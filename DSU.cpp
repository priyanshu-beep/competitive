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
