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

namespace leetCode27
{
    /*
        leetCode 27. 移除元素

        给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
        不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
        元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

        输入：nums = [3,2,2,3], val = 3
        输出：2, nums = [2,2]
        解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。
              例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = [2,2,0,0]，也会被视作正确答案。
    */
    int removeElement(vector<int> &nums, int val)
    {
        int res = 0, n = nums.size();
        for (int slow = 0, fast = 0; fast < n; fast++)
        {
            if (nums[fast] == val)
            {
                res++;
                continue;
            }
            else
            {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return n - res;
    }
} // namespace leetCode27

namespace leetCode977
{
    /*
        leetCode 977. 有序数组的平方

        给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

        输入：nums = [-4,-1,0,3,10]
        输出：[0,1,9,16,100]
        解释：平方后，数组变为 [16,1,0,9,100]
              排序后，数组变为 [0,1,9,16,100]
    */
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, 0);
        int left = 0, right = n - 1, pos = n - 1;
        while (left <= right)
        {
            int l = nums[left] * nums[left];
            int r = nums[right] * nums[right];
            if (l < r)
            {
                res[pos--] = r;
                right--;
            }
            else
            {
                res[pos--] = l;
                left++;
            }
        }
        return res;
    }
} // namespace leetCode977

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

    // leetCode 27. 移除元素
    {
        cout << "leetCode 27. 移除元素: " << endl;
        vector<int> nums{3, 2, 2, 3};
        int n = leetCode27::removeElement(nums, 3);
        for (int i = 0; i < n; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    // leetCode 977. 有序数组的平方
    {
        cout << "leetCode 977. 有序数组的平方: " << endl;
        vector<int> nums{-4, -1, 0, 3, 10};
        vector<int> res = leetCode977::sortedSquares(nums);
        for (int i : res)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}