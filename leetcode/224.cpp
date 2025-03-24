#include<iostream>
#include<vector>
#include<stack>
using namespace std;

typedef pair<int,int> pairInt;

class Solution {
public:
    int calculate(string s) {
       // io优化  
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);  
      int val = 0;
      int sign = 1;
      int curr = 0;
      int sz = s.size();
      stack<pairInt> stk;
      for (int i = 0; i < sz; i++) {
        char c = s[i];
        if ( c == ' ' ) continue;
        if (c == '(') {
          stk.emplace(curr, sign);
          curr = 0, sign = 1;
          continue;
        }
        bool pop = false;
        if (c == ')') {
          c = '+';
          pop = true;
        }
        if ( c >= '0' && c <= '9') {
          val = (val << 3) + val << 1;
          val += c - '0';
        } else if (c == '+' || c == '-') {
          curr += val * sign;
          val = 0;
          sign = c == '+'?1:-1;
        }
        if (pop) {
          pairInt pp = stk.top(); stk.pop();
          curr *= pp.second;
          curr += pp.first;
        }
      }
      return curr + val * sign;  
    }
};


/**
//动态规划
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

const int time2[121] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 15};


class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int64_t count1 = 1;
        int64_t count2 = s[0]=='*' ? 9:1;
        
        for(int i=1;i<s.size();i++){
            int64_t cur = 0;
            int time1 = 1;
            if(s[i]=='*'){
                time1 = 9;
            }else if(s[i]=='0'){
                time1 = 0;
            } 
            
            int index = s[i-1]=='*' ? 10:s[i-1]-'0';
            index *= 11;
            index += s[i]=='*' ? 10:s[i]-'0';
            
            cur = (count2*time1 + count1*time2[index]) % 1000000007;
            count1 = count2;
            count2 = cur;
        }
        
        return count2;
    }
};
**/