#include<iostream>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int s=1, e=n;
	cout<<s;
	s++;
	while(k > 2){
		cout<<" "<<e<<" "<<s;
		e--;
		s++;
		k-=2;
	}
	cout<<" ";
	if(k==2){
		for(;e>s;e--){
			cout<<e<<" ";
		}
		cout<<s<<endl;
	}else {
		for(;s<e;s++){
			cout<<s<<" ";
		}
		cout<<e<<endl;
	}
	return 0;
}