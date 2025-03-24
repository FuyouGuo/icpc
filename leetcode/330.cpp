#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long t = 0;
        int extraNum = 0;
        for(int i = 0; i < nums.size() && t < n; i++){
            while(nums[i] > t + 1 && t < n){
                extraNum++;
                t = 2 * t + 1;
            }
            t += nums[i];
        }
        while(t < n){
            extraNum++;
            t = 2 * t + 1; 
        }
        return extraNum;
    }
};