#include<bits/stdc++.cpp>
#include<kuangbin/io.cpp>
using namespace std;

class Solution {
public:
    vector<int> getTmpMaxData(vector<int>& nums, int k){
        int cur_max=INT_MIN;
        int cur_max_pos=0;
        int nxt_max = INT_MIN;
        int nxt_max_pos=0;
        int n = nums.size();
        vector<int> res(0, n-k+1);
        for(int i=0; i < n;i++){
            if (nums[i] >= nxt_max) {
                nxt_max = nums[i];
                nxt_max_pos = i;
            }
            if(cur_max_pos <= i-k || nums[i]>=cur_max){
                cur_max = nxt_max;
                cur_max_pos = nxt_max_pos;
                nxt_max = INT_MIN;
            }
            if (i >= k-1) {
               res.push_back(cur_max); 
            }
        }
        return res;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> lres = getTmpMaxData(nums,k);
        reverse(nums.begin(), nums.end());
        vector<int> rres = getTmpMaxData(nums, k);
        int ans_num = rres.size();
        vector<int> res = vector<int>(0, ans_num);
        for(int i = 0; i < lres.size(); i++){
            cout<<lres[i]<<" "<<rres[i]<<endl;
            res.push_back(max(lres[i], rres[ans_num-i-1]));
        }
        return res;
    }
};

int main(){
    freopen("input.txt","r",stdin);
    vector<int> nums;
    scan_v(&nums, ',', append_str_func);
    for(int i = 0;nums[i] != 0; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl<<size<<endl;
    cout<<size;
    return 0;
}