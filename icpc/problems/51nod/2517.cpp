#include<iostream>
using namespace std;
int main(){
    int n,tmp,sum=0,ind=-1;
    char c;
    cin>>n;
    int res=0, res0=0;
    for(int i=0;i<n;i++){
        cin>>c;
        tmp=c-'0';
        sum += tmp;
        if(i+1-2 * sum > res){
            res = i+1-2*sum;
            res0 = sum;
            ind=i;
        }
    }
    cout<<2*res0+n-ind-1-sum<<endl;
}