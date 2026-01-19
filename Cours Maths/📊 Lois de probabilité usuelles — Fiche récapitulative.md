## 🔢 Lois discrètes

### 🔹 Loi de Bernoulli
- **Paramètre** : $p \in [0,1]$
- **Valeurs** : $X \in \{0,1\}$

$$
P(X=1)=p \quad ; \quad P(X=0)=1-p
$$

- **Espérance** : $\mathbb{E}(X)=p$
- **Variance** : $\mathrm{Var}(X)=p(1-p)$

---

### 🔹 Loi Binomiale $\mathcal{B}(n,p)$
- **Paramètres** : $n \in \mathbb{N},\; p \in [0,1]$
- **Valeurs** : $X \in \{0,\dots,n\}$

$$
P(X=k)=\binom{n}{k}p^k(1-p)^{n-k}
$$

- **Espérance** : $\mathbb{E}(X)=np$
- **Variance** : $\mathrm{Var}(X)=np(1-p)$

---

### 🔹 Loi Géométrique $\mathcal{G}(p)$
- **Paramètre** : $p \in ]0,1]$
- **Valeurs** : $X \in \mathbb{N}^*$

$$
P(X=k)=(1-p)^{k-1}p
$$

- **Espérance** : $\mathbb{E}(X)=\dfrac{1}{p}$
- **Variance** : $\mathrm{Var}(X)=\dfrac{1-p}{p^2}$

**Propriété** : sans mémoire

---

### 🔹 Loi de Poisson $\mathcal{P}(\lambda)$
- **Paramètre** : $\lambda>0$
- **Valeurs** : $X \in \mathbb{N}$

$$
P(X=k)=\dfrac{\lambda^k e^{-\lambda}}{k!}
$$

- **Espérance** : $\mathbb{E}(X)=\lambda$
- **Variance** : $\mathrm{Var}(X)=\lambda$

---

## 📈 Lois continues

### 🔹 Loi Uniforme $\mathcal{U}([a,b])$
- **Paramètres** : $a<b$

$$
f(x)=\frac{1}{b-a}, \quad x\in[a,b]
$$

- **Espérance** : $\mathbb{E}(X)=\dfrac{a+b}{2}$
- **Variance** : $\mathrm{Var}(X)=\dfrac{(b-a)^2}{12}$

---

### 🔹 Loi Exponentielle $\mathcal{E}(\lambda)$
- **Paramètre** : $\lambda>0$

$$
f(x)=\lambda e^{-\lambda x}, \quad x\ge 0
$$

- **Espérance** : $\mathbb{E}(X)=\dfrac{1}{\lambda}$
- **Variance** : $\mathrm{Var}(X)=\dfrac{1}{\lambda^2}$

**Propriété** : sans mémoire

---

### 🔹 Loi Normale $\mathcal{N}(\mu,\sigma^2)$
- **Paramètres** : $\mu \in \mathbb{R},\; \sigma>0$

$$
f(x)=\frac{1}{\sigma\sqrt{2\pi}}e^{-\frac{(x-\mu)^2}{2\sigma^2}}
$$

- **Espérance** : $\mathbb{E}(X)=\mu$
- **Variance** : $\mathrm{Var}(X)=\sigma^2$

---

## 🧠 Tableau récapitulatif

| Loi | Espérance | Variance |
|----|----|----|
| Bernoulli(p) | $p$ | $p(1-p)$ |
| Binomiale(n,p) | $np$ | $np(1-p)$ |
| Géométrique(p) | $1/p$ | $(1-p)/p^2$ |
| Poisson($\lambda$) | $\lambda$ | $\lambda$ |
| Uniforme(a,b) | $(a+b)/2$ | $(b-a)^2/12$ |
| Exponentielle($\lambda$) | $1/\lambda$ | $1/\lambda^2$ |
| Normale($\mu,\sigma^2$) | $\mu$ | $\sigma^2$ |
