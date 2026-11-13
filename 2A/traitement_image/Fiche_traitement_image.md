---
tags: [cours, traitement-image, TSIG3, antiseche]
source: "[[Slides_EI_TSIG3.pdf]]"
prof: R. Giraud (ENSEIRB-MATMECA 2026-2027)
---

# Antisèche : Traitement d'images (TSIG3)

> [!info] Évaluation
> TP (contrôle continu + TP final) ×0.33 · Rapport projet ×0.34 · Soutenance ×0.33

---

## 1. Image numérique

- Image = **signal 2D discret** = matrice `h × w (× c)` ; chaque case = **pixel**, intensité usuelle `[0, 255]` (`uint8`).
- **Synthétique** (calculée) vs **naturelle** (photo, discrétisation du réel).
- `c = 3` → **vraies couleurs** RGB (synthèse **additive**, cube RGB).
- `c = 1` → **couleurs indexées / fausses couleurs** : on choisit une **palette** (colormap = table intensité → triplet RGB). Gris = triplication du canal : (L, L, L).
- Luminance simple : $L = \frac{R+G+B}{3}$ → `np.mean(img, axis=2)`

> [!warning] Convention Python
> `img[ligne, colonne, canal]` = `img[y, x, c]`, indices à partir de **0**, `range(0,n)` → 0…n-1, `tab[-1]` = dernier.

### Lire / afficher
```python
img = plt.imread('img.jpg')        # .jpg/.png/.tif ; np.load('x.npy') pour les .npy
h, w, c = img.shape                # whos dans la console : taille + type
plt.imshow(I, cmap='gray')         # palettes : 'gray', 'hot', 'jet'...
plt.imshow(I, vmin=0, vmax=255)    # bornes fixées (comparaison/fidélité)
plt.colorbar()                     # gamme d'intensités (image 1 canal)
```
- **Contexte informationnel** : ajustement auto `(min, max)` de la palette (défaut de `imshow`).
- **Contexte comparaison/fidélité** : mêmes `vmin/vmax` pour toutes les images.
- Pièges classiques : mauvais **type** (`float` hors [0,1] / `uint8` qui déborde), mauvais **intervalle**, mauvaise **palette** (données discrètes).

---

## 2. Histogramme

Distribution des intensités (nb de pixels par intensité) → `np.histogram(I)`.

> [!caution] Précautions
> - Choisir un **nombre d'intervalles** pertinent (petits = peu représentatifs ; gros = perte de détail).
> - **Aucune info spatiale** : 2 images différentes peuvent avoir le même histogramme.
> - Couleur : un histogramme **par canal**.

| Histogramme | Image |
|---|---|
| Tassé vers 0 | sombre |
| Tassé vers 255 | claire |
| Valeurs tassées | contraste faible |
| Valeurs réparties | contraste fort |

**Transformations :**
- Translation : $I_s = I_e + 50$ · Négatif : $I_s = I_{max} + I_{min} - I_e$
- **Étirement / normalisation** (ce que fait `imshow`) : $I'(i,j) = \frac{255}{\max-\min}\,(I(i,j)-\min)$
  - Limite : inefficace si quelques pixels sont déjà à 0 et 255.
