#include<iostream>
#include<list>
#include<vector>
typedef long long ll;
using namespace std;
typedef pair<int,int> pii;
int arr[7],num2,num1,tmp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=1;i<=6;i++){
    	cin>>arr[i];
    }
    int cnt=arr[6]+arr[5]+arr[4];
    if(arr[5]>0){
    	arr[1]-=arr[5]*11;
    }
    if(arr[4]>0){
      num2 = 5 * arr[4];
      tmp=num2;
      num2=max(num2-arr[2],0);
      arr[2] -= tmp;
      arr[1]-=num2*4;  	
    }
    if(arr[3]>0){
    	int num3=(arr[3]+3)/4;
    	cnt += num3;
    	num3=num3*4-arr[3];
    	if(num3==1){
    		num2=1;
    		num1=5;
    	}else if(num3==2){
    		num2=3;
    		num1=6;
    	}else if(num3==3){
    		num2=5;
    		num1=7;
    	}
    	if(arr[2]>0){
    		tmp=num2;
    		num2 = max(num2-arr[2],0);
    		arr[2] -= tmp;
    	}
    	num1 += num2 * 4;
    	if(arr[1]>0){
    		arr[1]-=num1;
    	}
    }
    if(arr[2]>0){
    	num2=(arr[2]+8)/9;
    	cnt += num2;
    	num2=num2*9-arr[2];
    	if(num2>0){
    		arr[1]-=num2*4;
    	}
    }
    if(arr[1]>0){
    	num1=(arr[1]+35)/36;
    	cnt += num1;
    }
    cout<<cnt<<endl;
    return 0;
}