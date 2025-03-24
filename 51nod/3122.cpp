#include<iostream>
#define lowbit(x) (x&(-x))
typedef long long ll;
using namespace std;
ll c[100006];
int n,m;
void update(int x, int k) {
	for(int i=x;i<=n;i+=lowbit(i))
		c[i]+=k;
}
ll ask(int x) {
	ll ans = 0;
	for(int i=x;i>0;i-=lowbit(i))
		ans+=c[i];
	return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll pre=0,cur,op,x,y,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cur;
		update(i,cur-pre);
		pre=cur;
	}
	for(int i=1;i<=m;i++){
		cin>>op;
		if(op==1){
			cin>>x>>y>>k;
			update(x,k);
			update(y+1,-k);
		} else {
			cin>>x;
			cout<<ask(x)<<endl;
		}
	}
}