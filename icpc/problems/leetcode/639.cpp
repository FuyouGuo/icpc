#include<iostream>
using namespace std;

class Solution {
private:
    int get_num(char pre, char cur, bool isUnion) {
        int m1 = 0;
        if(!isUnion){
            int m0 = pre == '*' ? 9:pre=='0'?0:1;
            if(cur == '*') {
                m1 += m0 * 9;
            } else {
                m1 = m0;
            }
        }
        if(pre == '*') {
            m1 += cur == '*'?15:cur>'6'?1:2;
        } else if(pre == '1') {
            m1 += cur == '*'?9:1;
        } else if(pre  == '2'){
            m1 += cur == '*'?6:cur>'6'?0:1;
        }
        return m1;
    }
public:
    int numDecodings(string s) {
        int mod = 1e9+7;
        int sz = s.size();
        if(sz <= 0) {
            return  0;
        }
        if(sz <= 1) {
            return s[0] == '*'?9:s[0]=='0'?0:1;
        }
        int dp[sz];
        long long extra = 0;
        dp[0] = s[0] == '*' ? 9:s[0]=='0'?0:1;
        if(dp[0] == 0) {
            return 0;
        }
        for(int i = 1; i < sz; i++){
            dp[i] = ((long long)dp[i - 1] * (s[i]=='*'?9:s[0]=='0'?0:1)) % mod;
            extra = get_num(s[i-1], s[i], true);
            dp[i] = (dp[i] + dp[i-2] * extra) % mod;
        }
        return dp[sz-1];
    }
};

int main(){
    Solution s;
    printf("%d", s.numDecodings("2*9"));
}