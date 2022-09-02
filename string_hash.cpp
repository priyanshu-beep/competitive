struct string_hash {
    int M[4] = {999999929, 999999937, 1000000007, 1000000009};
    int p[4] = {29, 31, 37, 41};
    int inv_p[4] = {793103392, 64516125, 621621626, 195121953};
    int count_of_hash = 4;
    vector<int> pref[4], suff[4], pow_p[4], inv_pow_p[4];
    int n;

    void precompute_forward_hash(string s) {
        n = s.size();

        for (int k = 0; k < count_of_hash; k++) {
            pref[k].assign(n + 1, 0);
            pow_p[k].assign(n + 1, 0);
            inv_pow_p[k].assign(n + 1, 0);
            pow_p[k][0] = 1;
            inv_pow_p[k][0] = 1;

            for (int i = 1; i <= n; i++) {
                pow_p[k][i] = (((long long) pow_p[k][i - 1]) * p[k]) % M[k];
                inv_pow_p[k][i] = (((long long) inv_pow_p[k][i - 1]) * inv_p[k]) % M[k];
                pref[k][i] = ((s[i - 1] - 'a') * ((long long) pow_p[k][i]) + pref[k][i - 1]) % M[k];
            }
        }
    }

    void precompute_backward_hash(string s) {
        n = s.size();

        for (int k = 0; k < count_of_hash; k++) {
            suff[k].assign(n + 2, 0);

            for (int i = n; i >= 1; i--) 
                suff[k][i] = ((s[i - 1] - 'a') * ((long long) pow_p[k][n - i + 1]) + suff[k][i + 1]) % M[k];
        }
    }

    // 0 based inedexing accepted
    vector<int> forword_hash(int l, int r) {
        l++;
        r++;
        vector<int> ans(count_of_hash);

        for (int k = 0; k < count_of_hash; k++) {
            long long hashed_value = ((long long) pref[k][r] - pref[k][l - 1]) % M[k];
            if (hashed_value < 0)
                hashed_value += M[k];

            hashed_value = (hashed_value * inv_pow_p[k][l]) % M[k];
            ans[k] = hashed_value;
        }
        return ans;
    }

    // 0 based inedexing accepted
    vector<int> backward_hash(int l, int r) {
        l++;
        r++;
        vector<int> ans(count_of_hash);

        for (int k = 0; k < count_of_hash; k++) {
            long long hashed_value = ((long long) suff[k][r] - suff[k][l + 1]) % M[k];
            if (hashed_value < 0)
                hashed_value += M[k];

            hashed_value = (hashed_value * inv_pow_p[k][n - l + 1]) % M[k];
            ans[k] = hashed_value;
        }
        return ans;
    }

    // 0 based inedexing accepted
    vector<int> cal_hash(int l, int r) {
        if (l <= r) return forword_hash(l, r);
        else return backward_hash(l, r);
    }
};
