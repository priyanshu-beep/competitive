vector<pair<int, int> > g[N];
const int inf = 1e9 + 10;
vi dist(N, inf);

void shortestPath(int src, int n)
{

    priority_queue< pii, vector <pii> , greater<pii> > pq;

    pq.push(make_pair(0, src));
    dist[src] = 0;

    vector<bool> f(n, false);
    while (!pq.empty()) {
        int u = pq.top().S;
        pq.pop();
        f[u] = true;

        for (auto it : g[u])
            if (f[it.F] == false && dist[it.F] > dist[u] + it.S) {
                dist[it.F] = dist[u] + it.S;
                pq.push(make_pair(dist[it.F], it.F));
            }
    }

}

