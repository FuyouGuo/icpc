#include<bits/stdc++.h>
using namespace std;
namespace FastIO {
    constexpr int LEN = 1 << 20;
    char in[LEN + 1], out[LEN + 1];
    char *pin = in, *pout = out, *ein = in, *eout = out + LEN;

    char gc() { return pin == ein && (ein = (pin = in) + fread(in, 1, LEN, stdin), ein == in) ? EOF : *pin ++; }
    void pc(char c) { pout == eout && (fwrite(out, 1, LEN, stdout), pout = out); (*pout ++) = c; return; }
    struct Flush { ~Flush() { fwrite(out, 1, pout - out, stdout); pout = out; return; } } _flush;

    template<typename T> T Read() {
        T x = 0; int f = 1; char ch = gc();
        while (ch < '0' || ch > '9') f = (ch == '-' ? (~f + 1) : f), ch = gc();
        while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = gc();
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

void solve(int r, int b) {
    int k = (b & 1) > 0 ? 0 : 1;
    int rl = (b+3)>>1;
    for (int i = 1; i < rl; i++) {
        Write("B ", i, " ", i + k, "\n");
    }
    if (r > 0) {
        Write("R ", rl, " ", rl + k, "\n");
        for (int i = 1; i <= (r - 2) / 2; i++) {
            Write("R ", rl + i, " ", rl + k, "\n");
        }
        for (int i = (r - 2) / 2; i > 0; i--) {
            Write("R ", rl + i, " ", rl + k - 1, "\n");
        }
        if (k == 1) {
            Write("R ", rl, " ", rl, "\n");
        }
    }
    for (int row = rl; row >= 3 - k; row--) {
        Write("B ", row, " ", row - 1, "\n");
    }
    if (r > 0 && !k) {
        Write("R ", 2, " ", 1, "\n");
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = Read<int>();
    int r, b;
    while (T--) {
        r = Read<int>();
        b = Read<int>();
        if ((r & 1) || (!r && (b & 1))) {
            Puts("No");
        } else {
            Puts("Yes");
            solve(r, b);
        }
    }
}