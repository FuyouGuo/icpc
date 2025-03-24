#include<bits/stdc++.h>
using namespace std;
using pii = std::pair<int, int>;
using ll =long long;
template<class T>
std::istream& operator>>(std::istream& in, std::vector<T>& a)
{
    for (auto& o : a) in >> o;
    return in;
}
int main(){
    std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    int T = 1;
    while(T--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        cin>>a>>b>>c;
        vector<int> ones;
        vector<int> zeros;
        ll sum = 0;
        for(int i=0;i<n;i++){
            if(a[i]==b[i]){
                if(a[i]==1){
                    sum += c[i];
                }
            } else if(a[i]==0){
                ones.push_back(c[i]);
            } else {
                zeros.push_back(c[i]);
            }
        }
        int ops = ones.size() + zeros.size();
        sum = sum * ops;
        sort(zeros.begin(), zeros.end(), std::greater<int>());
        sort(ones.begin(), ones.end());
        for(int i=1;i<zeros.size();i++){
            sum += zeros[i] * ll(i);
        }
        int osize = ones.size();
        for(int i=0; i < ones.size(); i++){
            sum += ll(osize-i)*ones[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}