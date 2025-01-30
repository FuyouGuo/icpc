#include<iostream>
typedef long long ll;
using namespace std;
int T;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    ll base[33];
    for(int i=1;i<=33;i++){
        base[i-1]=(ll(1)<<i)-1;
    }
    while(T--){
        ll n;
        cin>>n;
        if(n==0){
            cout<<0<<endl;
            continue;
        }
        string s;
        int i=32;
        for(;i>=0&&base[i]>n;i--);
        for(;i>=0;i--){
            if(n==2*base[i]){
                n=0;
                s+="2";
                continue;
            } else if(n>=base[i]){
                n-=base[i];
                s+="1";
            }else{
                s+="0";
            }
        }
        cout<<s<<endl;   
    }
    return 0;
}