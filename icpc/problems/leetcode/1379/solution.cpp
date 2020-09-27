#include<bits/stdc++.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool preOrderTree(TreeNode* cur, TreeNode* target, vector<char>& arr, int ind){
        if(cur == target){
            return true;
        } else {
            if(arr.size()<=ind){
                arr.push_back((char)1);
            } else {
                arr[ind] = (char)1;
            }
            if(cur->left&&preOrderTree(cur->left, target, arr, ind+1)){
                return true;
            }
            arr[ind]=(char)2;
            if(cur->right&&preOrderTree(cur->right, target, arr, ind+1)){
                return true;
            }
        }
        arr[ind]=(char)0;
        return false;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        vector<char> paths;
        if(preOrderTree(original, target, paths, 0)){
            TreeNode* ret = cloned;
            for(int i = 0; i < paths.size(); i++){
                if (paths[i] == (char)1) {
                    ret = ret->left;
                } else if (paths[i] == (char)2) {
                    ret = ret->right;
                }
            }
            return ret;
        }
        return NULL;
    }
};













