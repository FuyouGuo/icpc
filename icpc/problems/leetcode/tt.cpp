#include<iostream>
#include<string>
#include<cmath>
using namespace std;
const int MOD = 1000000007;
class Solution {
	public:
		void addMod(long long& a, long long b) {
			a = (a + b) % MOD;
		}

		int numDecodings(string s) {
			if (s.empty()) return 0;

			int n = s.size();
			long long f1 = 1;
			long long f2 = 1;
			long long nf;
			int d;

			for(int i = 0; i < n; ++i) {
				nf = 0;
				if (s[i] != '0') {
					if (s[i] == '*') addMod(nf, f1 * 9);
					else addMod(nf, f1);
				}

				if (i - 1 >= 0 && s[i-1] != '0') {
					if (s[i] == '*' && s[i-1] == '*') {
						addMod(nf, f2 * 15);
					}
					else if (s[i] != '*' && s[i-1] != '*') {
						if ((s[i-1] - '0') * 10 + s[i] - '0' <= 26) addMod(nf,f2);
					}
					else if (s[i-1] != '*') {
						d = min(9, 26 - (s[i-1] - '0') * 10);
						if (d >= 1) addMod(nf, f2 * d);
					}
					else if (s[i] != '*') {
						d = min(9, (26 - (s[i] - '0')) / 10);
						if (d >= 1) addMod(nf, f2 * d);
					}
				}

				f2 = f1;
				f1 = nf;
			}

			return f1;
		}
};

int main(){
    Solution s;
    cout<<s.numDecodings("2*")<<endl;
}