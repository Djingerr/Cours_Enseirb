# JavaScript – Pages dynamiques côté client

## Introduction

Jusqu’à présent, le dynamisme des pages web provenait du **serveur** (PHP). Avec **JavaScript**, nous introduisons le **dynamisme côté client** : le code est exécuté directement par le **navigateur**, après le chargement de la page.

JavaScript permet de rendre les pages **interactives**, de modifier le contenu affiché sans recharger la page et d’améliorer fortement l’expérience utilisateur.

---

## Chapitre 1 : Rôle de JavaScript dans le web

### 1.1 Exécution côté client

JavaScript est un langage :
- interprété par le navigateur
- exécuté **après** la réception de la page HTML
- capable d’interagir avec le contenu affiché

Contrairement à PHP :
- JavaScript est visible côté client
- il ne doit jamais contenir de logique sensible

### 1.2 Exemples d’usages

JavaScript permet notamment :
- de réagir aux actions de l’utilisateur
- de modifier le contenu HTML dynamiquement
- de valider des formulaires côté client
- de créer des animations

---

## Chapitre 2 : Intégration de JavaScript dans une page web

### 2.1 Script intégré

```html
<script>
  alert("Bonjour !");
</script>
```

### 2.2 Script externe (recommandé)

```html
<script src="script.js"></script>
```

Avantages :
- séparation du code
- réutilisation
- maintenance facilitée

### 2.3 Emplacement du script

- dans `<head>` (avec précautions)
- en fin de `<body>` (souvent recommandé)

---

## Chapitre 3 : Bases du langage JavaScript

### 3.1 Variables

```js
let age = 25;
const nom = "Alice";
```

- `let` : variable modifiable
- `const` : constante

### 3.2 Types de données

- nombres
- chaînes de caractères
- booléens
- tableaux
- objets

### 3.3 Conditions

```js
if (age >= 18) {
  console.log("Majeur");
}
```

### 3.4 Boucles

```js
for (let i = 0; i < 5; i++) {
  console.log(i);
}
```

---

## Chapitre 4 : Interaction avec le document HTML (DOM)

### 4.1 Le DOM

Le **DOM (Document Object Model)** est la représentation en mémoire de la page HTML.

JavaScript peut :
- accéder aux éléments
- les modifier
- en créer ou en supprimer

### 4.2 Sélection d’éléments

```js
document.getElementById("titre");
document.querySelector("p");
```

### 4.3 Modification du contenu

```js
element.textContent = "Nouveau texte";
element.style.color = "red";
```

---

## Chapitre 5 : Gestion des événements

### 5.1 Principe

Un **événement** est une action détectée par le navigateur :
- clic
- survol
- saisie clavier

### 5.2 Exemple

```js
button.addEventListener("click", function () {
  alert("Bouton cliqué");
});
```

JavaScript permet de **réagir dynamiquement** aux actions de l’utilisateur.

---

## Chapitre 6 : Validation des formulaires côté client

### 6.1 Objectif

La validation JavaScript permet :
- de guider l’utilisateur
- de détecter des erreurs simples
- d’éviter des allers-retours inutiles avec le serveur

⚠️ Elle **ne remplace jamais** la validation côté serveur.

### 6.2 Exemple simple

```js
if (champ.value === "") {
  alert("Champ obligatoire");
}
```

---

## Chapitre 7 : Communication asynchrone

### 7.1 Principe général

JavaScript peut communiquer avec un serveur **sans recharger la page**.

C’est le principe des pages dites **dynamiques côté client**.

### 7.2 Exemple d’usage

- chargement dynamique de données
- mise à jour partielle de la page
- applications web modernes

---

## Chapitre 8 : Limites et bonnes pratiques

### 8.1 Sécurité

- ne jamais faire confiance au JavaScript côté client
- toute vérification doit être répétée côté serveur

### 8.2 Bonnes pratiques

- séparer JavaScript, HTML et CSS
- nommer clairement les variables
- éviter le code complexe inutile
- utiliser les outils de développement du navigateur

---

## Synthèse du chapitre

JavaScript permet :
- d’ajouter de l’interactivité
- de modifier dynamiquement le contenu
- d’améliorer l’expérience utilisateur

Il complète HTML, CSS et PHP pour former une **application web moderne**.

---

[[05_bases_de_donnees_relationnelles_et_sql]] | [[07_conclusion_et_synthese_generale]]

