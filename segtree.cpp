
int n;
int t[4 * N];


void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];


        return;
    }


    int tm = (tl + tr) / 2;

    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);


    t[v] = t[v * 2] + t[v * 2 + 1];

}

int querry(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;

    if (l == tl && r == tr) {
        return t[v];

    }
    int tm = (tl + tr) / 2;

    return querry(v * 2, tl, tm, l, min(r, tm)) + querry(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}


void update(int v, int tl, int tr, int pos, int new_val) {
    
    if (tl == tr) {
        t[v] = new_val;

        return;
    }

    int tm = (tl + tr) / 2;
    if (pos <= tm)
        update(v * 2, tl, tm, pos, new_val);
    else
        update(v * 2 + 1, tm + 1, tr, pos, new_val);


    t[v] = t[v * 2] + t[v * 2 + 1];

}


struct data
{
    //Use required attributes
    ll mn;

    //Default Values
    data() : mn(0) {};
};

struct SegTree
{
    int N;
    vector<data> st;
    vector<bool> cLazy;
    vector<int> lazy;

    void init(int n)
    {
        N = n;
        st.resize(4 * N + 5);
        cLazy.assign(4 * N + 5, false);
        lazy.assign(4 * N + 5, 0);
    }

    //Write reqd merge functions
    void merge(data &cur, data &l, data &r)
    {
        cur.mn = l.mn + r.mn;
    }

    //Handle lazy propagation appriopriately
    void propagate(int node, int L, int R)
    {
        if (L != R)
        {
            cLazy[node * 2] = 1;
            cLazy[node * 2 + 1] = 1;
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        st[node].mn += 1LL * (R - L + 1) * lazy[node];
        lazy[node] = 0;
        cLazy[node] = 0;
    }

    void Build(int node, int L, int R, int ar[])
    {
        if (L == R)
        {
            st[node].mn = ar[L];
            return;
        }
        int mid = (L + R) / 2;
        Build(node * 2, L, mid, ar);
        Build(node * 2 + 1, mid + 1, R, ar);
        merge(st[node], st[node * 2], st[node * 2 + 1]);
    }

    data Query(int node, int L, int R, int i, int j)
    {
        if (cLazy[node])
            propagate(node, L, R);
        if (j < L || i > R)
            return data();
        if (i <= L && R <= j)
            return st[node];
        int mid = (L + R) / 2;
        data left = Query(node * 2, L, mid, i, j);
        data right = Query(node * 2 + 1, mid + 1, R, i, j);
        data cur;
        merge(cur, left, right);
        return cur;
    }

    data pQuery(int node, int L, int R, int pos)
    {
        if (cLazy[node])
            propagate(node, L, R);
        if (L == R)
            return st[node];
        int mid = (L + R) / 2;

        if (pos <= mid)
            return pQuery(node * 2, L, mid, pos);
        else
            return pQuery(node * 2 + 1, mid + 1, R, pos);
    }

    void Update(int node, int L, int R, int i, int j, int val)
    {
        if (cLazy[node])
            propagate(node, L, R);
        if (j < L || i > R)
            return;
        if (i <= L && R <= j)
        {
            cLazy[node] = 1;
            lazy[node] = val;
            propagate(node, L, R);
            return;
        }
        int mid = (L + R) / 2;
        Update(node * 2, L, mid, i, j, val);
        Update(node * 2 + 1, mid + 1, R, i, j, val);
        merge(st[node], st[node * 2], st[node * 2 + 1]);
    }

    void pUpdate(int node, int L, int R, int pos, int val)
    {
        if (cLazy[node])
            propagate(node, L, R);
        if (L == R)
        {
            cLazy[node] = 1;
            lazy[node] = val;
            propagate(node, L, R);
            return;
        }
        int mid = (L + R) / 2;
        if (pos <= mid)
            pUpdate(node * 2, L, mid, pos, val);
        else
            pUpdate(node * 2 + 1, mid + 1, R, pos, val);

        merge(st[node], st[node * 2], st[node * 2 + 1]);
    }

    data query(int pos)
    {
        return pQuery(1, 1, N, pos);
    }

    data query(int l, int r)
    {
        return Query(1, 1, N, l, r);
    }

    void update(int pos, int val)
    {
        pUpdate(1, 1, N, pos, val);
    }

    void update(int l, int r, int val)
    {
        Update(1, 1, N, l, r, val);
    }

    void build(int ar[]) {
        Build(1, 1, N, ar);
    }
};

