# CSS – Mise en forme des pages web

## Introduction

Après avoir structuré le contenu avec **HTML**, il est nécessaire d’en améliorer la présentation visuelle. C’est le rôle de **CSS (Cascading Style Sheets)**. CSS permet de contrôler l’apparence des pages web tout en respectant la séparation entre **structure** (HTML) et **présentation** (CSS).

---

## Chapitre 1 : Rôle et principes de CSS

### 1.1 Pourquoi utiliser CSS ?

Sans CSS, une page HTML est affichée avec le **style par défaut du navigateur** :
- lisible mais rudimentaire
- peu agréable visuellement

CSS permet de :
- définir les couleurs, polices, espacements
- organiser la mise en page
- adapter l’affichage aux différents écrans

### 1.2 Compatibilité des navigateurs

Le rendu d’une page dépend du **moteur de rendu** du navigateur.

Conséquences :
- certaines propriétés peuvent être interprétées différemment
- le style par défaut varie d’un navigateur à l’autre

👉 Il est indispensable de **tester son site sur plusieurs navigateurs**.

---

## Chapitre 2 : Où écrire le code CSS ?

### 2.1 Fichier CSS externe (méthode recommandée)

```html
<link rel="stylesheet" href="style.css">
```

Avantages :
- séparation claire HTML / CSS
- réutilisation sur plusieurs pages
- maintenance facilitée

### 2.2 CSS dans la page HTML

```html
<style>
  /* règles CSS */
</style>
```

Utilisable pour des tests ou pages simples.

### 2.3 CSS en ligne (à éviter)

```html
<p style="color: white; background-color: black;">Texte</p>
```

Inconvénients :
- difficile à maintenir
- mélange structure et présentation

---

## Chapitre 3 : Syntaxe des règles CSS

### 3.1 Structure d’une règle

```css
selecteur {
  propriete: valeur;
}
```

Une feuille CSS contient **plusieurs règles**.

### 3.2 Commentaires

```css
/* Ceci est un commentaire */
```

---

## Chapitre 4 : Sélecteurs CSS

### 4.1 Sélecteurs de base

- universel : `*`
- type : `p`, `h1`
- identifiant : `#id`
- classe : `.classe`

### 4.2 Combinaisons de sélecteurs

- union : `h1, h2`
- descendants : `article p`
- enfants directs : `body > p`
- voisins : `h2 ~ p`
- voisin immédiat : `h2 + p`

### 4.3 Sélecteurs par attribut

```css
input[required] { }
input[type="password"] { }
```

### 4.4 Classes CSS

```html
<p class="important">Texte</p>
```

```css
.important {
  color: red;
}
```

---

## Chapitre 5 : Pseudo-classes et pseudo-éléments

### 5.1 Pseudo-classes

Elles ciblent un **état particulier** d’un élément :

- `:hover`
- `:focus`
- `:visited`
- `:nth-child(n)`

Exemple :
```css
a:hover {
  color: pink;
}
```

### 5.2 Pseudo-éléments

Ils ciblent une **partie** d’un élément (`::before`, `::after`, etc.).

---

## Chapitre 6 : Mise en forme du texte

### 6.1 Propriétés de police

- `font-family`
- `font-size`
- `font-weight`
- `font-style`
- `font`

### 6.2 Alignement et espacement

- `text-align`
- `vertical-align`
- `line-height`
- `text-indent`

### 6.3 Couleurs

```css
color: red;
background-color: #ff0000;
background-color: rgb(255,0,0);
```

---

## Chapitre 7 : Le modèle de boîte (box model)

### 7.1 Composition d’une boîte

Chaque élément HTML est représenté par une **boîte** composée de :
- contenu
- padding (marge intérieure)
- border (bordure)
- margin (marge extérieure)

### 7.2 Propriétés associées

- `width`, `height`
- `padding`, `margin`
- `border-width`, `border-style`, `border-color`
- propriétés combinées : `border`, `margin-top`, etc.

### 7.3 Unités de taille

- pixels : `px`
- pourcentages : `%`
- relatives à la police : `em`

---

## Chapitre 8 : Positionnement des éléments

### 8.1 La propriété position

- `static` (par défaut)
- `relative`
- `absolute`
- `fixed`
- `sticky`

Les positions utilisent : `top`, `bottom`, `left`, `right`.

### 8.2 Flottants

```css
.left {
  float: left;
}
```

Technique historique, aujourd’hui remplacée par Flexbox.

---

## Chapitre 9 : Mise en page moderne

### 9.1 Flexbox

Flexbox permet d’organiser facilement des éléments en lignes ou colonnes.

```css
.parent {
  display: flex;
}
```

```css
.colonne {
  flex: 1;
}
```

### 9.2 Media queries (responsive design)

```css
@media (max-width: 800px) {
  .contenu {
    width: 100%;
  }
}
```

Elles adaptent l’affichage à la taille de l’écran.

---

## Chapitre 10 : Bonnes pratiques CSS

- utiliser un fichier CSS externe
- nommer les classes de façon explicite
- éviter le CSS en ligne
- tester sur plusieurs navigateurs
- utiliser les outils de développement
- valider son CSS avec le validateur W3C

---

## Synthèse du chapitre

CSS permet de :
- transformer une page HTML brute en page agréable
- contrôler précisément l’apparence
- adapter l’affichage aux différents supports

Il est indissociable de HTML dans le développement web moderne.

---

[[02_html_structuration_du_contenu]] | [[04_php_programmation_web_cote_serveur]]

