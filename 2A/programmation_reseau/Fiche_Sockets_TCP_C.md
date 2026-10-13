---
tags:
  - reseau
  - C
  - sockets
  - TCP
  - IPv4
module: Programmation réseau
type: Fiche
share_link: https://share.note.sx/8jj33n09#nSQaMz8J4alNZIJcR2XOTA
share_updated: 2026-09-25T09:50:58+02:00
---

# Sockets TCP en C (client)

## 1. Vue d'ensemble

Une **socket** est un point de terminaison de communication réseau, manipulé comme un descripteur de fichier (`int fd`). Pour un client TCP, le déroulement classique est :

```mermaid
graph LR
A[socket] --> B[remplir sockaddr_in]
B --> C[connect]
C --> D[send / recv]
D --> E[close]
```

> [!info] À retenir
> Une socket cliente TCP suit toujours ces étapes : **créer → configurer l'adresse cible → se connecter → échanger → fermer**.

---

## 2. `socket()` — créer le point de communication

```c
int client_fd = socket(AF_INET, SOCK_STREAM, 0);
```

| Paramètre | Rôle | Valeurs courantes |
|---|---|---|
| `domain` | Famille d'adresses | `AF_INET` (IPv4), `AF_INET6` (IPv6), `AF_UNIX` (local) |
| `type` | Mode de communication | `SOCK_STREAM` (TCP, connecté, fiable), `SOCK_DGRAM` (UDP, non connecté) |
| `protocol` | Protocole précis | `0` = laisse le noyau choisir le protocole par défaut du couple (domain, type) |

- Retourne un **descripteur de fichier** (`int`) comme `open()`.
- Retourne `-1` en cas d'échec (`errno` renseigné).

> [!warning] Erreur fréquente
> Oublier de vérifier la valeur de retour de `socket()`. Toujours tester `< 0`.

---

## 3. `struct sockaddr_in` — représenter une adresse IPv4

```c
struct sockaddr_in server_addr;
server_addr.sin_family = AF_INET;
server_addr.sin_port   = htons(1234);
inet_aton("192.168.57.19", &server_addr.sin_addr);
```

Structure (simplifiée) :

```c
struct sockaddr_in {
    sa_family_t    sin_family;   // AF_INET
    in_port_t      sin_port;     // port, en network byte order
    struct in_addr sin_addr;     // adresse IPv4, en network byte order
};
```

### Pourquoi `htons()` ?
- **h**ost **to** **n**etwork **s**hort : convertit un entier 16 bits de l'ordre des octets de la machine (souvent *little-endian* sur x86) vers l'ordre **réseau** (*big-endian*, imposé par la norme).
- Fonctions associées : `htonl()` (32 bits), `ntohs()`/`ntohl()` (sens inverse, à la réception).

> [!tip] Mnémotechnique
> **h**ost **to** **n**etwork : on parle toujours *depuis* la machine locale *vers* le format réseau.

### Conversion d'adresse IP : `inet_aton` vs `inet_pton`
| Fonction      | IPv4 seulement ? | Vérifie une erreur ?                                                   | Statut                        |
| ------------- | ---------------- | ---------------------------------------------------------------------- | ----------------------------- |
| `inet_aton()` | Oui              | Retourne `0` si échec (souvent ignoré, comme dans le code étudié)      | Obsolète-ish, encore répandue |
| `inet_pton()` | IPv4 **et** IPv6 | Retourne `1` (succès), `0` (adresse invalide), `-1` (famille invalide) | Recommandée aujourd'hui       |

> [!danger] Piège classique
> `inet_aton("192.168.57.19", &server_addr.sin_addr);` **sans tester le retour**. Si l'adresse textuelle est mal formée, l'erreur passe silencieusement et `connect()` échouera avec un message confus.

---

## 4. `connect()` — établir la connexion TCP

```c
int ret_value = connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
```

- Déclenche la **poignée de main en trois temps** (*3-way handshake* : SYN, SYN-ACK, ACK).
- **Cast obligatoire** vers `(struct sockaddr *)` : l'API socket est générique et historique (elle doit fonctionner avec `sockaddr_in`, `sockaddr_in6`, `sockaddr_un`...), donc les fonctions attendent le type générique `struct sockaddr *`.
- Retourne `0` si succès, `-1` sinon (`errno` = `ECONNREFUSED`, `ETIMEDOUT`, `ENETUNREACH`, etc.).

> [!info] Pourquoi le cast ?
> `struct sockaddr` et `struct sockaddr_in` ont la **même taille en mémoire** au début (compatibilité binaire) ; le cast permet à une seule fonction `connect()` de traiter plusieurs familles d'adresses sans dupliquer le code (polymorphisme "à la C").

---

## 5. Gestion des erreurs : le pattern `die()`

```c
void die(int ret_value, const char *msg){
    if (ret_value < 0){
        perror(msg);
        exit(EXIT_FAILURE);
    }
}
```

