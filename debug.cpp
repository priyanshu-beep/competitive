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
ostream& operator<<(ostream& os, const pair<T, U>& p)
{
    os << "[";
    os << p.first;
    os << ", ";
    os << p.second;
    os << "]";
    return os;
}
#define deb(...)             cout << "(" << #__VA_ARGS__ << "):", dbg(__VA_ARGS__)
inline void  dbg()           { cout << endl; }
template <typename T, typename... V>
inline void  dbg(T t, V... v) {cout << ' ' << t; dbg(v...);}
