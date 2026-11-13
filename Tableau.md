# Contraintes sur l'émetteur ADS-B (DF17)

Source de référence : OACI, Annexe 10, Volume IV (5e éd., 2014), chapitre 3, section 3.1.2 (Mode S). Le signal ADS-B est une **réponse Mode S, downlink (air → sol)**.

## 1. Paramètres extraits

| #   | Paramètre                                | Valeur                                                                         | Tolérance                          | Section Annexe IV                                                                                              |
| --- | ---------------------------------------- | ------------------------------------------------------------------------------ | ---------------------------------- | -------------------------------------------------------------------------------------------------------------- |
| 1   | Durée d'un bit $T_b$                     | 1 µs                                                                           | —                                  | 3.1.2.2.5.1.2                                                                                                  |
| 2   | Débit $D_b = 1/T_b$                      | 1 Mbit/s                                                                       | —                                  | 3.1.2.2.4 (recoupé avec 3.1.2.2.5.1.2)                                                                         |
| 3   | Nombre de bits d'une trame DF17          | 112 (= DF 5 + CA 3 + AA 24 + ME 56 + PI 24)                                    | —                                  | 3.1.2.2.5, 3.1.2.3.1.2, Figure 3-8 (ligne 17 « Extended squitter »), 3.1.2.8.6.1 (« 112-bit downlink format ») |
| 4   | Fréquence porteuse                       | 1 090 MHz                                                                      | ± 1 MHz                            | 3.1.2.2.1                                                                                                      |
| 5   | Codage d'un « 1 »                        | impulsion de 0,5 µs dans la **1re moitié** de l'intervalle bit (de 0 à 0,5 µs) | ± 0,05 µs sur la position          | 3.1.2.3.1.2                                                                                                    |
| 6   | Codage d'un « 0 »                        | impulsion de 0,5 µs dans la **2e moitié** de l'intervalle bit (de 0,5 à 1 µs)  | ± 0,05 µs sur la position          | 3.1.2.3.1.2                                                                                                    |
| 7   | Durée d'une impulsion de données         | 0,5 µs (= $T_b$/2)                                                             | ± 0,05 µs (Table 3-2)              | 3.1.2.2.5.1.2 + Table 3-2                                                                                      |
| 8   | Impulsions adjacentes (« 0 » puis « 1 ») | fusion en une impulsion de 1 µs                                                | ± 0,05 µs sur la durée (Table 3-2) | 3.1.2.2.5.1.2                                                                                                  |
| 9   | Début du bloc de données                 | 8 µs après le front montant de la 1re impulsion                                | ± 0,05 µs                          | 3.1.2.2.5.1.2 (+ 3.1.2.2.5.1 pour la tolérance)                                                                |

## 2. Paramètres complémentaires (rubriques de la fiche)

