#include<iostream>
using namespace std;
int main() {
string s;
cin>>s;
int counta, countb;
counta = countb = 0;
for (int i = 0; i < s.length(); i++) {
    if (s[i] == '-') {
        counta++;
     } else {
        countb++;
     }
}
if (countb <= 1) {
    cout << "YES" << endl;	
} else {	    
    cout <<(counta % countb == 0? "YES":"NO")<<endl;	
}
}
