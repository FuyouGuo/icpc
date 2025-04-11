// LUOGU_RID: 207821064
//Coded by Elairin176 (luogu uid=592238)
#include<bits/stdc++.h>
using namespace std;
#define il inline
#define ret return
#define cst const
#define ll long long
#define ui unsigned int
#define ull unsigned ll
#define db double
#define ld long db
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define pii pair<int,int>
#define pll pair<ll,ll>
#define gc getchar
#define pc putchar
#define tpcTi template<class T>il
#define spe pc(' ')
#define edl pc('\n')
#define fi first
#define se second
#define br printf("--------------------\n")
#if __cplusplus <= 199711L
#define re register
#else
#define re  // Deprecated in C++11.
#endif
#define cfor(i,a,b) for(re int i=a;i<=b;++i)
#define crof(i,a,b) for(re int i=a;i>=b;--i)
#define sfor(i,a,b,z) for(re int i=a;i<=b;z)
#define srof(i,a,b,z) for(re int i=a;i>=b;z)
#define clr(i,a) memset(i,a,sizeof(i))
#define debug(x) cerr<<#x<<'='<<x<<endl
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
cst ll INF=9223372036854775807;
cst int inf=2147483647;
cst int xinf=0x3f3f3f3f;
cst ll XINF=0x3f3f3f3f3f3f3f3fll;
cst db pi=acos(-1.0),eps=1e-12;
#if __cplusplus >= 201103L
mt19937 rnd(233);
mt19937_64 RND(233);
#endif
namespace my_icpc_stl{
    tpcTi T _max(T a,T b){ret a>b?a:b;}
    tpcTi T _min(T a,T b){ret a<b?a:b;}
    tpcTi T _abs(T a){ret a<0?-a:a;}
    il ll mod(ll a,ll p){ret (a>=p?a-p:(a<0?a+p:a));}
    il ll madd(ll a,ll b,ll p){ret mod(a+b,p);}
    il ll msub(ll a,ll b,ll p){ret mod(a-b,p);}
    il ll exmul(ll a,ll b,ll p){ll ans=0;while(b){if(b&1)ans=madd(ans,a,p);a=madd(a,a,p);b>>=1;}ret ans;}
    il ll expw(ll a,ll b,ll p){ll ans=1;while(b){if(b&1)ans=exmul(ans,a,p);a=exmul(a,a,p);b>>=1;}ret ans;} 
    il ll pw(ll a,ll b,ll p=INF){if(b==0)ret 1;if(b==1)ret a%p;ll mid=pw(a,b>>1,p)%p;if(b&1)ret mid*mid%p*a%p;else{ret mid*mid%p;}}
    il ll pinv(ll a,ll p){ret pw(a,p-2,p);}
    il ll pdiv(ll a,ll b,ll p){ret a*pinv(b,p)%p;}
    il ll expdiv(ll a,ll b,ll p){ret exmul(a,pinv(b,p),p);}
    tpcTi T read(){char c=gc();T f=1,ans=0;while(c<'0'||c>'9'){if(c=='-') f=-1;c=gc();}while(c>='0'&&c<='9')ans=(ans*10+c-'0'),c=gc();ret ans*f;}
    tpcTi void _swap(T &a,T &b){a^=(b^=(a^=b));}
    il void write(int x){if(x<0){pc('-');x=-x;}if(x>=10){write(x/10);}pc(x%10+'0');}
    il void write(ll x){if(x<0){pc('-');x=-x;}if(x>=10){write(x/10);}pc(x%10+'0');}
    tpcTi T gcd(T a,T b){ret b?gcd<T>(b,a%b):a;}
    tpcTi T lcm(T a,T b){ret a/gcd<T>(a,b)*b;}
    il void write(string s,int st=0){int len=s.length();if(st>=len)ret;cfor(i,st,len-1) pc(s[i]);}
    il void bwrite(int x,int n=-1){stack<int>stk;int len=0;while(x){stk.push(x&1);x>>=1;len++;}if(n!=-1){cfor(i,1,n-len){pc('0');}}while(!stk.empty()){write(stk.top());stk.pop();}}
    il char readc(){char c=getchar();while(c==' '||c=='\n'||c=='\r'){c=getchar();}ret c;}
    il int lowbit(int x){ret x&-x;}
    il int Sdigits(ll x,ll base=2){int cnt=0;while(x){cnt+=x%base,x/=base;}ret cnt;}
    il int Slen(ll x,ll base=10){int cnt=0;while(x){cnt++,x/=base;}ret cnt;}
    il bool isprime(ll x){if(x<2){ret 0;}cfor(i,2,x/i){if(x%i==0){ret 0;}}ret 1;}
    il int dcmp(db x){ret (fabs(x)<=eps?0:(x>0?1:-1));}
    il ll inc(ll a,ll p){ret madd(a,1,p);}
    il ll dec(ll a,ll p){ret msub(a,1,p);}
    tpcTi ll sgn(T x){ret (x<0?-1:(x>0?1:0));}
    tpcTi istream& operator>>(std::istream& in, std::vector<T>& a){for (auto& o : a) in >> o;return in;}

