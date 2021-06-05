

struct Data
{
    //Use required attributes
    ll mn;

    //Default Values
    Data() : mn(0) {};
};

struct SegTree
{
    int N;
    vector<Data> st;
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
    void merge(Data &cur, Data &l, Data &r)
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

    Data Query(int node, int L, int R, int i, int j)
    {
        if (cLazy[node])
            propagate(node, L, R);
        if (j < L || i > R)
            return Data();
        if (i <= L && R <= j)
            return st[node];
        int mid = (L + R) / 2;
        Data left = Query(node * 2, L, mid, i, j);
        Data right = Query(node * 2 + 1, mid + 1, R, i, j);
        Data cur;
        merge(cur, left, right);
        return cur;
    }

    Data pQuery(int node, int L, int R, int pos)
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

    Data query(int pos)
    {
        return pQuery(1, 1, N, pos);
    }

    Data query(int l, int r)
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






// for point update only no lazy propagation


struct Data
{
    //Use required attributes
    ll mn;

    //Default Values
    Data() : mn(0) {};
};

struct SegTree
{
    int N;
    vector<Data> st;

    void init(int n)
    {
        N = n;
        st.resize(4 * N + 5);
    }

    //Write reqd merge functions
    void merge(Data &cur, Data &l, Data &r)
    {
        cur.mn = l.mn + r.mn;
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


    Data Query(int node, int L, int R, int i, int j) {

        if (j < L || i > R)
            return Data();
        if (i <= L && R <= j)
            return st[node];
        
        int mid = (L + R) / 2;
        Data left = Query(node * 2, L, mid, i, j);
        Data right = Query(node * 2 + 1, mid + 1, R, i, j);
        Data cur;
        merge(cur, left, right);
        return cur;
    }

    void pUpdate(int node, int L, int R, int pos, int val)
    {
        if (L == R) {
            st[node].mn = val;
            return;
        }

        int mid = (L + R) / 2;
        if (pos <= mid)
            pUpdate(node * 2, L, mid, pos, val);
        else
            pUpdate(node * 2 + 1, mid + 1, R, pos, val);

        merge(st[node], st[node * 2], st[node * 2 + 1]);
    }



    Data query(int l, int r)
    {
        return Query(1, 1, N, l, r);
    }

    void update(int pos, int val)
    {
        pUpdate(1, 1, N, pos, val);
    }

    void build(int ar[]) {
        Build(1, 1, N, ar);
    }
};


