#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
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

namespace leetCode51
{
    bool isValid(int n, int row, int col, vector<string> &chessboard);
    void backtracking(vector<string> &chessboard, int n, int row);
    vector<vector<string>> result;
    /*
        leetCode 51. N 皇后
        n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
        给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
        每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

        输入：n = 4
        输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
        解释：如上图所示，4 皇后问题存在两个不同的解法。
    */
    vector<vector<string>> solveNQueens(int n)
    {
        result.clear();
        vector<string> chessboard(n, string(n, '.'));
        backtracking(chessboard, n, 0);
        return result;
    }
    void backtracking(vector<string> &chessboard, int n, int row)
    {
        if (row == n)
        {
            result.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isValid(n, row, col, chessboard))
            {
                chessboard[row][col] = 'Q';
                backtracking(chessboard, n, row + 1);
                chessboard[row][col] = '.'; // 回溯
            }
        }
    }

    bool isValid(int n, int row, int col, vector<string> &chessboard)
    {
        // 检查列
        for (int i = 0; i < row; i++)
        {
            if (chessboard[i][col] == 'Q')
                return false;
        }

        // 检查 45度角是否有皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }

        // 检查 135度角是否有皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        return true;
    }

} // namespace leetCode51

namespace leetCode704
{
    /*
        leetCode 704. 二分查找
        给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
        写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

        输入: nums = [-1,0,3,5,9,12], target = 9
        输出: 4
        解释: 9 出现在 nums 中并且下标为 4
    */
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

} // namespace leetCode704

int main()
{
    // leetCode 51. N 皇后
    {
        cout << "leetCode 51. N 皇后: " << endl;
        vector<vector<string>> res;
        res = leetCode51::solveNQueens(4);
        for (vector<string> a : res)
        {
            for (string s : a)
            {
                cout << s << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // leetCode 704. 二分查找
    {
        cout << "leetCode 704. 二分查找: " << endl;
        vector<int> nums{-1, 0, 3, 5, 9, 12};
        cout << leetCode704::search(nums, 9) << endl; // 4
        cout << endl;
    }

    return 0;
}