    class DSU{public:vector<int>father_of_DSU;int size_of_DSU;
        il void Init(int n){size_of_DSU=n;father_of_DSU.clear();father_of_DSU.push_back(0);cfor(i,1,n){father_of_DSU.push_back(i);}}
        il int Find(int x){ret (x==father_of_DSU[x]?x:father_of_DSU[x]=Find(father_of_DSU[x]));}
        il void Join(int x,int y){int f1=Find(x),f2=Find(y);if(f1!=f2){father_of_DSU[f1]=f2;}}
        il bool Check(int x,int y){ret Find(x)==Find(y);}};
    class Point{public:db x,y;
        Point(){}Point(cst db& x,cst db& y):x(x),y(y){} 
        il db Len(){ret sqrt(x*x+y*y);} 
        il db Len2(){ret x*x+y*y;}};
    #define Vector Point
    il Point operator+(cst Point& a,cst Point& b){ret Point{a.x+b.x,a.y+b.y};}
    il Point operator-(cst Point& a,cst Point& b){ret Point{a.x-b.x,a.y-b.y};}
    il Point operator*(cst Point& a,cst db x){ret Point{a.x*x,a.y*x};} 
    il Point operator*(cst db x,cst Point& a){ret Point{a.x*x,a.y*x};} 
    il db Cross(cst Point& a,cst Point& b){ret a.x*b.y-a.y*b.x;}
    il db Dot(cst Point& a,cst Point& b){ret a.x*b.x+a.y*b.y;}
    il db Slope(Point x,Point y){ret (x.y-y.y)/(x.x-y.x);}
    il db Dis2(cst Point& a,cst Point& b){ret (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
    il db Dis(cst Point& a,cst Point& b){ret sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
    il Vector Rotate90(cst Vector& a){ret Vector{-a.y,a.x};}
    il Vector Rotate(cst Vector&v,cst db&theta){ret Vector(cos(theta)*v.x-sin(theta)*v.y,sin(theta)*v.x+cos(theta)*v.y);}
    template<class T>class matrix{public:vector<vector<T>>mat;int mat_siz;
    il void Init(int n,T num=0){mat_siz=n;mat.clear();vector<T>v;cfor(i,0,n) v.push_back(num);cfor(i,0,n) mat.push_back(v);}
    il void Init_01(int n){Init(n);cfor(i,1,n) mat[i][i]=1;}};
    tpcTi matrix<T>mat_mul(cst matrix<T>&x,cst matrix<T>&y,cst ll&p){matrix<T>ans;ans.Init(x.mat_siz);int n=x.mat_siz;cfor(i,1,n)cfor(j,1,n)cfor(k,1,n)ans.mat[i][j]=madd(ans.mat[i][j],x.mat[i][k]*y.mat[k][j]%p,p);return ans;}
    tpcTi matrix<T>mat_pw(matrix<T>a,ll k,cst ll&p){matrix<T>ans;ans.Init_01(a.mat_siz);while(k){if(k&1ll)ans=mat_mul(ans,a,p);a=mat_mul(a,a,p);k>>=1ll;}return ans;}
    cst int Mod=998244353,sqi=86583718,inv2=pinv(2,Mod);
    void NTT(int*a,int len,bool INTT){int*r=new int[len];r[0]=0;int l=-1;srof(x,len,0,x>>=1)++l;cfor(i,1,len-1)r[i]=(r[i/2]/2)|((i&1)<<(l-1));cfor(i,0,len-1)if(i<r[i])_swap<int>(a[i],a[r[i]]);delete[]r;sfor(i,1,len-1,i<<=1){int p=(i<<1);int wn=pw(3,(Mod-1)/p,Mod);if(INTT)wn=pinv(wn,Mod);sfor(j,0,len-1,j+=p){int w=1;cfor(k,0,i-1){int x=a[j+k],y=1ll*w*a[i+j+k]%Mod;a[j+k]=(x+y)%Mod;a[i+j+k]=(x-y+Mod)%Mod;w=1ll*w*wn%Mod;}}}if(INTT){int inv=pinv(len,Mod);cfor(i,0,len-1)a[i]=1ll*a[i]*inv%Mod;}}
    class Polynomial{
        public:
            int n;
            int *a;
            Polynomial& resize(int _n);
            Polynomial():n(-1),a(nullptr){}
            Polynomial(cst int &_n);
            Polynomial(cst int &_n, cst int *p);
            Polynomial(cst Polynomial &rhs);
            ~Polynomial();
            il int operator()(int x)cst;
            il int operator[](int i)cst;
            il int& operator[](int i);
            Polynomial& operator=(cst Polynomial &rhs);
            Polynomial operator+(cst Polynomial &rhs)cst;
            Polynomial operator-(cst Polynomial &rhs)cst;
            Polynomial operator-()cst;
            Polynomial operator*(int k)cst;
            Polynomial operator*(cst Polynomial &rhs)cst;
            Polynomial derivative()cst;
            Polynomial integral()cst;
    };
    Polynomial::Polynomial(cst int&_n){n=_n;a=new int[n+1];memset(a,0,sizeof(int)*(n+1));}
    Polynomial::Polynomial(cst int&_n,cst int*p){n=_n;a=new int[n+1];memcpy(a,p,sizeof(int)*(n+1));}
    Polynomial::Polynomial(cst Polynomial&rhs){n=rhs.n;a=new int[n+1];memcpy(a,rhs.a,sizeof(int)*(n+1));}
    Polynomial::~Polynomial(){delete[]a;n=0;}
    Polynomial&Polynomial::resize(int _n){if(_n==n)ret*this;else if(_n<n)n=_n;else{int*p=a;a=new int[_n+1];memcpy(a,p,sizeof(int)*(n+1));memset(a+n+1,0,sizeof(int)*(_n-n));n=_n;delete[]p;}ret*this;}
    Polynomial&Polynomial::operator=(cst Polynomial&rhs){n=rhs.n;a=new int[n+1];memcpy(a,rhs.a,sizeof(int)*(n+1));ret*this;}
    Polynomial Polynomial::operator+(cst Polynomial&rhs)cst{Polynomial res(std::max(n,rhs.n));cfor(i,0,n)res[i]=(*this)[i];cfor(i,0,rhs.n)res[i]=(res[i]+rhs[i])%Mod;ret res;}
    Polynomial Polynomial::operator-(cst Polynomial&rhs)cst{Polynomial res(std::max(n,rhs.n));cfor(i,0,n)res[i]=(*this)[i];cfor(i,0,rhs.n)res[i]=(res[i]-rhs[i]+Mod)%Mod;ret res;}
    Polynomial Polynomial::operator-()cst{Polynomial res(n);for(int i=0;i<=n;i++)res[i]=((*this)[i]?Mod-(*this)[i]:0);ret res;}
    Polynomial Polynomial::operator*(int k)cst{Polynomial res=*this;for(int i=0;i<=n;i++)res[i]=1ll*k*res[i]%Mod;ret res;}
    Polynomial operator*(int k,Polynomial res){for(int i=0;i<=res.n;i++)res[i]=1ll*k*res[i]%Mod;ret res;}
    Polynomial Polynomial::operator*(cst Polynomial&rhs)cst{Polynomial res(n+rhs.n);if(res.n<=5){for(int i=0;i<=n;i++)for(int j=0;j<=rhs.n;j++)res[i+j]=(res[i+j]+1ll*a[i]*rhs[j])%Mod;ret res;}int len=1;while(len<=n+rhs.n)len<<=1;int*f=new int[len];int*g=new int[len];memset(f,0,sizeof(int)*len);memset(g,0,sizeof(int)*len);for(int i=0;i<=n;i++)f[i]=(*this)[i];for(int i=0;i<=rhs.n;i++)g[i]=rhs[i];NTT(f,len,0);NTT(g,len,0);for(int i=0;i<len;i++)f[i]=1ll*f[i]*g[i]%Mod;NTT(f,len,1);for(int i=0;i<=n+rhs.n;i++)res[i]=f[i];delete[]f;delete[]g;ret res;}
    il int Polynomial::operator()(int x)cst{int rx=1,res=0;for(int i=0;i<=n;i++){res=(res+1ll*a[i]*rx)%Mod;rx=1ll*rx*x%Mod;}ret res;}
    il int&Polynomial::operator[](int i){ret a[i];}
    il int Polynomial::operator[](int i)cst{ret a[i];}
    Polynomial Polynomial::derivative()cst{Polynomial res(n-1);for(int i=0;i<n;i++)res.a[i]=1ll*a[i+1]*(i+1)%Mod;ret res;}
    Polynomial Polynomial::integral()cst{Polynomial res(n+1);int*inv=new int[n+1];inv[1]=1;for(int i=2;i<=n;i++)inv[i]=(Mod-1ll*(Mod/i)*inv[Mod%i]%Mod)%Mod;for(int i=0;i<=n;i++)res.a[i+1]=1ll*a[i]*inv[i+1]%Mod;ret res;}
    Polynomial constPoly(int x=0){Polynomial res(0);res[0]=x;ret res;}
    Polynomial inv(cst Polynomial&f,int n=-1){if(n==-1)n=f.n+1;if(n==1)ret constPoly(pinv(f[0],Mod));auto g0=inv(f,(n+1)>>1);Polynomial f0(n-1,f.a);ret(g0*2-g0*g0*f0).resize(n-1);}
    Polynomial ln(cst Polynomial&f){ret((f.derivative()*inv(f)).integral().resize(f.n));}
    Polynomial sqrt(cst Polynomial&f,int n=-1){if(n==-1)n=f.n+1;if(n==1)ret constPoly(1);auto g0=sqrt(f,(n+1)>>1).resize(n-1);Polynomial f0(n-1,f.a);ret((g0+f0*inv(g0))*inv2).resize(n-1);}
    Polynomial exp(cst Polynomial&f,int n=-1){if(n==-1)n=f.n+1;if(n==1)ret constPoly(1);auto g0=exp(f,(n+1)>>1).resize(n-1);Polynomial f0(n-1,f.a);ret(g0*(constPoly(1)-ln(g0)+f0)).resize(n-1);}
    Polynomial sin(cst Polynomial&f){ret(exp(sqi*f)-exp(mod(-sqi,Mod)*f))*pinv(2*sqi,Mod);}
    Polynomial cos(cst Polynomial&f){ret(exp(sqi*f)+exp(mod(-sqi,Mod)*f))*inv2;}
    Polynomial tan(cst Polynomial&f){ret sin(f)*inv(cos(f));}
    Polynomial arcsin(cst Polynomial&f){ret (inv(sqrt(constPoly(1)-(f*f).resize(f.n-1)))*f.derivative()).integral();}
    Polynomial arccos(cst Polynomial&f){ret -(inv(sqrt(constPoly(1)-(f*f).resize(f.n-1)))*f.derivative()).integral();}
    Polynomial arctan(cst Polynomial&f){ret (inv(constPoly(1)+(f*f).resize(f.n-1))*f.derivative()).integral();}
}
using namespace my_icpc_stl;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n=read<int>();
    int m=read<int>();
    int a[n],b[m],p[m][2];
    cfor(i,0,m-1) std::fill_n(p[i], 2, -1);
    cfor(i,0,n-1) a[i]=read<int>();
    cfor(i,0,m-1) b[i]=read<int>();
    int i=0,j=0;
    for(int i=0, j=0; i<m&&j<n; i++){
        while(j<n&&b[i]!=a[j]) j++;
        p[i][0]=j;
        j++;
    }
    for(int i=m-1,j=n-1; i>=0&&j>=0; i--){
        while(j>=0&&b[i]!=a[j]) j--;
        p[i][1]=j;
        j--;
    }
    int ans = 0;
    for(int i=0;i<m;i++){
        if(p[i][0] == -1 || p[i][1]==-1 || p[i][0]>=n || p[i][1] < p[i][0]) {
            ans=-1;
            break;
        } else if(p[i][1]>p[i][0]) {
            ans = 1;
        }
    }
    if(ans<1){
        puts("No");
    } else {
        puts("Yes");
    }
    return 0;
}