#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

namespace leetCode416
{
    /*
        leetCode 416. 分割等和子集

        给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以
        将这个数组分割成两个子集，使得两个子集的元素和相等。

        输入：nums = [1,5,11,5]
        输出：true
        解释：数组可以分割成 [1, 5, 5] 和 [11] 。
    */
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();
        for (int num : nums)
        {
            sum += num;
        }
        if (sum % 2)
            return false;
        int bagCapa = sum / 2;
        vector<int> dp(bagCapa + 1, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = bagCapa; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[bagCapa] == bagCapa)
            return true;
        return false;
    }
} // namespace leetCode416

namespace leetCode698
{
    /*
        leetCode 698. 划分为k个相等的子集

        给定一个整数数组  nums 和一个正整数 k，找出是否有可能
        把这个数组分成 k 个非空子集，其总和都相等。

        输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
        输出： True
        说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
    */
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = 0, n = nums.size();
        for (int num : nums)
        {
            sum += num;
        }
        if (sum % k)
            return false;
        int bagCapa = sum % k;
        vector<int> dp(bagCapa + 1, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = bagCapa; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if(dp[bagCapa] == bagCapa) return true;
        return false;
    }
} // namespace leetCode698

int main()
{
    // leetCode 416. 分割等和子集
    {
        cout << "leetCode 416. 分割等和子集: " << endl;
        vector<int> nums{1, 5, 11, 5};
        cout << leetCode416::canPartition(nums) << endl;
        cout << endl;
    }

    return 0;
}