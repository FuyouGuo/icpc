#include<iostream>
using namespace std;
using ll =long long;
int n, cur;
ll ps=0,s=0,ns;
int main(){
    std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    cin>>n;
    cin>>s;
    for(int i=1;i<n;i++){
        cin>>cur;
        ns=max(s+cur,ps);
        ps=s;
        s=ns;
    }
    cout<<s<<endl;
    return 0;
}