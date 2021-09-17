bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {return (a.S < b.S);}

struct compare {
    bool operator()(const pair<int, int>& value, const int& key) {return (value.F < key);}
    bool operator()(const int& key, const pair<int, int>& value) {return (key < value.F);}
};
