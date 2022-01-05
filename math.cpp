
int fac[N + 1];
int infac[N + 1];
int inv[N + 1];
void fact() {
    fac[0] = infac[0] = inv[0] = 1;
    fac[1] = infac[1] = inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        fac[i] = (1LL * fac[i - 1] * i) % M;
        inv[i] = (-(1LL * (M / i) * inv[M % i]) % M + M) % M;
        infac[i] = (1LL * infac[i - 1] * inv[i]) % M;
    }
}

ll ncr(int n, int r) {
    return ((((ll)fac[n] * infac[n - r]) % M) * (ll)infac[r]) % M;
}


bool prime[N];
void SOE() {
    prime[1] = 1;
    prime[0] = 1;
    for (int p = 2; p * p < N; p++)
        if (!prime[p])
            for (int i = p * p; i < N; i += p)
                prime[i] = true;
}

int spf[N];
void sieve() {

    for (int i = 1; i < N; i += 2)
        spf[i] = i;
    for (int i = 2; i < N; i +=2)
        spf[i] = 2;

    for (int i = 3; i * i < N; i += 2)
        if (spf[i] == i)
            for (int j = i * i; j < N; j += i)
                if (spf[j] == j)
                    spf[j] = i;
}
