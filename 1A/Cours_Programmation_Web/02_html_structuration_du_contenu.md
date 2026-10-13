# HTML – Structuration du contenu des pages web

## Introduction

Après avoir compris **comment fonctionne un site Internet**, nous abordons maintenant le premier langage fondamental du web : **HTML**.

HTML permet de **structurer le contenu** d’une page web. Il ne sert ni à programmer une logique, ni à définir l’apparence visuelle, mais à donner du **sens** au contenu affiché par le navigateur.

---

## Chapitre 1 : Le langage HTML

### 1.1 Définition

**HTML (HyperText Markup Language)** est un langage de **description** :
- il décrit la structure d’un document
- il indique au navigateur *quoi afficher*, pas *comment l’afficher*

Caractéristiques principales :
- fichiers avec l’extension **`.html`**
- langage inventé en **1989**
- version actuelle : **HTML5** (finalisée en 2014)

### 1.2 Rôle du navigateur

Le navigateur :
- reçoit le code HTML depuis le serveur
- le **convertit en document structuré**
- applique un style minimal par défaut

👉 Le rendu visuel par défaut est volontairement sobre.

---

## Chapitre 2 : Structure de base d’une page HTML

### 2.1 Squelette minimal

Toute page HTML5 repose sur une structure commune :

```html
<!DOCTYPE html>
<html lang="fr">
  <head>
    <meta charset="utf-8">
    <title>Titre de la page</title>
  </head>
  <body>
  </body>
</html>
```

### 2.2 Rôle des principales balises

- **`<!DOCTYPE html>`** : indique l’utilisation de HTML5
- **`<html>`** : racine du document
- **`<head>`** : métadonnées (non affichées)
- **`<title>`** : titre de l’onglet du navigateur
- **`<meta charset="utf-8">`** : encodage des caractères
- **`<body>`** : contenu affiché

---

## Chapitre 3 : Balises, attributs et vocabulaire

### 3.1 Anatomie d’une balise

Exemple :
```html
<a href="https://example.com">Lien</a>
```

- **balise ouvrante** : `<a>`
- **balise fermante** : `</a>`
- **attribut** : `href="..."`
- **contenu** : `Lien`

### 3.2 Règles d’écriture essentielles

- toute balise ouvrante doit être fermée
- certaines balises sont **void elements** (pas de fermeture) :
  - `<br>`, `<img>`, `<input>`, `<meta>`, `<link>`
- les balises imbriquées doivent être fermées dans l’ordre inverse

Exemple incorrect :
```html
<a><b>texte</a></b>
```

Exemple correct :
```html
<a><b>texte</b></a>
```

---

## Chapitre 4 : HTML, XML et commentaires

### 4.1 Parenté avec XML

HTML est **proche du XML** :
- structure en arbre
- balises imbriquées
- attributs clé/valeur

Cependant, HTML est **plus permissif** que XML.

### 4.2 Commentaires

```html
<!-- Ceci est un commentaire -->
```

### 4.3 Caractères spéciaux

Certains caractères doivent être échappés :
- `<` → `&lt;`
- `>` → `&gt;`
- `&` → `&amp;`
- espace insécable → `&nbsp;`

---

## Chapitre 5 : Types d’éléments HTML

### 5.1 Éléments de type bloc

Caractéristiques :
- occupent toute la largeur disponible
- s’affichent les uns **sous** les autres
- peuvent contenir blocs et inline

Exemples :
- `<p>`, `<div>`, `<section>`, `<article>`, `<header>`, `<footer>`

### 5.2 Éléments en ligne (inline)

Caractéristiques :
- s’insèrent dans le flux du texte
- ne provoquent pas de retour à la ligne
- dimensions non imposables

Exemples :
- `<a>`, `<strong>`, `<em>`, `<span>`

---

## Chapitre 6 : Structuration sémantique du contenu

### 6.1 Balises sémantiques principales

- **`<header>`** : en-tête
- **`<footer>`** : pied de page
- **`<nav>`** : navigation
- **`<section>`** : section thématique
- **`<article>`** : contenu autonome
- **`<aside>`** : contenu secondaire

👉 Ces balises donnent du **sens** au contenu.

### 6.2 Titres

Les balises de titres :
- `<h1>` à `<h6>`

Règles importantes :
- un seul `<h1>` par page (en général)
- hiérarchie logique (pas de saut brutal)

---

## Chapitre 7 : Liens, ancres et navigation

### 7.1 Liens hypertextes

```html
<a href="page.html">Lien</a>
```

Les URLs peuvent être :
- absolues
- relatives

### 7.2 Ancres

Un élément peut être ciblé par un **id** :

```html
<h2 id="conclusion">Conclusion</h2>
```

Lien vers l’ancre :
```html
<a href="#conclusion">Aller à la conclusion</a>
```

---

## Chapitre 8 : Images

### 8.1 Insertion d’une image

```html
<img src="panda.png" alt="Panda mangeant du bambou">
```

- `src` : adresse de l’image
- `alt` : description **obligatoire** (accessibilité)

### 8.2 Image avec légende

```html
<figure>
  <img src="panda.png" alt="Panda mangeant du bambou">
  <figcaption>Légende de l’image</figcaption>
</figure>
```

---

## Chapitre 9 : Formulaires

### 9.1 Principe général

Les formulaires permettent à l’utilisateur d’envoyer des données au serveur.

```html
<form method="post" action="traitement.php">
</form>
```

### 9.2 Champs courants

- `<input type="text">`
- `<input type="password">`
- `<textarea>`
- `<input type="radio">`
- `<input type="checkbox">`
- `<select>` / `<option>`

### 9.3 Accessibilité des formulaires

```html
<label for="login">Login</label>
<input id="login" name="login">
```

Avantages :
- meilleure ergonomie
- accessibilité améliorée

---

## Chapitre 10 : Bonnes pratiques HTML

- respecter la **sémantique** des balises
- séparer structure (HTML) et présentation (CSS)
- valider son code avec le **validateur W3C**
- tester sur plusieurs navigateurs

---

## Synthèse du chapitre

HTML permet de :
- structurer le contenu d’une page
- donner du sens aux informations
- faciliter l’accessibilité et le référencement

Il constitue la **base incontournable** de toute page web.

---

[[01_fonctionnement_site_internet]] | [[03_css_mise_en_forme_des_pages_web]]

