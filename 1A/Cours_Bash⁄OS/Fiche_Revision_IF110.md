# 🎓 Fiche de Révision – IF110 : Systèmes d’Exploitation

## 1. Structure générale d’un système
- Le système d’exploitation (OS) fait le lien entre **le matériel** et **l’utilisateur**.  
- Rôles essentiels :
  - **Gérer les ressources** (CPU, mémoire, fichiers).  
  - **Exécuter et planifier les processus**.  
  - **Assurer la sécurité et la communication**.

---

## 2. Le Shell et Bash
- **Shell** = interpréteur de commandes (ex. : `bash`).  
- **Commandes de base** : `cd`, `pwd`, `ls`, `cp`, `mv`, `rm`.  
- **Aide** : `man`, `help`.  

### Redirections
- `>` : sortie vers fichier.  
- `<` : entrée depuis fichier.  
- `>>` : ajout sans écraser.  
- `|` : enchaînement de commandes (tubes).  

### Variables
- Locales : `nom=valeur`  
- Exportées : `export nom=valeur`  
- Spéciales : `$?`, `$$`, `$!`, `$0`, `$1`, etc.  
- **Alias** : `alias ll='ls -l'`

---

## 3. Système de fichiers
- Organisation **hiérarchique** : `/`, `/home`, `/etc`, `/bin`, `/dev`…  
- **Chemin absolu** → commence par `/`.  
- **Chemin relatif** → dépend du répertoire courant.  
- **Inode** : contient les métadonnées d’un fichier.  

### Liens
- **Dur** : même inode (`ln fichier lien`).  
- **Symbolique** : raccourci (`ln -s fichier lien`).  

### Droits et permissions
- `rwxr-xr--` → propriétaire / groupe / autres.  
- Modifier : `chmod`, `chown`, `chgrp`.

---

## 4. Flux et outils
- **Flux standards** :
  - Entrée : `stdin (0)`  
  - Sortie : `stdout (1)`  
  - Erreur : `stderr (2)`  

### Redirections avancées
```bash
cmd > out.txt 2>&1   # sortie et erreurs dans le même fichier
```

### Commandes clés
`cat`, `grep`, `sort`, `uniq`, `wc`, `cut`, `tr`, `head`, `tail`, `tee`.

---

## 5. Processus
- Un **processus** = programme en exécution.  
- Identifiants : **PID**, **PPID**.  
- États : prêt, en exécution, bloqué, terminé.  

### Observation
`ps`, `pstree`, `top`.

### Contrôle
- Avant-plan : exécution bloquante.  
- Arrière-plan : `&`, `fg`, `bg`, `jobs`.  
- Arrêt : `Ctrl+C`, `kill`, `killall`.  
- Priorité : `nice`, `renice`.

---

## 6. Signaux
- **Communication asynchrone** entre processus.  
- Envoi : `kill -SIGUSR1 PID`.  
- Réception : `trap 'commande' SIGNAL`.  

### Signaux fréquents
| Nom | Effet | Raccourci |
|------|-------|------------|
| `SIGINT` | Interruption | Ctrl + C |
| `SIGTERM` | Arrêt normal | — |
| `SIGKILL` | Arrêt forcé | — |
| `SIGSTOP` | Suspension | Ctrl + Z |
| `SIGCONT` | Reprise | — |

⚠️ `SIGKILL` et `SIGSTOP` ne peuvent pas être interceptés.

---

## 7. Tubes
- **Tubes anonymes** : via `|`  
  → ex. `cat /etc/passwd | grep root`  
- **Tubes nommés** : créés avec `mkfifo`.  
- **Commande `tee`** : duplique un flux vers écran et fichier.
```bash
cat /etc/passwd | grep root | tee result.txt
```

---

## 8. Concurrence et verrouillage
- Plusieurs processus peuvent accéder à la même ressource → **risque d’incohérence**.  
- **Section critique** : partie du code nécessitant un accès exclusif.  
- **Mutex** : verrou empêchant l’accès simultané.

### Scripts de gestion
`P.sh` → prend le verrou (avec `ln` atomique).  
`V.sh` → libère le verrou (`rm`).  

### Interblocage
- Deux processus attendent mutuellement un verrou.  
- Solution : acquérir les verrous **dans le même ordre**.

---

## 9. Commandes essentielles à maîtriser
| Domaine | Commandes clés |
|----------|----------------|
| Navigation | `cd`, `ls`, `pwd` |
| Fichiers | `cp`, `mv`, `rm`, `ln`, `chmod`, `chown` |
| Flux | `cat`, `grep`, `sort`, `tee`, `cut` |
| Processus | `ps`, `top`, `kill`, `nice`, `bg`, `fg` |
| Système | `export`, `alias`, `trap` |

---

## 10. À retenir
- Maîtriser la **logique des redirections** et des **tubes**.  
- Comprendre le **cycle de vie** d’un processus.  
- Savoir gérer les **signaux** et les **verrous**.  
- Appliquer les **principes d’exclusion mutuelle** pour éviter les interblocages.  

---

[[00_Sommaire]] ← → [[01_Introduction_Systemes_Exploitation]]
