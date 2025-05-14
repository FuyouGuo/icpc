#include <bits/stdc++.h>
using namespace std;
char *p1, *p2, buf[100000];
#define nc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++)
template <class T>
inline T read() {
    char c = nc();
    T f = 1, ans = 0;
    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = nc();
    }
    while (c >= '0' && c <= '9')
        ans = (ans * 10 + c - '0'), c = nc();
    return ans * f;
}
int a[200001];
int b[200001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = read<int>();
    int m = read<int>();
    for (int i = 0; i < n; i++) {
        a[i] = read<int>();
    }
    for (int i = 0; i < m; i++) {
        b[i] = read<int>();
    }
    int it = 0, mul = 0;
    for (int i = 0; i < n; i++) {
        if (it < m && a[i] == b[it]) {
            it++;
        } else if (it > 0 && a[i] == b[it - 1]) {
            mul = 1;
        }
    }
    if (it >= m && mul) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}