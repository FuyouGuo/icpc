#include<iostream>
using namespace std;

int main(){
	short int T;
	cin>>T;
	short int sum[1001];
	char data[350];
	sum[0]=1;
	data[0]=1;
	short int right = 1;
	short int re = 0;
	for(short int i = 1; i <= 1000; i++){
		sum[i]=0;
		for(short int j = 0; j<right; j++){
			data[j]=(data[j]<<1) + re;
			if (data[j] >= 10) {
				data[j] -= 10;
				re = 1;
				if(j==right-1){
					right++;
					data[j+1]=0;
				}
			} else {
				re = 0;
			}
			sum[i] += data[j];
		}
	}
	short int n;
	while(T--){
		cin>>n;
		cout<<sum[n]<<endl;
	}
}