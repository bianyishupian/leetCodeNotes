#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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

namespace leetCode62
{
    /*
        leetCode 62. 不同路径

        一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
        机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
        问总共有多少条不同的路径？

        输入：m = 3, n = 2
        输出：3
        解释：
        从左上角开始，总共有 3 条路径可以到达右下角。
        1. 向右 -> 向下 -> 向下
        2. 向下 -> 向下 -> 向右
        3. 向下 -> 向右 -> 向下
    */
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
} // namespace leetCode62

namespace leetCode63
{
    /*
        leetCode 63. 不同路径II

        一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
        机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。
        现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
        网格中的障碍物和空位置分别用 1 和 0 来表示。

        输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
        输出：2
        解释：3x3 网格的正中间有一个障碍物。
        从左上角到右下角一共有 2 条不同的路径：
        1. 向右 -> 向右 -> 向下 -> 向下
        2. 向下 -> 向下 -> 向右 -> 向右
    */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 1)
                break;
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[0][j] == 1)
                break;
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
} // namespace leetCode63

namespace leetCode343
{
    /*
        leetCode 343. 整数拆分

        给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
        返回你可以获得的最大乘积 。

        输入: n = 2
        输出: 1
        解释: 2 = 1 + 1, 1 × 1 = 1。
    */
    int integerBreak(int n)
    {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j <= i / 2; j++)
            {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
} // namespace leetCode343

namespace leetCode96
{
    /*
        leetCode 96. 不同的二叉搜索树

        给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的
        二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

        输入：n = 3
        输出：5
    */
    int numTrees(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
} // namespace leetCode96

namespace test01
{
    /*
        test 01. 01背包问题

        有n件物品和一个最多能背重量为w 的背包。第i件物品的重量是weight[i]，
        得到的价值是value[i] 。每件物品只能用一次，求解将哪些物品装入背包里物品价值总和最大。


    */
    int test_01_bag(vector<int> weight, vector<int> value, int bagCapacity)
    {
        int n = weight.size();
        vector<vector<int>> dp(n, vector<int>(bagCapacity + 1, 0));
        for (int j = weight[0]; j <= bagCapacity; j++)
        {
            dp[0][j] = value[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= bagCapacity; j++)
            {
                if (j < weight[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }

        return dp[n - 1][bagCapacity];
    }
} // namespace test01

int main()
{
    // leetCode 62. 不同路径
    {
        cout << "leetCode 62. 不同路径: " << endl;
        cout << leetCode62::uniquePaths(3, 2) << endl;
        cout << endl;
    }

    // leetCode 63. 不同路径II
    {
        cout << "leetCode 63. 不同路径II: " << endl;
        vector<vector<int>> obstacleGrid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
        cout << leetCode63::uniquePathsWithObstacles(obstacleGrid) << endl;
        cout << endl;
    }

    // leetCode 343. 整数拆分
    {
        cout << "leetCode 343. 整数拆分: " << endl;
        cout << leetCode343::integerBreak(2) << endl;
        cout << endl;
    }

    // leetCode 96. 不同的二叉搜索树
    {
        cout << "leetCode 96. 不同的二叉搜索树: " << endl;
        cout << leetCode96::numTrees(3) << endl;
        cout << endl;
    }

    // test 01. 01背包问题
    {
        cout << "test 01. 01背包问题: " << endl;
        vector<int> weight{1, 3, 4};
        vector<int> value{15, 20, 30};
        int bagCap = 4;
        cout << test01::test_01_bag(weight, value, bagCap) << endl;
        cout << endl;
    }

    return 0;
}