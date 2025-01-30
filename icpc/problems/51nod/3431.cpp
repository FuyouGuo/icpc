#include<iostream>
#include<cstring>
#include<unordered_set>
using namespace std;
int m,n;
int f[1001];
int a[1001],b[11];
int sg(int x) {
	if(f[x]!=-1){
		return f[x];
	}
	unordered_set<int> S;
	for(int j = 0; j < m; j++){
		if(x>=b[j]){
			S.insert(sg(x-b[j]));
		}
	}
	for(int j=0;j<1001;j++){
		if(!S.count(j)){
			return f[x]=j;
		}
	}
	return f[x];
}
int main(){
	memset(f,-1,sizeof(f));
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	int s = 0;
	for(int i=0;i<n;i++){
		s = s^sg(a[i]);
	}
	if(s!=0){
		cout<<"YES"<<endl;
	} else{
		cout<<"NO"<<endl;
		return 0;
	}
	int tmp = s;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			tmp = s^sg(a[i])^sg(a[i]-b[j]);
			if(tmp==0){
				cout<<i+1<<" "<<b[j]<<endl;
				return 0;
			}
		}
	}
	return 0;
}