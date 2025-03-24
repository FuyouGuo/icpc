#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MaxN = 50010;
typedef pair<int, int> pairInt;

class Solution
{
private:
    struct TreeNode
    {
        TreeNode *left, *right;
        int val;
        int cnt;
        int sum[2];
    } root[MaxN];

    TreeNode *traverse(vector<pairInt> &nums, int low, int high)
    {
        if (high <= low)
            return NULL;
        int mid = low + ((high - low) >> 1);
        TreeNode *root = new TreeNode();
        root->left = traverse(nums, low, mid);
        root->sum[0] = root->left ? root->left->sum[0] + root->left->sum[1] + root->left->cnt : 0;
        root->right = traverse(nums, mid + 1, high);
        root->sum[1] = root->right ? root->right->sum[0] + root->right->sum[1] + root->right->cnt : 0;
        root->val = nums[mid].first;
        root->cnt = nums[mid].second;
        return root;
    }

    TreeNode *del_node(TreeNode *node)
    {
        if (NULL == node)
        {
            return NULL;
        }
        if (NULL == node->left)
        {
            return node->right;
        }
        else if (NULL == node->right)
        {
            return node->left;
        }
        else
        {
            // 寻找右侧最小节点，替换到当前节点
            TreeNode *minNode = node->right;
            TreeNode *parent = node;
            while (minNode->left)
                parent = minNode, minNode = minNode->left;
            int val = minNode->val;
            int cnt = minNode->cnt;
            TreeNode *right = minNode->right;
            minNode = node->right;
            while (minNode->left)
                minNode->sum[0] -= cnt, minNode = minNode->left;
            if (parent != node)
            {
                parent->left = minNode->right;
            }
            else
            {
                node->right = minNode->right;
            }
            delete minNode;
            node->cnt = cnt;
            node->sum[1] -= cnt;
            node->val = val;
            return node;
        }
    }

    TreeNode *del(TreeNode *root, int num)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->val == num)
        {
            if (root->cnt > 1)
            {
                root->cnt--;
                return root;
            }
            else
            {
                // if(num == 600207129) {
                //     printTree(root);
                //     printf("\n");
                // }
                return del_node(root);
            }
        }
        else if (root->val < num)
        {
            TreeNode *node = del(root->right, num);
            root->sum[1]--;
            root->right = node;
        }
        else
        {
            TreeNode *node = del(root->left, num);
            root->sum[0]--;
            root->left = node;
        }
        return root;
    }

    int query_reverse_num(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return 0;
        }
        if(val < root->val) {
            return query_reverse_num(root->left, val);
        } else {
            int sum = root->sum[0] + root->cnt;
            if(val > root->val){
                sum += query_reverse_num(root->right, val);
            }
            return  sum;
        }
    }

    void printTree(TreeNode *root)
    {
        if (root != NULL)
        {
            printf("%d  ", root->val);
            printTree(root->left);
            printf("***********");
            printTree(root->right);
        }
    }

    int getRealData(vector<int>&nums, int i){
        int cnt = 0;
        for(int j = i + 1; j < nums.size(); j++){
            if(nums[i] > 2 * (long long)nums[j]) {
                cnt++;
            }
        }
        return cnt;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        std::map<int, int> nums_map = map<int, int>();
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums_map.find(nums[i]) == nums_map.end())
            {
                nums_map[nums[i]] = 0;
            }
            nums_map[nums[i]]++;
        }
        std::vector<pairInt> sorted_nums = vector<pairInt>();
        for (map<int, int>::iterator iter = nums_map.begin(); iter != nums_map.end(); iter++)
        {
            sorted_nums.push_back(pairInt(iter->first, iter->second));
        }
        std::sort(sorted_nums.begin(), sorted_nums.end());
        TreeNode *root = traverse(sorted_nums, 0, sorted_nums.size());
        // printTree(root);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int val = nums[i] >> 1;
            if(!(nums[i]&1)){
                val--;
            }
            int tmp = query_reverse_num(root, val);
            // int tt = getRealData(nums, i);
            // if (tmp != tt) {
            //     // printTree(root);
            //     // printf("%d    %d  %d  ", i, tmp, tt);
            // }
            sum += tmp;
            if(nums[i] < 0) {
                // 负数，需要去掉自身
                sum--;
            }
            // if(nums[i] == 600207129) {
            //     printTree(root);
            //     printf("\n");
            // }
            root = del(root, nums[i]);
            // printTree(root);
            // printf("\n");
            // printf("*** %d  %d    %d \n", nums[i], val, sum);
        }
        return sum;
    }
};

int answer(vector<int> &nums){
    int sum = 0;
    for(int i=0;i < nums.size();i++){
        for(int j=i+1; j < nums.size(); j++){
            if(nums[i] > 2 * (long long) nums[j]) {
                sum++;
            }
        }
    }
    return sum;
}

vector<int> get_nums(int k){
    vector<int> nums = vector<int>();
    for(int i = 0; i < k; i++){
        nums.push_back(rand() % INT32_MAX);
    }
    return nums;
}

void printVector(vector<int>&nums){
    for(int k = 0; k < nums.size(); k++){
        printf("%d,", nums[k]);
    }
}

int main()
{
    for(int i = 0; i< 1000; i++){
        // vector<int> nums(nums_arr, nums_arr + sizeof(nums_arr) / sizeof(int));
        vector<int> nums = get_nums(1000);
        Solution s;
        if(s.reversePairs(nums) != answer(nums)) {
            printVector(nums);
            break;
        }
        // printf("%d   %d\n", s.reversePairs(nums), answer(nums));
    }
    // int nums_arr[] = {1233398521,69297956,754609818,1836275591,796366900,1420400196,1237874120,128762704,1598733599,600207129,950527144,378859175,197140870,1926818416,2131204599,1275947080,70874618,1483764288,1046279452,1222648128};
    // Solution s;
    // vector<int> nums(nums_arr, nums_arr + sizeof(nums_arr) / sizeof(int));
    // printf("%d   %d\n", s.reversePairs(nums), answer(nums));
    return 0;
}