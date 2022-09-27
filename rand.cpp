mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll((unsigned long long int)chrono::steady_clock::now().time_since_epoch().count());


long long random(long long l, long long r) {
    if (r < l) swap(l, r);
    return l + (rng() % (r - l + 1));
}
long long randomll(long long l, long long r) {
    if (r < l) swap(l, r);
    return l + (rngll() % (r - l + 1));
}