- **Égalisation** (`skimage.exposure.equalize_hist`) : étale uniformément
  $$H_n(k)=\frac{H(k)}{MN},\quad H_{cn}(k)=\sum_{l=0}^{k}H_n(l),\quad \boxed{k' = I_{max}\,H_{cn}(k)}$$

---

## 3. Espaces couleurs

| Espace | Usage |
|---|---|
| **RGB** | acquisition / écran ; canaux très corrélés, non perceptuel |
| **HSV / HSL** | Teinte-Saturation-Valeur, intuitif, graphisme |
| **YUV / YCbCr** | transmission, compression |
| **L\*a\*b\* / L\*u\*v\*** | uniforme (distance entre couleurs) |
| **CMY** | impression |
| **XYZ** | modélisation |

**Luminance perceptuelle** (l'œil est plus sensible au vert, moins au bleu) :
$$Y = 0.299R + 0.587G + 0.114B$$
$$C_b = 0.564\,(B-Y)+128 \qquad C_r = 0.713\,(R-Y)+128$$
- $C_b$ = contraste **bleu/jaune**, $C_r$ = contraste **rouge/cyan**.
- `skimage.color.rgb2ycbcr(img)` / `ycbcr2rgb(...)` (passer en `double` avant les calculs).

> [!example] Applications
> - **Compression** : réduire la taille de **Cb, Cr seulement** (`skimage.transform.resize`, facteur r<1), l'œil voit peu la différence (Y intact).
> - **Incrustation (chroma-key)** : RGB → YCbCr → **seuillage** sur la chrominance → fusion.
> - **Pencil sketch** : contours C (`skimage.feature.canny`), puis $Y \leftarrow (255-\alpha)(1-C)+\beta$, retour RGB.
> - **Illusion** : inverser la chrominance ($C_b = 255-C_b$, $C_r = 255-C_r$), fixer un point puis afficher l'image en gris → couleurs perçues.

---

## 4. Filtrage linéaire (convolution)

$$I_s = I_e * H \qquad g(n)=\sum_{k=-K}^{K} f(n-k)\,h(k)$$
$$I_s(i,j)=\sum_{k=-K}^{K}\sum_{l=-L}^{L} I_e(i-k,\,j-l)\,H(k,l)$$
Filtre **RIF** de taille $(2K+1)\times(2L+1)$, centré sur le pixel ; la convolution **retourne** le filtre (miroir) puis le fait glisser.

- **Effets de bord** : zero-padding, extension, miroir, périodique ; taille de sortie `mode='same'|'full'|'valid'`.
- **Couleur** : même filtre sur chaque canal indépendamment.

### Filtres moyenneurs (passe-bas → flou, débruitage)
- **Rectangle** $R_{2K+1} = \frac{1}{2K+1}[1\ \dots\ 1]$, 2D : $R_{2K+1,2L+1}=R_{2K+1}*R_{2L+1}^T$ (ex. 3×3 : tous à 1/9). $R_{11,1}$ = flou vertical, $R_{1,11}$ = horizontal.
- **Triangle** : $T_3 = \frac14[1\ 2\ 1]$, $T_{3,3}=\frac1{16}\begin{bmatrix}1&2&1\\2&4&2\\1&2&1\end{bmatrix}$
- **Gaussien** (pondère selon la distance au centre, flou isotrope) :
  $$H(x,y)=\frac{1}{2\pi\sigma_x\sigma_y}\exp\left(-\left(\frac{x^2}{2\sigma_x^2}+\frac{y^2}{2\sigma_y^2}\right)\right)$$
  $\sigma$ grand = filtrage fort ; support ≈ $\pm 3\sigma$ (sinon gaussienne tronquée).

> [!tip] Normaliser un filtre moyenneur
> Somme des coefficients = 1, sinon la luminosité change : `H = H / H.sum()`.

```python
from scipy import signal
H = np.ones((5,5))/25
Is = signal.convolve2d(I, H, mode='same')
X, Y = np.meshgrid(range(-K,K+1), range(-K,K+1))      # pour construire un gaussien
G = np.exp(-(X**2+Y**2)/(2*s**2)); G /= G.sum()
signal.convolve(img, np.ones([7,7,1])/49, mode='same')   # image couleur
```

---

## 5. Filtrage non linéaire

| Bruit | Bon filtre |
|---|---|
| **Gaussien additif** (AWGN) | moyenneur / gaussien |
| **Poivre & sel** (impulsionnel) | **médian** (le moyenneur l'étale) |
| **Fréquentiel / périodique** | **coupe-bande** dans Fourier |

- **Médian** : médiane du voisinage $(2v+1)^2$ → `scipy.ndimage.median_filter(I, size=3)` ; préserve mieux les contours.
- **Bilatéral** (Tomasi & Manduchi) : moyenne pondérée par proximité **spatiale ET d'intensité** → lisse sans flouter les contours.
  $$I_F(p)=\frac{\sum_{p'\in V(p)}\omega(p,p')I(p')}{\sum_{p'\in V(p)}\omega(p,p')},\quad \omega=\exp\left(-\frac{\|I(p)-I(p')\|_2}{2\sigma_c^2}-\frac{(p-p')^2}{2\sigma_s^2}\right)$$
- **Anonymisation** : flouter toute l'image, puis combiner avec un **masque binaire** autour des visages : `Is = I*(1-M) + I_floue*M`.

---

## 6. Morphologie mathématique (images binaires)

Objet = 1 (blanc), fond = 0. Principe : **convolution par un élément structurant puis seuillage**.

| Opérateur | Règle | Effet |
|---|---|---|
| **Érosion** | objet si *tout* le voisinage est objet (seuil = somme max) | rétrécit, supprime les petits points |
| **Dilatation** | objet si *au moins un* voisin est objet (seuil > 0) | épaissit, bouche les trous |
| **Ouverture** | érosion **puis** dilatation | supprime les petites structures, **déconnecte** les objets |
| **Fermeture** | dilatation **puis** érosion | comble les trous, **recolle** les composantes |

> [!tip] Moyen mnémo
> **O**uverture = **É**rosion d'abord (« on ouvre en grattant »). Les étapes peuvent être itérées (×n puis ×n).

- **Composantes connexes** : pixels reliés (voisinage 4 ou 8). Étiquetage : `skimage.measure.label(B)`.

---

## 7. Transformée de Fourier 2D

- Centre du spectre = **basses fréquences** (zones uniformes), bords = **hautes fréquences** (détails, contours, bruit).
- Direction : un contour/texture orienté dans l'image → **ligne perpendiculaire** dans le spectre ; motif périodique → pics.

```python
F = np.fft.fftshift(np.fft.fft2(I))          # spectre centré en 0
plt.imshow(np.log10(np.abs(F)), extent=[-0.5,0.5,0.5,-0.5])   # log du module
plt.xlabel('Fx'); plt.ylabel('Fy')
Ir = np.real(np.fft.ifft2(np.fft.ifftshift(F)))   # retour spatial
```

- **Échantillonnage** = produit par un peigne de Dirac 2D $\text{Ш}_{T_e^x,T_e^y}$ → **spectre périodisé** (période $1/T_e$). Fréquences normalisées dans $[-0.5, 0.5]$.
- **Aliasing (repliement)** : si la fréquence d'échantillonnage < 2 × fréq. max (Shannon), les copies du spectre se chevauchent → moirés.
  - **Anti-aliasing** : **filtre passe-bas (gaussien) AVANT de sous-échantillonner** (`img[::4, ::4]`) ; `skimage.transform.resize` le fait.

> [!example] Applications
> Analyse de **textures** · **Compression (JPEG)** : mise à zéro des hautes fréquences · **Débruitage fréquentiel** : bruit périodique = pics hors centre → **filtre coupe-bande** (mettre ces pics à 0), un moyenneur n'y arrive pas.

---

## 8. Détection de contours

Contour = frontière entre régions = variation rapide d'intensité (nets, bruités, flous ; parfois ouverts/discontinus).

### Sobel (dérivée + lissage orthogonal)
$$S_x = \begin{bmatrix}1\\2\\1\end{bmatrix} * \begin{bmatrix}1 & 0 & -1\end{bmatrix} = \begin{bmatrix}1&0&-1\\2&0&-2\\1&0&-1\end{bmatrix},\qquad S_y = S_x^T$$
Pipeline : $G_x = I*S_x$, $G_y = I*S_y$ → **norme** $\sqrt{G_x^2+G_y^2}$ → normaliser dans [0,1] → **seuiller** (ex. 0.25) → carte binaire.

### Canny (dérivées de gaussienne)
$$G_x(x,y) = -\frac{x}{2\pi\sigma_x^3\sigma_y}\,e^{-\left(\frac{x^2}{2\sigma_x^2}+\frac{y^2}{2\sigma_y^2}\right)}\quad(\text{idem en } y)$$
Lisse **et** dérive en même temps. $\sigma$ petit = beaucoup de détails (sur-détection) ; $\sigma$ grand = contours principaux (sous-détection).
```python
X, Y = np.meshgrid(range(-10,11), range(-10,11)); sig = 1
Gx = -X/(2*np.pi*sig**4)*np.exp(-(X**2+Y**2)/(2*sig**2))   # Gy : remplacer -X par -Y
C = skimage.feature.canny(I)                                  # version toute faite
```

### Laplacien (dérivée seconde) & rehaussement
$$\Delta I = I_{xx}+I_{yy},\quad [1\ {-2}\ 1]$$
$$\text{croix}\begin{bmatrix}0&1&0\\1&-4&1\\0&1&0\end{bmatrix}\quad \text{diag}\begin{bmatrix}1&0&1\\0&-4&0\\1&0&1\end{bmatrix}\quad \text{isotrope } \tfrac12\begin{bmatrix}1&1&1\\1&-8&1\\1&1&1\end{bmatrix}$$
**Rehaussement de contraste** (« netteté ») : $\boxed{I_s = I - \beta\,\Delta I}$ ($\beta$ ≈ 1 moyen, 5 fort).
> [!warning] Risque : valeurs **hors [0, 255]** → `np.clip(Is, 0, 255)` avant de repasser en `uint8`.

---

## 9. Transformations spatiales (annexe)

- Rotation $R=\begin{bmatrix}\cos\theta & -\sin\theta\\ \sin\theta & \cos\theta\end{bmatrix}$, translation, similarité : $p_2 = f(p_1)$.
- Pas de bijection entre grilles → appliquer la **transformation inverse** : pour chaque pixel d'arrivée, chercher sa position dans l'image de départ.
- **Interpolation** : **plus proche voisin** (rapide, crénelé) ou **bilinéaire** (moyenne pondérée des 4 voisins, plus lisse).

---

## 10. Mémo Python

```python
import numpy as np, matplotlib.pyplot as plt, skimage
from scipy import signal

G = img[:,:,1]                         # canal vert
I = img.astype('double')               # avant tout calcul ! (uint8 déborde)
I8 = np.uint8(np.clip(I, 0, 255))      # retour en uint8
img[::4, ::4]                          # sous-échantillonnage ×4
mask = G > 100                         # seuillage → carte binaire
G[mask == 0] = 0   # ou  G = G*mask
a*a; np.dot(a, b)                      # terme à terme ; produit matriciel
np.stack((R,G,B), axis=2)              # recomposer une image couleur
X, Y = np.meshgrid(range(w), range(h)) # coordonnées sans boucles
R = np.sqrt(X**2 + Y**2)               # ex. disque : (R < r)
plt.subplot(121); plt.plot(I[0,:])     # profil d'une ligne
plt.ginput(2)                          # récupérer 2 clics
```
Autres : `np.squeeze`, `np.tile`, `np.mod`, `img.ravel()`, `cv2.VideoWriter` (vidéo).
