#include<bits/stdc++.h>
using namespace std;
#define lson rt<<1;
#define rson rt<<1|1
#define mid (l+r>>1)
#define N 100010

int n,m,a[N],sum[N<<2],tag[N<<2];

void up

int main(){
	int n,m,p;
	cin>>n>>m>>p;
	vector<int> a(n);
	for(int i =0;i<n;i++){
		cin>>a[i];
	}
	int op,l,r;
	for(int j=0;j<m;j++){
		cin>>op>>l>>r;
		operation(op,l,r);
	}
	
}