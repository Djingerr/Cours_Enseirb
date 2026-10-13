---
tags: [communications-numériques, introduction]
---

# 01 — Introduction et modèle de Shannon

[[00 - Index - Communications Numériques|← Retour à l'index]]

---

## 📖 Définitions de base

**Télécommunications** : transmission, émission ou réception d'informations par fil, radioélectricité, optique, etc.

**Communications numériques** : le signal transmis est **échantillonné et quantifié**, sous la forme d'une suite de symboles (le **bit** est l'unité).

---

## 📡 Modèle de Shannon-Weaver (1948)

```
                      Message              Signal
[Source d'info] ───────────────→ [Émetteur] ──────→ [Canal]
                                                      │
                                                      │ Signal reçu
                                                      ▼
[Destination] ←─────────────── [Récepteur]
                Message reçu
```

| Bloc | Rôle |
|------|------|
| **Source d'information** | Produit le message original |
| **Émetteur** | Convertit le message en signal transmissible (codage, modulation) |
| **Canal** | Média de propagation : câble coaxial, paire torsadée, air, fibre... |
| **Récepteur** | Reconvertit le signal en message compréhensible |
| **Destination** | Reçoit le message |

⚠️ **Point crucial** : `Message ≠ Message reçu` à cause des **erreurs de transmission** (bruit, atténuation, IES...).

---

## 🌐 Bande de base vs Bande transposée

Deux familles de systèmes :

| Critère | **Bande de base** | **Bande transposée** |
|---------|-------------------|----------------------|
| Fréquence porteuse $f_p$ | $f_p = 0$ Hz | $f_p > 0$ Hz |
| Usage typique | Transmissions **filaires** | Transmissions **sans fil** |
| Symboles | **Réels** | **Complexes** |

→ Voir [[02 - Signaux en bande de base]] pour le détail bande de base
→ Voir [[10 - Transmission sur fréquence porteuse]] pour la bande transposée

---

## 📜 Repères historiques

| Date | Événement |
|------|-----------|
| Avant 1800 | Sémaphores, signaux de fumée, tambours |
| **1794** | Télégraphe de Chappe |
| 1837 | Télégraphe électrique |
| 1897 | Télégraphe sans fil (Marconi) |
| **1924** | **Nyquist** — débit max sans IES dans une bande donnée |
| **1948** | **Shannon/Weaver** — théorie formelle de la communication sans erreur |
| 1980 → 2030 | 1G → 6G |

---

## ✅ À retenir

- Une chaîne de communication a 5 blocs : source / émetteur / canal / récepteur / destination
- Le **canal introduit du bruit** : il faut concevoir un système qui le compense
- Deux modes : **bande de base** (filaire) et **bande transposée** (sans fil)
