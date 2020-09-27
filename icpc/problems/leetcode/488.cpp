#include<iostream>
#include<cstring>
#include<map>
using namespace std;
class Solution {
private:
    const static int MAX_STEP = INT_MAX - 100;    
public:
    int findSubBoardStep(string board, map<char,int> charCntMap) {
        int charLen = board.length();
        int step = MAX_STEP;
        if (charCntMap.size()<=0 && charLen > 1){
            return MAX_STEP;
        }
        int e = 0;
        char c;
        for(int i=0;i<charLen - 1;i++){
            if(board[i] != board[i+1]){
                c = board[i];
                int cnt = charCntMap[c];
                if(cnt + e >= 2){
                    map<char,int> newCntMap(charCntMap.begin(),charCntMap.end());
                    newCntMap[c] = min(cnt, cnt +  e - 2);
                    int j=i-e-1; // 左半边起始位置
                    int g=i+1;   // 右半边起始位置   
                    string s = "";
                    if(j >= 0) {
                        s = board.substr(0,j+1);
                    }
                    if(g < charLen) {
                        s += board.substr(g, charLen - g);   
                    }
                    // cout<<board<<"   "<<c<<" "<<e<<" "<<cnt<<"&&&&&"<<j<<" "<<g<<" "<<s<<endl;
                    int ii = max(0, 2 - e);
                    if(s.length() <= 1) {
                        step = min(step, ii);
                    } else {
                        step = min(step, findSubBoardStep(s, newCntMap) + ii);
                    }
                    // cout<<board<<" "<<board[i-1]<<" "<<cnt<<" " << step << endl;
                }
                e = 0;
            } else {
                e++;
            }
        }
        return step;
    }
    int findMinStep(string board, string hand) {
        map<char, int> charCntMap;
        for(int i=0;i<hand.length();i++){
            charCntMap[hand[i]]++;
        }
        board += "$";
        int cnt = findSubBoardStep(board, charCntMap);
        if (cnt >= MAX_STEP) {
            return -1;
        }
        return cnt;
    }
};

int main(){
    Solution s;
    cout<<s.findMinStep("RBYYBBRRB", "YRBGB")<<endl;
    return 0;
}