- Convention Unix : la **plupart** des appels système renvoient une valeur `< 0` en cas d'erreur, et positionnent `errno`.
- `perror(msg)` affiche `msg: <description textuelle de errno>` (ex : `"On connecting...: Connection refused"`).
- Factoriser ce contrôle dans une fonction `die()` évite de répéter `if (... < 0) { perror(...); exit(...); }` après chaque appel.

> [!tip] Bonne pratique
> Ce pattern est propre mais **radical** (arrêt immédiat du programme). Dans un vrai serveur, on préfère souvent logguer l'erreur et continuer/nettoyer plutôt que `exit()` brutalement.

---

## 6. Ce qu'il manque dans le programme étudié

- [ ] Vérifier le retour de `inet_aton()`
- [ ] Envoyer/recevoir des données (`send()` / `recv()`) — sans ça, le programme ne fait que tester la connexion
- [ ] `close(client_fd)` avant `return 0;` pour libérer proprement la socket

---

## 7. Aller plus loin : côté serveur (aperçu)

Pour compléter la vision client/serveur :

```c
bind(server_fd, ...);     // associe la socket à une adresse locale + un port
listen(server_fd, backlog); // passe en mode écoute, définit la file d'attente
accept(server_fd, ...);   // bloque jusqu'à une connexion entrante, retourne un nouveau fd
```

> [!info] Différence clé
> Le **client** appelle `connect()` vers une adresse distante connue.
> Le **serveur** appelle `bind()` + `listen()` + `accept()` pour attendre des connexions entrantes.

---
## Etablir la connexion
### Code client.c

```c 
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>

void die(int ret_value, const char *msg){
	if (ret_value < 0){
		perror(msg);
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char *argv[]){
	
	int client_fd = socket(AF_INET,SOCK_STREAM, 0);
	die(client_fd,"socket creation");
	
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(1234);

	// server_addr.sin_addr

	inet_aton("192.168.62.60", &server_addr.sin_addr);
	int ret_value;
	ret_value = connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	die(ret_value, "On connecting...");

	return 0;
}
```

### Code server.c
```c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>

void die(int ret_value, const char *msg){
	if (ret_value < 0){
		perror(msg);
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char *argv[]){
	
	int server_fd = socket(AF_INET,SOCK_STREAM, 0);
	
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(1234);

	inet_aton("192.168.62.60", &server_addr.sin_addr);
	int ret_value = bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	die(ret_value, "On Binding...");

	int backlog = 5;
	ret_value = listen(server_fd, backlog);
	die(ret_value, "On Listening...");

	struct sockaddr_in client_addr = {0};
	socklen_t addr_len = 0;
	printf("Start accepting...\n");
	int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
	die(client_fd,"On Accepting...");
	printf("client_fd = %d\n", client_fd);
	
return 0;
}
```


> [!danger] Attention
> Il faut en premier lieu lancer server.c et ensuite client.c.
> Par ailleurs, dans les deux codes, il faut que l'ip dans `inet_aton` soit la même, soit celle de sa carte réseau, soit celle de loopback ici.

## Echange de données fonctions

```c
// Lit exactement `size` octets depuis `sock` dans `buffer`.
// Boucle tant que tout n'est pas reçu, gère déconnexion et erreurs.

int recv_all(int sock, void *buffer, size_t size){
	size_t read_bytes = 0;
	int ret_value;

  while (read_bytes != size) {
		ret_value = read(sock, (char *)buffer + read_bytes, size - read_bytes);
		if (ret_value == 0) {
			printf("Disconnected\n");
			exit(EXIT_FAILURE);
		}
		die(ret_value, "reading");
		read_bytes += ret_value;
	}
	return ret_value;
}

// Écrit exactement `size` octets depuis `buffer` vers `sock`.
// Boucle tant que tout n'est pas envoyé, gère déconnexion et erreurs.

int send_all(int sock, void *buffer, size_t size){
	size_t written_bytes = 0;
	int ret_value;

	while (written_bytes != size) {
		ret_value = write(sock, (char *)buffer + written_bytes, size - written_bytes);
		if (ret_value == 0) {
			printf("Disconnected\n");
			exit(EXIT_FAILURE);
		}
		die(ret_value, "writing");
		written_bytes += ret_value;
	}
	return ret_value;
}
```

---
## Résumé express

| Étape | Fonction              | Rôle                                                               |
| ----- | --------------------- | ------------------------------------------------------------------ |
| 1     | `socket()`            | Créer le descripteur de socket                                     |
| 2     | remplir `sockaddr_in` | Définir famille, port (`htons`), adresse (`inet_aton`/`inet_pton`) |
| 3     | `connect()`           | Établir la connexion TCP (3-way handshake)                         |
| 4     | `send()`/`recv()`     | Échanger des données                                               |
| 5     | `close()`             | Libérer la socket                                                  |

#TCP #sockets #C #reseau