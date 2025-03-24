/*
 * 题目链接：https://loj.ac/problem/6378
 */
#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;
int upd(int x) { return x + (x >> 31 & P); }
bool eq[1 << 12 | 1], alv[1 << 12 | 1]; // 申请大小为4097数组
int S, K, M, sz;
struct poly {
    int arr[79];
    poly() { memset(arr, 0, sizeof(arr)); }
    int &operator[](int x) { return arr[x]; }
    void operator+=(poly q) {
        for (int i = 0; i <= sz; ++i) arr[i] += q[i];
    }
    void operator*=(int q) {
        for (int i = sz; i >= q; --i) arr[i] -= arr[i - q];
    }
    friend poly operator<<(poly x, int len) {
        for (int i = sz; ~i; --i) x[i] = i >= len ? x[i - len] : 0;
        return x;
    }
} dp[1 << 12 | 1];

#define clr(x, v) memset(x, v, sizeof(x))
#define in(x, y) (x >> y & 1)
int coef[79], mod[173], arr[173], ans[173];
void mul(int *a, int *b) {
    static int tmp[173];
    clr(tmp, 0);
    for (int i = 0; i < sz; ++i)
        if (b[i])
            for (int j = 0; j < sz; ++j) tmp[i + j] = (tmp[i + j] + 1ll * b[i] * a[j]) % P;
    for (int i = 2 * sz; i >= sz; --i)
        if (tmp[i])
            for (int j = 0; j < sz; ++j)
                tmp[i - j - 1] = (tmp[i - j - 1] - 1ll * mod[j] * tmp[i] % P + P) % P;
    memcpy(a, tmp, sizeof(tmp));
}

void calc() {
    clr(ans, 0);
    clr(arr, 0);
    clr(mod, 0);
    mod[0] = arr[1] = ans[0] = 1;
    for (int i = 1; i <= K; ++i)
        for (int j = sz; j >= i; --j) mod[j] = upd(mod[j] - mod[j - i]);
    for (int j = 0; j < sz; ++j) mod[j] = mod[j + 1];
    --S;
    while (S) {
        if (S & 1)
            mul(ans, arr);
        mul(arr, arr);
        S >>= 1;
    }
    clr(arr, 0);
    arr[1] = 1;
    for (int i = 0; i <= sz; ++i) {
        coef[i] = ans[sz - 1];
        mul(ans, arr);
    }
}

int main() {
    while (cin >> S >> K >> M) {
        clr(eq, 1);
        clr(alv, 1);
        sz = K * (K + 1) / 2;
        while (M--) {
            int p, q, sum = 0;
            string op;
            cin >> p >> op >> q;
            --p;
            --q;
            if (op[0] == '<') {
                swap(p, q);
                op[0] = '>';
            }
            for (auto t : op) sum += t;

            for (int i = 0; i < 1 << K; ++i) switch (sum) {
                    case '=':
                        eq[i] &= in(i, p) ^ in(i, q) ^ 1;
                        break;
                    case '!' + '=':
                        eq[i] &= !in(i, p) || !in(i, q);
                        break;
                    case '>':
                        alv[i] &= !in(i, q) || in(i, p);
                        eq[i] &= !in(i, p) || !in(i, q);
                        break;
                    case '>' + '=':
                        alv[i] &= !in(i, q) || in(i, p);
                }
        }
        dp[0] = poly();
        dp[(1 << K) - 1][0] = 1;
        for (int i = (1 << K) - 1; i; --i) {
            if (!alv[i])
                continue;
            vector<int> pot[20];
            int s = (i - 1) & i;
            if (eq[i])
                pot[0].push_back(0);
            while (s) {
                if (eq[i ^ s] && alv[s])
                    pot[__builtin_popcount(s)].push_back(s);
                s = (s - 1) & i;
            }
            dp[i] = dp[i] << __builtin_popcount(i);
            for (int j = __builtin_popcount(i) - 1; ~j; --j) {
                for (auto t : pot[j]) dp[t] += dp[i];
                dp[i] *= j;
            }
        }
        calc();
        int sum = 0;
        for (int i = 0; i <= sz; ++i) sum = (sum + 1ll * coef[i] * dp[0][sz - i]) % P;
        cout << (sum % P + P) % P << endl;
    }
    return 0;
}
 
 