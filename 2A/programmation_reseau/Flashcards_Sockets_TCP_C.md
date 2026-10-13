---
tags: [reseau, C, sockets, TCP]
module: Programmation réseau
type: Flashcards
---

START
Basic
Front: Que fait `socket(AF_INET, SOCK_STREAM, 0)` ?
Back: Crée une socket IPv4 (AF_INET) en mode connecté/fiable TCP (SOCK_STREAM), en laissant le noyau choisir le protocole par défaut (0). Retourne un descripteur de fichier, ou -1 en cas d'erreur.
END

START
Basic
Front: Pourquoi faut-il utiliser `htons()` pour le port dans `sockaddr_in` ?
Back: Parce que le port doit être stocké en "network byte order" (big-endian), alors que la machine locale peut utiliser un autre ordre d'octets (souvent little-endian sur x86). `htons` = host to network short.
END

START
Basic
Front: Différence entre `inet_aton()` et `inet_pton()` ?
Back: `inet_aton()` ne gère que l'IPv4 et son code de retour est peu vérifié en pratique. `inet_pton()` gère IPv4 et IPv6, et distingue clairement succès (1), adresse invalide (0) et famille invalide (-1). `inet_pton` est recommandée aujourd'hui.
END

START
Basic
Front: Pourquoi caste-t-on `&server_addr` en `(struct sockaddr *)` dans `connect()` ?
Back: Car l'API socket est générique : `connect()` accepte n'importe quelle famille d'adresse (`sockaddr_in`, `sockaddr_in6`, `sockaddr_un`...) via le type générique `struct sockaddr *`. Les structures ont une compatibilité binaire au début.
END

START
Basic
Front: Que déclenche l'appel à `connect()` sur une socket TCP ?
Back: La poignée de main en trois temps (3-way handshake) : SYN, SYN-ACK, ACK, qui établit la connexion avec le serveur distant.
END

START
Basic
Front: Quelle convention Unix permet à la fonction `die()` de détecter une erreur ?
Back: La plupart des appels système renvoient une valeur négative (souvent -1) en cas d'échec et positionnent la variable globale `errno`, que `perror()` peut ensuite traduire en message lisible.
END

START
Basic
Front: Quelles sont les étapes supplémentaires côté serveur (absentes côté client) ?
Back: `bind()` (associer la socket à une adresse locale/port), `listen()` (passer en mode écoute avec une file d'attente), `accept()` (bloquer jusqu'à une connexion entrante et obtenir un nouveau descripteur).
END

START
Basic
Front: Quels éléments manquent dans un programme client TCP qui ne fait que `socket → connect → return 0` ?
Back: L'envoi/réception de données (`send`/`recv`), la vérification du retour de la conversion d'adresse (`inet_aton`), et la fermeture propre de la socket (`close`).
END
