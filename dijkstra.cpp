vector<pair<int, int> > g[N];
const int inf = 1e9 + 10;
vi dist(N, inf);

void dijkstra(int source)
{

    dist[source] = 0;
    set<pair<int, int> > s;
    s.insert({0, source});

    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        for (auto it : g[x.second])
            if (dist[it.first] > dist[x.second] + it.second)
            {
                s.erase({dist[it.first], it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first], it.first});

                par[it.F] = x.S;
            }
    }
}
