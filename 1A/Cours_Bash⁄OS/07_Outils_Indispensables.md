# Outils indispensables
[[06_Flux]] ← → [[08_Processus]]

---

## Introduction

Les **outils de manipulation de fichiers et de texte** sont au cœur de l’utilisation quotidienne d’un système UNIX/Linux.  
Ce chapitre regroupe les commandes essentielles pour :
- identifier la **nature** d’un fichier,  
- consulter et transformer des **fichiers texte**,  
- mesurer l’**occupation du disque**,  
- **archiver** ou **rechercher** des fichiers.

---

## Chapitre 1 — Identifier la nature d’un fichier

### 1.1 Commande `file`

Détermine le type d’un fichier : texte, image, exécutable, archive, etc.

```bash
file *
```

Exemple de sortie :
```
TP3             directory
tp3.html        exported SGML document, UTF-8 Unicode text
cm3.pdf         PDF document, version 1.5
Notes.txt       ASCII text
Pedagogie.txt   UTF-8 Unicode text
```

### 1.2 Tests de type avec `test` ou `[` `]`

| Test | Description |
|------|--------------|
| `-e fichier` | existe |
| `-f fichier` | fichier ordinaire |
| `-d fichier` | répertoire |
| `-L fichier` | lien symbolique |

Exemple :
```bash
if [ -d /home ]; then
    echo "C’est un dossier"
fi
```

---

## Chapitre 2 — Consultation de fichiers texte

| Commande | Fonction |
|-----------|-----------|
| `more fichier` | Affiche page par page |
| `less fichier` | Affiche page par page avec navigation |
| `head -n N fichier` | Affiche les N premières lignes |
| `tail -n N fichier` | Affiche les N dernières lignes |
| `cat fichier1 [fichier2 ...]` | Concatène les fichiers |
| `wc [-lwc] fichier` | Compte lignes (-l), mots (-w), caractères (-c) |

Exemples :
```bash
head -n 10 rapport.txt
wc -l notes.txt
```

---

## Chapitre 3 — Extraction et transformation de texte

### 3.1 Extraire des caractères : `cut`

```bash
cut -c3-7 fic.txt      # caractères 3 à 7
cut -d' ' -f2,4 fic.txt # 2e et 4e mots (séparateur espace)
```

### 3.2 Transformer ou supprimer des caractères : `tr`

```bash
cat fic | tr 'a-z' 'A-Z'     # majuscules
cat fic | tr -d 'aeiouy'     # supprime les voyelles
cat fic | tr '
 ' 'ab'      # remplace retour ligne et espace
```

---

## Chapitre 4 — Trier et filtrer des fichiers texte

### 4.1 Commande `sort`

Trie les lignes d’un ou plusieurs fichiers.

| Option | Fonction |
|---------|-----------|
| `-n` | Tri numérique |
| `-k x[,y]` | Tri sur les champs x à y |
| `-t c` | Définit le séparateur de champs |
| `-r` | Tri inverse |

Exemples :
```bash
sort -n notes.txt
sort -t':' -k2,3 utilisateurs.txt
```

### 4.2 Commande `grep` : rechercher un motif

```bash
grep motif fichier
grep -r "main" src/     # recherche récursive
grep -v "Erreur" log.txt # inverse (exclut le motif)
```

**Rappels sur les expressions régulières simples :**

| Symbole | Signification |
|----------|----------------|
| `.` | n’importe quel caractère |
| `*` | 0 ou plusieurs répétitions |
| `+` | au moins une répétition |
| `?` | 0 ou une fois |
| `[abc]` | un caractère parmi a, b ou c |
| `[^abc]` | tout caractère sauf a, b, c |

---

## Chapitre 5 — Occupation disque

### 5.1 Commande `df`

Affiche l’état des partitions et leur espace libre.

```bash
df -h
```

### 5.2 Commande `ls -lh`

Affiche la taille des fichiers de manière lisible.

```bash
ls -lh /home
```

### 5.3 Commande `du`

Calcule l’occupation d’un répertoire (récursif par défaut).

```bash
du -h
du -h --max-depth=1    # équivalent de l’option -d0
```

---

## Chapitre 6 — Archivage et compression

### 6.1 Commande `tar`

Regroupe ou extrait un ensemble de fichiers dans une **archive**.

| Option | Fonction |
|---------|-----------|
| `-c` | créer une archive |
| `-x` | extraire une archive |
| `-v` | mode verbeux |
| `-z` | compression gzip |
| `-f` | nom de fichier à traiter |

Exemples :
```bash
tar -cvzf sauvegarde.tgz projet/
tar -xvzf sauvegarde.tgz
```

---

## Chapitre 7 — Recherche dans le système de fichiers

### 7.1 Commande `find`

Recherche récursive dans une arborescence.

| Option | Fonction |
|---------|-----------|
| `-name "motif"` | recherche par nom |
| `-type f/d/l` | fichier, dossier ou lien |
| `-size +1M` | taille supérieure à 1 Mo |
| `-print` | affiche le résultat |

Exemples :
```bash
find /usr -name "*.c" -print
find . -type f -size +100k
```

### 7.2 Commande `locate`

Recherche rapide à partir d’une base d’index mise à jour périodiquement.

```bash
locate config.conf
```

---

## Synthèse finale

Les commandes étudiées permettent d’effectuer la majorité des opérations de manipulation de fichiers sous Linux :  
- **identifier, consulter, filtrer et trier** les fichiers texte,  
- **mesurer l’espace disque**,  
- **archiver ou compresser** des répertoires,  
- **rechercher** efficacement des fichiers selon divers critères.

Elles constituent une boîte à outils indispensable pour tout utilisateur ou administrateur système.

---

[[06_Flux]] ← → [[08_Processus]]
