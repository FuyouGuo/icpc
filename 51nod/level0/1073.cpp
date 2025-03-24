#include<iostream>
using namespace std;
int n,k,ans=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    // 最后只剩一个数,ind=0, 逆向模拟约瑟夫游戏全过程
    for(int i = 2;i <= n;i++)
        ans = (ans + k)%i;
    // 约瑟夫游戏是从1开始计数的，但ans下标是从0开始的，所以index+1是其最终编号
    cout<<ans + 1<<endl;
    return 0;
}