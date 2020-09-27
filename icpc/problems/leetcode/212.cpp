#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

typedef std::pair<int,int> intPair;

struct intPairHash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1,T2> &pair) const{
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

class Solution {
private:
    bool dfs(string word, int ind, intPair pos, vector<intPair> posList, unordered_map<char,vector<intPair> > charMap, 
        unordered_map<intPair,bool,intPairHash> visited) {
        if (visited.find(pos) == visited.end() && !visited[pos] && std::find(posList.begin(), posList.end(), pos) != posList.end()){
            visited[pos] = true;
            // if (word == "aaba") {
            //     cout<<word<<" "<<pos.first<<" "<<pos.second<<endl;
            // }
            if (isContainWord(word, ind + 1, pos.first, pos.second, charMap, visited)) {
                return true;
            }
        }
        return false;
    };
    bool isContainWord(string word, int ind, int rst, int cst, unordered_map<char,vector<intPair> > charMap, 
    unordered_map<intPair,bool,intPairHash> visited){
        // 从st,j位置开始查询是否包含word（dfs）
        if(ind >= word.size()){
            return true;
        }
        char c = word[ind];
        if (charMap.find(c) == charMap.end()){
            return false;
        }
        vector<intPair> posList = charMap[c];
        if (ind == 0) {
            for (int j = 0; j < posList.size(); j++){
                int rst = posList[j].first;
                int cst = posList[j].second;
                // if(word == "aaba"){
                //     cout<<word<<" "<<rst<<" "<<cst<<endl;
                // }
                visited.clear();
                visited[intPair(rst,cst)]=true;
                if(isContainWord(word, ind+1, rst, cst, charMap, visited)) {
                    return true;
                }
            }
            return false;
        } else {
            bool isContain = false;
            pair<int, int> left = pair<int, int>(rst, cst - 1);
            pair<int, int> right = pair<int, int>(rst, cst+1);
            pair<int, int> up = pair<int, int>(rst-1, cst);
            pair<int, int> down = pair<int, int>(rst + 1, cst);
            return dfs(word, ind, left, posList, charMap, visited) || dfs(word, ind, right, posList, charMap, visited) 
                    || dfs(word, ind, up, posList, charMap, visited) || dfs(word, ind, down, posList, charMap, visited);
        }
    }   
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        unordered_map<char,vector<intPair> > charMap = unordered_map<char, vector<intPair> >();
        vector<string> results;
        for(int i=0;i < board.size();i++){
            for(int j=0;j<board[i].size();j++){
                char c = board[i][j];
                if (charMap.find(c) == charMap.end()){
                    charMap[c] = vector<intPair>();
                }
                charMap[c].push_back(intPair(i, j));
            }
        }
        int maxWord = board.size() * board[0].size();
        unordered_map<intPair,bool,intPairHash> visited = unordered_map<intPair,bool,intPairHash>();
        for(int i=0;i < words.size(); i++) {
            if(words[i].size() > maxWord){
                continue;
            }
            if (isContainWord(words[i], 0, -1, -1, charMap, visited)) {
                results.push_back(words[i]);
            }
        }
        return results;
    }
};

int main(){
    Solution s;
    char v[2][2] = {
        {'a','b'},
        {'a','a'},
    };
    vector<vector<char> > board;
    board.push_back(vector<char>(v[0], v[0] + 2));
    board.push_back(vector<char>(v[1], v[1] + 2));
    // board.push_back(vector<char>(v[2], v[2] + 4));
    // board.push_back(vector<char>(v[3], v[3] + 4));
    string str[7] = {"aba","baa","bab","aaab","aaa","aaaa","aaba"};
    vector<string> words(str, str + 7);
    vector<string> results = s.findWords(board, words);
    // cout<<results.size()<<endl;
    for(int i=0;i < results.size();i++){
        cout<<results[i]<<endl;
    }
    return 0;
}