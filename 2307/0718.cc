#include "public.h"

namespace leetCode1049
{
    /*
        leetCode 1049. 最后一块石头的重量 II

        有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。
        每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
            - 如果 x == y，那么两块石头都会被完全粉碎；
            - 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
        最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。

        输入：stones = [2,7,4,1,8,1]
        输出：1
        解释：
        组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
        组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
        组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
        组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
    */
    int lastStoneWeightII(vector<int> &stones)
    {
        int n = stones.size();
        int sum = 0;
        for (int num : stones)
            sum += num;
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = target; j >= stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return (sum - dp[target]) - dp[target];
    }
} // namespace leetCode1049

namespace leetCode494
{
    /*
        leetCode 494. 目标和

        给你一个整数数组 nums 和一个整数 target 。
        向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
            - 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
        返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

        输入：nums = [1,1,1,1,1], target = 3
        输出：5
        解释：一共有 5 种方法让最终目标和为 3 。
        -1 + 1 + 1 + 1 + 1 = 3
        +1 - 1 + 1 + 1 + 1 = 3
        +1 + 1 - 1 + 1 + 1 = 3
        +1 + 1 + 1 - 1 + 1 = 3
        +1 + 1 + 1 + 1 - 1 = 3
    */
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sum = 0;
        for (int num : nums)
            sum += num;
        int x = (target + sum) / 2;
        if ((target + sum) % 2 == 1)
            return 0;
        if (abs(target) > sum)
            return 0;
        vector<int> dp(x + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = x; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[x];
    }
} // namespace leetCode494

int main()
{
    // leetCode 1049. 最后一块石头的重量 II
    {
        cout << "leetCode 1049. 最后一块石头的重量 II: " << endl;
        vector<int> stones{2, 7, 4, 1, 8, 1};
        cout << leetCode1049::lastStoneWeightII(stones) << endl;
        cout << endl;
    }

    // leetCode 494. 目标和
    {
        cout << "leetCode 494. 目标和: " << endl;
        vector<int> nums{1, 1, 1, 1, 1};
        cout << leetCode494::findTargetSumWays(nums, 3) << endl;
        cout << endl;
    }

    return 0;
}