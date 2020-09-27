#include<iostream>
using namespace std;

class Solution {
private:
    bool isExists[26];
    int  alphaCnt[26];
public:
    string removeDuplicateLetters(string s) {
        for(int i = 0; i < s.length(); i++) {
            int ind=s[i] - 'a';
            isExists[ind]=true;
            alphaCnt[ind]++;
        }
        int j = 0;
        string ret = "";
        for(;!isExists[j];j++);
        for(int i=0;i < s.length(); i++) {
            int ind=s[i]-'a';
            if(isExists[ind]){
                if(ind==j||alphaCnt[ind]==1){
                    ret+=s[i];
                    isExists[ind]=false;
                }
                if(ind==j){
                   for(;!isExists[j];j++); 
                }
            }
            alphaCnt[ind]--;
        }
        return ret;
    }
};

int main(){
    string s;
    Solution solution;
    cin>>s;
    cout<<solution.removeDuplicateLetters(s)<<endl;
}