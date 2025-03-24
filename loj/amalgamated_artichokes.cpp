#include <bits/stdc++.h>
using namespace std;

int main() { 
    ios::sync_with_stdio(false);
    long long p,a,b,c,d;
    long long n;
    cin>>p>>a>>b>>c>>d>>n;
    long double arr[n+1];
    for(int i=1;i<=n;i++){
        arr[i]=p*(sin(a*i+b)+cos(c*i+d)+2);
    }
    cout<<endl;
    if(n==1){
        cout<<0.00<<endl;
    } else {
        long double res = 0;
        long double tmp=arr[1];
        for(int i=2;i<=n;i++){
            tmp=max(tmp, arr[i]);
            res=max(res, tmp-arr[i]);
        }
        cout<<setiosflags(ios::fixed)<<setprecision(8)<<res<<endl;
    }
    return 0;
}