|Paramètre|Valeur|Où (section / page)|
|---|---|---|
|Durée du bloc de données DF17|112 × 1 µs = **112 µs** (cohérent avec la Figure 3-6 : « 56 or 112 µs »)|déduite de #1 et #3 ; Figure 3-6 (p. 3-90)|
|Polarisation|**Verticale** (« nominally vertical »)|3.1.2.2.3 (p. 3-12)|
|Gabarit de spectre|Atténuation minimale par rapport à la porteuse : **0 dB** jusqu'à ±1,3 MHz ; **−3 dB** entre ±1,3 et ±7 MHz ; **−20 dB** entre ±7 et ±23 MHz ; **−40 dB** entre ±23 et ±78 MHz ; **−60 dB** au-delà de ±78 MHz. Le gabarit suit la porteuse dans sa tolérance de ±1 MHz.|3.1.2.2.2 → Figure 3-5 (p. 3-89)|
|Forme des impulsions (montée / descente)|Impulsion de 0,5 µs (± 0,05) et de 1,0 µs (± 0,05) : temps de montée **0,05 à 0,1 µs**, temps de descente **0,05 à 0,2 µs**. Définitions : montée = 10 % → 90 % de A, descente = 90 % → 10 % de A, durée mesurée entre les points à 50 % de A.|3.1.2.2.4.1 → Table 3-2 ; définitions dans les pages de figures/tables du chap. 3|
|Préambule : nb d'impulsions, durée, positions|**4 impulsions** de **0,5 µs**, fronts montants à **0 ; 1,0 ; 3,5 ; 4,5 µs** de la 1re impulsion. Durée totale du préambule : **8 µs** (la dernière impulsion finit à 5 µs, puis silence jusqu'à 8 µs).|3.1.2.2.5.1.1 + Figure 3-6|
|Tolérance sur les positions d'impulsions|Chaque impulsion démarre à un multiple de 0,5 µs après la 1re impulsion, à **± 0,05 µs** près|3.1.2.2.5.1|
|Variation d'amplitude entre impulsions|**≤ 2 dB** entre deux impulsions quelconques d'une même réponse|3.1.2.2.5.2|
|Durée totale d'une trame (préambule + données)|8 + 112 = **120 µs**|déduite|
|Ordre des bits (MSB en premier ?)|**Oui, MSB en premier.** Les bits sont numérotés dans l'ordre d'émission à partir du bit 1, et les champs sont codés en binaire naturel.|3.1.2.3.1.3|
|Champs de la trame DF17|**DF** bits 1–5 (= 10001₂ = 17) · **CA** bits 6–8 (capability) · **AA** bits 9–32 (adresse OACI 24 bits) · **ME** bits 33–88 (message ADS-B, 56 bits) · **PI** bits 89–112 (parité / identifiant interrogateur, 24 bits)|Figure 3-8 (p. 3-92), 3.1.2.3.2.1, 3.1.2.8.6 / 3.1.2.8.6.1 (p. 3-56)|
|Parité : nb de bits, polynôme, position|**24 bits** sur les bits **89–112**, calculés sur les k = **88** premiers bits. Polynôme : $G(x) = 1 + x^3 + x^{10} + x^{12} + x^{13} + \dots + x^{24}$ (tous les termes de $x^{12}$ à $x^{24}$), soit **0x1FFF409**. $R(x)$ est le reste de $x^{24}M(x)$ divisé par $G(x)$, et $p_i$ est le coefficient de $x^{24-i}$. Bit émis : $t_{88+i} = a_i \oplus p_i$. Pour le DF17, les codes II et SI valent 0, donc la séquence $a$ du PI est entièrement nulle : **PI = CRC pur**.|3.1.2.3.3.1.1, 3.1.2.3.3.1.2, 3.1.2.3.3.2.2 ; 3.1.2.3.2.1.4 et 3.1.2.8.6.1 (« II equal to 0 »)|

## 3. Sections hors périmètre (ne s'appliquent PAS au signal ADS-B)

|Section|Pourquoi l'exclure|
|---|---|
|3.1.1.x|Systèmes Mode A/C uniquement, pas Mode S|
|3.1.2.1.x|**Interrogations** Mode S : uplink (sol → air), émises par le radar sol|
|3.1.2.3.1.1|Codage des données d'**interrogation** (inversion de phase DPSK), uplink|
|3.1.2.3.3.2.1|Ordre d'émission de l'AP en **uplink** (séquence $b_i$ modifiée)|
|3.1.2.10.x|Récepteur du **transpondeur** (à bord), pas notre récepteur sol|

## 4. Hypothèses de modélisation

- Impulsions rectangulaires idéales (la norme impose des temps de montée et de descente, Table 3-2 : montée de 0,05 à 0,1 µs, descente de 0,05 à 0,2 µs).
- Signal en bande de base (porteuse retirée par le récepteur SDR).
- Amplitude constante sur toute la trame (la norme tolère jusqu'à 2 dB d'écart).

## 5. Remarques

- Le contenu détaillé du champ ME (registres 05, 06, 08, 09, etc.) n'est pas dans l'Annexe 10 : il est défini dans le Doc 9871 de l'OACI (Technical Provisions for Mode S Services and Extended Squitter).