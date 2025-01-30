#include<iostream>
typedef long long ll;
using namespace std;
ll mod = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,sum=0,tmp;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>tmp;
		sum=(sum+i*(n-i+1)*tmp)%mod;
	}
	cout<<sum<<endl;
	return 0;
}