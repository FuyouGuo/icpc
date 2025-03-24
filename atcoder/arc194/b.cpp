#include<bits/stdc++.h>
using namespace std;
using pii = std::pair<int, int>;
using ll =long long;
template<class T>
struct BIT {
    vector<T> h;
    int n;
    inline int lowbit(int i){return i & -i;}
    BIT(int n):n(n){h.resize(n+1);}
    void add(int i, int v){for(;i<=n;i+=lowbit(i)) h[i]+=v;}
    T sum(int i){
        T ans = 0;
        for(;i;i-=lowbit(i)){
            ans += h[i];
        }
        return ans;
    }
};
int main(){
    std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    cin.tie(NULL);
    int n,cur;
    cin>>n;
    BIT<int> t(n);
    ll ans=0;
    for(int i=0;i<n;i++){
        cin>>cur;
        int cnt = t.sum(cur);
        ans += ll(cnt+1+i)*(i-cnt)/2;
        t.add(cur, 1);
    }
    cout<<ans<<endl;
    return 0;
}