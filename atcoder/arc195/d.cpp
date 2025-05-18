#include<bits/stdc++.h>
#include <fcntl.h>
using namespace std;
#define IS_DEBUG 0

namespace my_icpc_stl {
    constexpr int LEN = 1<<20;
    static char in[LEN + 1], out[LEN + 1], *pin = in, *pout = out, *ein = in, *eout = out + LEN;
    inline char gc() { return pin == ein && (ein = (pin = in) + fread(in, 1, LEN, stdin), ein == in) ? EOF : *pin ++;}
    inline void pc(char c) { pout == eout && (fwrite(out, 1, LEN, stdout), pout = out); (*pout ++) = c;}
    struct Flush { ~Flush() { fwrite(out, 1, pout - out, stdout); pout = out;} } _flush;
    void initializer(){ios::sync_with_stdio(0); fcntl(0, F_SETFL, 65542);cin.tie(0);cout.tie(0);if(IS_DEBUG){(void)freopen("input.txt", "r", stdin);(void)freopen("out.txt", "w", stdout);}}
    template<typename T> inline T Read(){char c=gc();T f=1,x=0;while(c<'0'||c>'9'){f=(c=='-'?-1:1),c=gc();}while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=gc();return x*f;}
    template<typename T> inline void Write(T x) {static char stk[40]; short tp = 0;if (x < 0) stk[tp++]='-',x = -x;do stk[tp++] = x % 10 + 48, x /= 10; while (x);while (tp--) pc(stk[tp]);}
    inline void Read(char *s) {char ch = gc();while (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') ch = gc();while ((ch != EOF) && !(ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t')) *s = ch, s++, ch = gc();*s = '\0';}
    inline void Write(char ch) { pc(ch);}
    inline void Write(const char *s) {while (*s != '\0') pc(*s), s++;}
    inline void Puts(const char *s) {Write(s), pc('\n');}
    template<typename T, typename ...Args> inline void Write(T x, Args ...args) { Write(x), Write(args...);}
    template<typename T> inline void Read(T &x) { x = Read<T>();}
    template<typename T, typename ...Args> inline void Read(T &x, Args &...args) { Read(x), Read(args...);}
}
using namespace my_icpc_stl;

constexpr int N = 2e5 + 5;
int a[N];

void dpsolve(int n) {
    int f[N][2];
    for (int i = 1; i <= n; i++) {
        a[i] = Read<int>();
    }
    f[1][0] = f[1][1] = 1;
    f[2][0] = 1 + (a[1] != a[2]);
    f[2][1] = f[2][0] + 1;
    for (int i = 3; i <= n; i++) {
        f[i][0] = min(f[i-1][0] + (a[i]!=a[i-1]), f[i-1][1] + (a[i]!=a[i-2]));
        f[i][1] = min(f[i-2][0] + (a[i] != a[i-2]), f[i-2][1] + (a[i]!=a[i-3])) + 2;
    }
    Write(min(f[n][0], f[n][1]), '\n');
}

void solve(int n) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = Read<int>();
        cnt += (a[i] != a[i-1]);
    }
    a[n+1] = a[n+2] = a[n+3] = 0;   // 数据清零
	for (int i = 1; i <= n; i++) {
        if (a[i] == a[i + 2] && a[i] != a[i + 1]) {
            // 判断i+1交换是否会减少处理次数 
			int cur = i + 1; 
            while (1) {
                // 形似aba[b]格式，[b]含义是后面片段交换处理后只留一个b，类似cbc
				if (a[cur] == a[cur + 2]) { cnt--, i = cur + 1; break;}
				if (a[cur] != a[cur + 3]) break;
				if (a[cur + 1] == a[cur + 2]) break; 
				cur += 2;
			}
		}
    }
    Write(cnt, '\n');
}

int main() {
    initializer();
    int T = Read<int>();
    while (T--) {
        int n = Read<int>();
        solve(n);
    }
}