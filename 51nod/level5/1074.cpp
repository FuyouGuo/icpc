#include<iostream>
#include<algorithm>
using namespace std;
long long n,ans=0,mul=1,i;
int k;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    // 最后只剩一个数,ind=0, 逆向模拟约瑟夫游戏全过程, 由于n比较大，中间过程可以加速
    for(i = 2;i < n;){
        ans = (ans + k * mul) % i;
        // ans + mul * k >= i + mul => mul >= (i-ans)/(k-1)
        mul = max<long long>((i - ans) / (k - 1),1L);
        i += mul;
    }
    // 最后一步i加m后是大于等于n的，我们需要的是i_{n-1}+mul0=n中mul0这部分，所以mul0=mul-(i-n)=mul-i+n
    ans = (ans +(mul - i + n) * k)%n;
    // 约瑟夫游戏是从1开始计数的，但ans下标是从0开始的，所以index+1是其最终编号
    cout<<ans + 1<<endl;
    return 0;
}