# PHP – Programmation web côté serveur

## Introduction

Jusqu’ici, nous avons travaillé sur la **partie visible** d’un site web (HTML et CSS). Nous abordons maintenant la **programmation côté serveur**, appelée **back-end**. Cette partie permet de générer des pages dynamiques, de traiter des formulaires et d’interagir avec des bases de données.

Le langage utilisé dans ce cours est **PHP**, l’un des langages serveur les plus répandus sur le web.h 

---

## Chapitre 1 : Le rôle du serveur web dynamique

### 1.1 Fonctionnement général

Un serveur web dynamique est capable de :
- écouter sur un **port TCP**
- recevoir et analyser des **requêtes HTTP**
- exécuter du **code serveur**
- générer une **réponse HTTP dynamique**

On distingue :
- le **serveur web dynamique** (logiciel)
- l’**application web** (code PHP exécuté)

### 1.2 Front-end / Back-end

- **Front-end** : HTML, CSS, JavaScript (navigateur)
- **Back-end** : PHP, base de données (serveur)

Un développeur **full-stack** maîtrise les deux.

---

## Chapitre 2 : Présentation du langage PHP

### 2.1 Définition

**PHP (Hypertext PreProcessor)** est un langage :
- côté serveur
- interprété
- impératif et orienté objet
- faiblement typé

Caractéristiques :
- fichiers `.php`
- multiplateforme
- version actuelle : PHP 8

### 2.2 Exécution du code PHP

Le serveur :
- repère les balises `<?php ... ?>`
- exécute le code
- remplace ces balises par le résultat généré

Le navigateur **ne voit jamais le code PHP**, seulement le HTML produit.

---

## Chapitre 3 : Premier script PHP

### 3.1 Hello World

```php
<?php
echo "Hello world";
?>
```

- `<?php` : début du code PHP
- `echo` : affiche du texte
- `;` : fin d’instruction

### 3.2 PHP au milieu du HTML

```php
<p>
  <?php echo "Bonjour"; ?>
</p>
```

PHP permet de **générer dynamiquement** du contenu HTML.

---

## Chapitre 4 : Inclusion et factorisation du code

### 4.1 Inclusion de fichiers

```php
<?php include("header.php"); ?>
```

Utilisation courante :
- en-tête commun
- pied de page commun

Avantages :
- évite les duplications
- facilite la maintenance

---

## Chapitre 5 : Syntaxe de base de PHP

### 5.1 Variables et types

- les variables commencent par `$`

```php
$age = 24;
$temperature = 15.3;
$texte = "Bonjour";
$valeur = null;
```

### 5.2 Opérations et concaténation

```php
$nom_complet = $prenom . " " . $nom;
```

L’opérateur `.` sert à **concaténer** des chaînes.

---

## Chapitre 6 : Conditions et boucles

### 6.1 Conditions

```php
if ($a == $b) {
  echo "égal";
} else {
  echo "différent";
}
```

Opérateurs :
- comparaison : `==`, `!=`, `<`, `>`
- logique : `&&`, `||`, `!`

### 6.2 Boucles

```php
for ($i = 0; $i < 10; $i++) {
  echo $i;
}
```

Boucles disponibles :
- `for`
- `while`
- `do...while`

---

## Chapitre 7 : Tableaux

### 7.1 Tableaux indexés

```php
$tab = ["a", "b", "c"];
```

Parcours :
```php
foreach ($tab as $valeur) {
  echo $valeur;
}
```

### 7.2 Tableaux associatifs

```php
$cours = [
  "it103" => "Web",
  "pg109" => "C"
];
```

---

## Chapitre 8 : Fonctions

```php
function addition($a, $b) {
  return $a + $b;
}
```

Les fonctions permettent de **structurer** le code.

---

## Chapitre 9 : Paramètres GET et POST

### 9.1 Paramètres GET

URL :
```
fichier.php?param=valeur
```

Récupération :
```php
$_GET["param"]
```

### 9.2 Paramètres POST

Récupération :
```php
$_POST["champ"]
```

👉 Toutes les valeurs sont des **chaînes de caractères**.

---

## Chapitre 10 : Sécurité et validation

### 10.1 Ne jamais faire confiance à l’utilisateur

Toujours vérifier :
- présence des paramètres
- type des données
- droits de l’utilisateur

### 10.2 Faille XSS

Les données utilisateur peuvent contenir du **code HTML ou JavaScript**.

Protection :
```php
htmlentities($texte)
```

---

## Chapitre 11 : Cookies et sessions

### 11.1 Cookies

- stockés côté client
- aucune confiance

```php
setcookie("pseudo", "toto", time()+3600);
```

### 11.2 Sessions

- stockées côté serveur

```php
session_start();
$_SESSION["pseudo"] = "toto";
```

---

## Synthèse du chapitre

PHP permet de :
- générer des pages dynamiques
- traiter des formulaires
- gérer l’état utilisateur
- sécuriser les entrées

Il constitue le **cœur du back-end** dans ce cours.

---

[[03_css_mise_en_forme_des_pages_web]] | [[05_bases_de_donnees_relationnelles_et_sql]]

