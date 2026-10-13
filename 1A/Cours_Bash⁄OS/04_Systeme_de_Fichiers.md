# Le système de fichiers
[[03_Shell_Bash]] ← → [[05_Complements_Bash]]

---

## Introduction

Le **système de fichiers** est un composant essentiel du système d’exploitation.  
Il définit **la manière dont les données sont organisées, stockées et retrouvées** sur un support physique (disque dur, SSD, clé USB, etc.).  
Sous Linux, tout est vu comme un **fichier** : programmes, périphériques, dossiers, liens, etc.

---

## Chapitre 1 — Organisation hiérarchique

### 1.1 Structure en arborescence

Le système de fichiers sous UNIX/Linux est organisé de façon **hiérarchique** :
```
/
├── bin/
├── etc/
├── home/
│   ├── alice/
│   └── bob/
├── tmp/
├── var/
└── usr/
```

- `/` : racine du système (root).  
- `bin` : commandes de base (binaries).  
- `etc` : fichiers de configuration.  
- `home` : répertoires personnels des utilisateurs.  
- `tmp` : fichiers temporaires.  
- `usr` : programmes et bibliothèques partagés.

### 1.2 Chemins absolus et relatifs

- **Chemin absolu** : part toujours de la racine `/`.  
  Exemple : `/home/alice/Documents/test.txt`
- **Chemin relatif** : dépend du répertoire courant.  
  Exemple : `../images/logo.png`

Commandes utiles :
```bash
pwd      # afficher le répertoire courant
cd ..    # remonter d’un dossier
cd /etc  # aller dans /etc
```

---

## Chapitre 2 — Fichiers et répertoires

### 2.1 Types de fichiers

| Type | Description | Exemple |
|------|--------------|----------|
| **Fichier ordinaire** | contient des données ou du texte | `notes.txt`, `main.c` |
| **Répertoire** | contient d’autres fichiers | `/home`, `/etc` |
| **Lien symbolique** | raccourci vers un autre fichier | `ln -s source lien` |
| **Périphérique** | représente un matériel | `/dev/sda`, `/dev/tty` |
| **Fichier spécial** | sockets, FIFO, pipes nommés | `/var/run/daemon.sock` |

### 2.2 Commandes de manipulation

| Commande | Fonction |
|-----------|----------|
| `ls` | Liste les fichiers |
| `cd` | Change de répertoire |
| `mkdir` | Crée un répertoire |
| `rmdir` | Supprime un répertoire vide |
| `rm` | Supprime un fichier |
| `cp` | Copie un fichier |
| `mv` | Déplace ou renomme |
| `touch` | Crée un fichier vide |
| `cat`, `less`, `head`, `tail` | Affichent le contenu |

Exemple :
```bash
mkdir projet
cd projet
touch main.c
ls -l
```

---

## Chapitre 3 — Inodes et structure interne

### 3.1 Inode : carte d’identité d’un fichier

Chaque fichier possède une **entrée unique** dans la table des inodes.  
Un **inode** contient :
- les **droits d’accès**,  
- le **propriétaire**,  
- la **taille du fichier**,  
- les **dates d’accès/modification**,  
- les **adresses des blocs** de données sur le disque.

Pour afficher les numéros d’inodes :
```bash
ls -i
```

### 3.2 Organisation sur disque

Un disque est divisé en plusieurs zones :
```
+-------------------+
| Boot / Superbloc  | → infos sur le système de fichiers
+-------------------+
| Table d’inodes    | → métadonnées des fichiers
+-------------------+
| Blocs de données  | → contenu des fichiers
+-------------------+
```

### 3.3 Partitions et systèmes de fichiers

Chaque **partition** de disque peut contenir un **système de fichiers** différent :
- **ext4** (Linux),  
- **NTFS** (Windows),  
- **FAT32**, **exFAT**, **XFS**, etc.

Liste des partitions :
```bash
lsblk
df -h
```

---

## Chapitre 4 — Liens entre fichiers

### 4.1 Lien dur (hard link)

Un **lien dur** partage le même inode que le fichier original.  
Les deux noms pointent vers les mêmes données.

```bash
ln fichier1 copie_lien
```

Si le fichier original est supprimé, les données sont toujours accessibles via le lien.

### 4.2 Lien symbolique (soft link)

Un **lien symbolique** est un fichier spécial contenant le chemin d’un autre fichier.

```bash
ln -s fichier_original lien_symbolique
```

Si le fichier d’origine disparaît, le lien devient invalide (**cassé**).

---

## Chapitre 5 — Gestion des droits d’accès

### 5.1 Structure des permissions

Chaque fichier a trois catégories d’accès :
| Catégorie | Signification |
|------------|----------------|
| `u` | Propriétaire (user) |
| `g` | Groupe |
| `o` | Autres utilisateurs |

Et trois types de droits :
| Droit | Symbole | Description |
|--------|----------|-------------|
| Lecture | `r` | lire le fichier |
| Écriture | `w` | modifier le fichier |
| Exécution | `x` | exécuter le fichier |

Exemple de sortie :
```bash
ls -l
-rwxr-xr-- 1 alice dev 2456 oct 18 14:32 script.sh
```

### 5.2 Modifier les permissions

#### Mode symbolique :
```bash
chmod u+x script.sh      # ajoute l’exécution au propriétaire
chmod go-rw secret.txt   # retire lecture/écriture aux autres
```

#### Mode numérique :
Les droits sont codés en octal :
- `r=4`, `w=2`, `x=1`
- Exemple : `chmod 754 fichier` → `rwxr-xr--`

### 5.3 Changer le propriétaire

```bash
chown alice fichier
chgrp dev fichier
```

---

## Chapitre 6 — Recherche et navigation avancée

### 6.1 Commande `find`

Recherche récursive :
```bash
find /home -name "*.txt"
find . -type f -size +1M
```

### 6.2 Commande `locate`

Recherche rapide via base d’index :
```bash
locate fichier.conf
```

### 6.3 Commande `file`

Identifier le type exact de fichier :
```bash
file script.sh
```

### 6.4 Commande `du` et `df`

- `du` → taille des répertoires  
- `df` → espace disque disponible

```bash
du -sh /home/alice
df -h
```

---

## Synthèse finale

Le **système de fichiers** constitue la **colonne vertébrale** du système Linux.  
Il permet de :
- structurer les données sous forme hiérarchique,  
- accéder rapidement à l’information,  
- gérer les liens et permissions,  
- et optimiser le stockage.

**À retenir :**
- Tout est fichier sous Linux.  
- Les inodes gèrent les métadonnées.  
- Les droits d’accès assurent la sécurité.  
- Les liens (durs/symboliques) facilitent l’organisation.

---

[[03_Shell_Bash]] ← → [[05_Complements_Bash]]
