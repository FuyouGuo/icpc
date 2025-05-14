#include<bits/stdc++.h>
using namespace std;
namespace FastIO {
    constexpr int LEN = 1<<20;
    char in[LEN + 1], out[LEN + 1];
    char *pin = in, *pout = out, *ein = in, *eout = out + LEN;

    char gc() { return pin == ein && (ein = (pin = in) + fread(in, 1, LEN, stdin), ein == in) ? EOF : *pin ++; }
    void pc(char c) { pout == eout && (fwrite(out, 1, LEN, stdout), pout = out); (*pout ++) = c; return; }
    struct Flush { ~Flush() { fwrite(out, 1, pout - out, stdout); pout = out; return; } } _flush;

    template<typename T> T Read() {
        T x = 0; int f = 1; char ch = gc();
        while (!isdigit(ch)) f = (ch == '-' ? -1 : 1), ch = gc();
        while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = gc();
        cout<<x*f<<endl;
        return x * f;
    }
    void Read(char *s) {
        char ch = gc();
        while (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') ch = gc();
        while ((ch != EOF) && !(ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t')) *s = ch, s ++, ch = gc();
        *s = '\0'; return;
    }
    template<typename T> void Read(T &x) { x = Read<T>(); return; }
    template<typename T, typename ...Args>
    void Read(T &x, Args &...args) { Read(x), Read(args...); return; }
    template<typename T> void Write(T x) {
        static char stk[40]; int tp = 0;
        if (x < 0) pc('-'), x = ~x + 1;
        do stk[tp++] = x % 10 + 48, x /= 10; while (x);
        while (tp --) pc(stk[tp]);
        return;
    }
    void Write(char ch) { pc(ch); return; }
    void Write(const char *s) {
        while (*s != '\0') pc(*s), s++;
        return;
    }
    void Puts(const char *s) {
        Write(s), pc('\n'); return;
    }
    template<typename T, typename ...Args>
    void Write(T x, Args ...args) { Write(x), Write(args...); return; }
}

using namespace FastIO;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = Read<int>();
    while (T--) {
        int n = Read<int>();
        int a[n+1];
        int f[n+1][2];
        for (int i = 1; i <= n; i++) {
            a[i] = Read<int>();
        }
        f[1][0] = f[1][1] = 1;
        f[2][0] = 1 + (a[1] != a[2]);
        f[2][1] = 2 + (a[1] != a[2]);
        for (int i = 3; i <= n; i++) {
            f[i][0] = min(f[i-1][0] + (a[i]!=a[i-1]), f[i-1][1] + (a[i]!=a[i-2]));
            f[i][1] = min(f[i-2][0] + (a[i] != a[i-2]) + (a[i] != a[i-1]), f[i-2][1] + (a[i]!=a[i-1]) + (a[i]!=a[i-3])) + 1;
        }
        Write(min(f[n][0], f[n][1]), "\n");
    }
}