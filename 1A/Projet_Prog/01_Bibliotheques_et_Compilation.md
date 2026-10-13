## Introduction

Lorsqu’un programme C est compilé, il traverse plusieurs étapes avant de devenir un exécutable.  
Comprendre ce processus permet de :

- mieux diagnostiquer les erreurs
- structurer un projet proprement
- réutiliser du code grâce aux bibliothèques
- réduire le temps de compilation

---

## 1. La chaîne de compilation

La transformation d’un programme C en exécutable se fait en plusieurs étapes.

### Étapes principales

1. **Prétraitement**
2. **Compilation**
3. **Assemblage**
4. **Édition de liens**
5. **Exécution**

👉 Le schéma du cours (page 6) illustre ce flux depuis les fichiers sources jusqu’à l’exécutable.

### 1.1 Prétraitement

Commande :
```bash
cpp fichier.c