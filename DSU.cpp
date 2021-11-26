struct DSU
{
    vector<int> sze, parent;

    void init(int n) {
        sze.assign(n + 2, 1);
        parent.resize(n + 2);
        for (int i = 0; i <= n + 1; i++)
            parent[i] = i;
    }

    void make_set(int v) {
        parent[v] = v;
        sze[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return  parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sze[a] < sze[b])
                swap(a, b);
            parent[b] = a;
            sze[a] += sze[b];
        }
    }
};




struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n + 1), siz(n + 1, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};
