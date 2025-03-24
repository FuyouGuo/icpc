#include<iostream>
using namespace std;
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int count=0;
        string::size_type pos = -1;
        do{
            ++pos;
            ++count;
            if(sentence.compare(pos, searchWord.length(), searchWord)==0){
                return count;
            }
        }while(pos=sentence.find(" ", pos) != sentence.npos);
        return -1;
    }
};