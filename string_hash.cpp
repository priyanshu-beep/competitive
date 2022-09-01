ll mex(ll x, ll n, int p) {
    ll result = 1;
    x %= p;
    while (n > 0) {
        if (n & 1)
            result = (result * x) % p;
        x = (x * x) % p;
        n = n >> 1;
    }
    return result;
}

struct string_hash{
    int M[4] = {999999929, 999999937, 1000000007, 1000000009};
    int p[4] = {29, 31, 37, 41};
    int count_of_hash = 4;
    vector<int> pref[4], pow_p[4], inv_pow_p[4];
    vector<int> suff[4], pow_s[4], inv_pow_s[4];
    int n;

    void precompute_forward_hash(string s) {
        n = s.size();        

        for (int k = 0; k < count_of_hash; k++) {
            pref[k].assign(n + 1, 0);
            pow_p[k].assign(n + 1, 0);
            inv_pow_p[k].assign(n + 1, 0);
            pow_p[k][0] = 1;

            for (int i = 1; i <= n; i++) {
                pow_p[k][i] = (((ll)pow_p[k][i - 1]) * p[k]) % M[k];
                pref[k][i] = ((s[i - 1] - 'a') * ((ll)pow_p[k][i])) % M[k];
                inv_pow_p[k][i] = mex(pow_p[k][i], M[k] - 2, M[k]);
            }
        }   
    }

    void precompute_backward_hash(string s) {
        n = s.size();

        for (int k = 0; k < count_of_hash; k++) {
            suff[k].assign(n + 2, 0);
            pow_s[k].assign(n + 2, 0);
            inv_pow_s[k].assign(n + 2, 0);
            pow_s[k][n + 1] = 1;

            for (int i = n; i >= 1; i--) {
                pow_s[k][i] = (((ll)pow_s[k][i + 1]) * p[k]) % M[k];
                suff[k][i] = ((s[i - 1] - 'a') * ((ll)pow_s[k][i])) % M[k];
                inv_pow_s[k][i] = mex(pow_s[k][i], M[k] - 2, M[k]);
            }
        }   
    }

    // 0 based inedexing accepted
    vector<int> forword_hash(int l, int r) {
        l++;
        r++;
        vector<int> ans(count_of_hash);

        for (int k = 0; k < count_of_hash; k++) {
            ll up = ((ll)pref[k][r] - pref[k][l - 1]) % M[k];
            if (up < 0)
                up += M[k];

            up = (up * inv_pow_p[k][l]) % M[k];

            ans[k] = up;
        }
        return ans;
    }

    // 0 based inedexing accepted
    vector<int> backward_hash(int l, int r) {
        l++;
        r++;
        vector<int> ans(count_of_hash);

        for (int k = 0; k < count_of_hash; k++) {
            ll up = ((ll)suff[k][r] - suff[k][l + 1]) % M[k];
            if (up < 0)
                up += M[k];

            up = (up * inv_pow_p[k][n - l + 1]) % M[k];

            ans[k] = up;
        }
        return ans;
    }

    // 0 based inedexing accepted
    vector<int> cal_hash(int l, int r) {
        if (l <= r) return forword_hash(l, r);
        else return backward_hash(l, r);
    }
};
