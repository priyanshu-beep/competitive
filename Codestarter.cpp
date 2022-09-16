// Created by Priyanshu
#include <bits/stdc++.h>
using namespace std;


#define ll                   long long
#define lld                  long double
#define pb                   push_back
#define mp                   make_pair
#define lb                   lower_bound
#define ub                   upper_bound
#define F                    first
#define S                    second
#define cel(x,a)             (((x) + (a) - 1) / (a))
#define all(v)               v.begin(), v.end()

const int N = 1e5 + 4;
const int M = 1e9 + 7;

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p)
{
    os << "[";
    os << p.first;
    os << ", ";
    os << p.second;
    os << "]";
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "[";
    for (int i = 0; i < (int) v.size(); ++i)
    {
        os << v[i];
        if (i != (int) v.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

template <typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& v)
{
    os << "-------\n";

    for (auto &it : v)
        os << it.first << " -> " << it.second << "\n";

    os << "-------\n";

    return os;
}

#define deb(...)             cout << "(" << #__VA_ARGS__ << "):", dbg(__VA_ARGS__)
inline void  dbg()           { cout << endl; }
template <typename T, typename... V>
inline void  dbg(T t, V... v) {cout << ' ' << t; dbg(v...);}









void solve() {

    int n;
    cin >> n;


    

}









int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);


    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {

        cout << "Case #" << tt << ": ";

        solve();
    }


    return 0;
}
