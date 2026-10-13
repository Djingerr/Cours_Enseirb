# 01C — Historique & Convergence des Réseaux

## Introduction
L’histoire des réseaux est marquée par une succession d’innovations déterminantes :
- la création des premiers réseaux de communication,
- l’automatisation du transport de données,
- la numérisation massive,
- puis la convergence entre télécommunications, informatique et médias.

Comprendre cette évolution permet de saisir pourquoi les réseaux modernes — Internet, réseaux mobiles, TV numérique — reposent sur des technologies communes.

---

# 1. Les motivations historiques

Les besoins initiaux qui ont conduit à la création des réseaux sont constants :
- **Transport d’information**
- **Partage de ressources**
- **Communication entre utilisateurs ou machines**

Ces besoins ont fait naître plusieurs révolutions technologiques successives.

---

# 2. Les trois grandes révolutions des réseaux

## 2.1 Première révolution : l’automatisation du transport de données
Cette étape a vu la mise en place :
- de réseaux **câblés**,
- d’infrastructures de transmission sur **ondes radio**,
- puis de **fibres optiques**.

Objectif : transmettre des données sans intervention humaine, de manière fiable et rapide.

---

## 2.2 Deuxième révolution : la numérisation
Avec l’essor de l’informatique, l’information (voix, images, documents) commence à être représentée par :
- des **bits**,
- des **octets**,
- des **formats numériques**.

Cette numérisation permet :
- une meilleure qualité de transmission,
- de nouveaux services,
- le stockage numérique,
- la réduction des coûts.

---

## 2.3 Troisième révolution : la convergence des réseaux
Les trois mondes :
- **Télécom** (téléphonie),
- **Informatique** (Internet),
- **Médias** (TV / radio)

convergent progressivement autour du protocole **IP**.

Cette convergence est rendue possible par :
- la capacité des réseaux informatiques à transporter tout type de données,
- les progrès de la compression (MPEG, codages audio/vidéo),
- l'évolution de la puissance de calcul.

Services résultants :
- Triple Play (Internet + TV + Téléphonie),
- Quadruple Play (incluant la téléphonie mobile),
- Streaming vidéo,
- VoIP,
- IPTV.

---

# 3. Les familles de réseaux avant la convergence

Avant l'unification autour de l'IP, les réseaux étaient spécialisés.

## 3.1 Réseaux télécom (téléphonie)
Services : Voix 1 ↔ 1
Technologies :
- RTC (Réseau Téléphonique Commuté),
- RNIS (Numérisation de la boucle locale),
- ADSL,
- GSM / UMTS.

Ces réseaux étaient conçus pour :
- garantir un **temps réel strict**,
- offrir un **débit garanti**,
- accepter une **légère perte** d’information.

---

## 3.2 Réseaux de données
Services : N ↔ N
Technologies :
- IP (Internet Protocol),
- Ethernet,
- WLAN / Wi-Fi,
- WMAN.

Contraintes :
- intégrité des données (perte **interdite**),
- hétérogénéité matérielle,
- croissance rapide du volume d’échanges.

Ces réseaux sont plus flexibles et efficaces que ceux de la téléphonie traditionnelle.

---

## 3.3 Réseaux médias (télévision)
Services : 1 → N (diffusion)
Technologies :
- TV analogique hertzienne,
- Câble CATV,
- DVB-T / DVB-S / DVB-C.

Caractéristiques :
- Débits très élevés,
- Tolérance à une perte légère d’information,
- Diffusion simultanée vers des millions de destinataires.

---

# 4. Le passage au tout-numérique

## 4.1 Motivation
Avant 2000, trois réseaux distincts existaient :
- un pour la **voix**,
- un pour les **données**,
- un pour la **télévision**.

Aujourd’hui, un seul réseau suffit :
> Tous ces flux sont transportés sous forme numérique sur des réseaux IP.

---

## 4.2 Les contraintes de la téléphonie
Contraintes :
- transmission en **temps réel**,
- délai réseau ≤ 300 ms,
- perte d'information **non critique**.

Solution historique :
- **commutation de circuits**,
- puis ATM avec commutation de **cellules**.

---

## 4.3 Les contraintes des données informatiques
Contraintes :
- taille croissante des réseaux,
- criticité de l’information,
- risque de congestion.

Solutions :
- **commutation de paquets**,
- **routage** par adresses source/destination.

---

## 4.4 Les contraintes de la télévision
Contraintes :
- transmission à très fort débit,
- perte non critique,
- diffusion de masse.

Anciennes solutions :
- réseaux câblés analogiques.

Aujourd’hui : IPTV, multicast IP.

---

# 5. La convergence technologique
Grâce aux évolutions technologiques :
- compression audio/vidéo (MPEG),
- montée en débit des réseaux,
- optimisation du routage,
- généralisation de l'accès à Internet,

Les services autrefois séparés sont désormais transportés via :
> **IP comme protocole universel**.

C’est cette convergence qui a permis :
- Netflix, YouTube,
- VoIP (Skype, WhatsApp),
- TV sur IP,
- Cloud computing,
- stockage réseaux (NAS),
- réseaux mobiles 3G/4G/5G.

---

# 6. Impact moderne : vers un réseau unique
Nous vivons aujourd’hui dans un modèle où :
- l’infrastructure réseau est partagée,
- les applications dictent leurs besoins (QoS),
- les opérateurs offrent des services multiples sur une même connexion.

Le réseau n’est plus un simple transport :
> Il est devenu une plateforme de services numériques.

---

# Synthèse
Dans ce sous-chapitre, nous avons vu :
- l’évolution historique des réseaux, des premiers systèmes câblés jusqu’à Internet ;
- les trois révolutions majeures : automatisation, numérisation, convergence ;
- la disparition des réseaux spécialisés au profit d’un réseau unique basé sur IP ;
- la transformation profonde des télécoms, de l’informatique et des médias.

Ces notions sont essentielles pour comprendre les technologies modernes comme :
- Ethernet,
- Wi-Fi,
- 4G/5G,
- VoIP,
- IPTV.

---

## Navigation
- ⬅️ Sous-chapitre précédent : [[01B_Nature_Information]]
- ➡️ Sous-chapitre suivant : [[01D_Types_Reseaux]]
- 🏠 Sommaire du chapitre : [[01_Sommaire_Concepts_Generaux]]
- 📘 Sommaire général du cours : [[00_Sommaire]]

