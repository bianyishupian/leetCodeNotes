#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

namespace jianZhi61
{
    /*
        leetCode 剑指 Offer 61. 扑克牌中的顺子

        从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。
        2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

        输入：输入: [1,2,3,4,5]
        输出：True
    */
    bool isStraight(vector<int> &nums)
    {
        set<int> s;
        int _max = 0, _min = 14;
        for (int num : nums)
        {
            if (num == 0)
                continue;
            else
            {
                _max = max(_max, num);
                _min = min(_min, num);
                if (s.find(num) != s.end())
                    return false;
                s.insert(num);
            }
        }
        return (_max - _min) < 5;
    }

} // namespace jianZhi61

namespace jianZhi62
{
    /*
        leetCode 剑指 Offer 62. 圆圈中最后剩下的数字

        0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。
        例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

        输入：n = 5, m = 3
        输出：3
    */
    int lastRemaining(int n, int m)
    {
        int ans = 0;
        for (int i = 2; i <= n; i++)
        {
            ans = (ans + m) % i;
        }
        return ans;
    }

} // namespace jianZhi62

namespace jianZhi63
{
    /*
        leetCode 剑指 Offer 63. 股票的最大利润

        假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

        输入：7,1,5,3,6,4
        输出：5
        解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
        注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
    */
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;
        int res = 0;
        int _min = prices[0];
        for (int i = 1; i < n; i++)
        {
            _min = min(_min, prices[i]);
            res = max(res, prices[i] - _min);
        }
        return res;
    }

} // namespace jianZhi63

namespace jianZhi64
{
    /*
        leetCode 剑指 Offer 64. 求1+2+…+n

        求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

        输入：n = 3
        输出：6
    */
    int sumNums(int n)
    { // 用sizeof()
        bool a[n][n + 1];
        return sizeof(a) >> 1;
    }

} // namespace jianZhi64

namespace jianZhi65
{
    /*
        leetCode 剑指 Offer 65. 不用加减乘除做加法

        写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

        输入：a = 1, b = 1
        输出：2
    */
    int add(int a, int b)
    {
        while (b != 0)
        {
            int c = (unsigned int)(a & b) << 1;
            a ^= b;
            b = c;
        }
        return a;
    }

} // namespace jianZhi65

namespace jianZhi66
{
    /*
        leetCode 剑指 Offer 66. 构建乘积数组

        给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，
        其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积,
        即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

        输入：[1,2,3,4,5]
        输出：[120,60,40,30,24]
    */
    vector<int> constructArr(vector<int> &a)
    {
        int n = a.size();
        if (n == 0)
            return vector<int>{};
        vector<int> b(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = 1;
        right[n - 1] = 1;
        for (int i = 1; i < n; i++)
        {
            left[i] = left[i - 1] * a[i - 1];
            right[n - i - 1] = right[n - i] * a[n - i];
        }
        for (int i = 0; i < n; i++)
        {
            b[i] = left[i] * right[i];
        }
        return b;
    }

} // namespace jianZhi66

namespace jianZhi67
{
    /*
        leetCode 剑指 Offer 67. 把字符串转换成整数

        写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。

        输入："   -42"
        输出：-42
        解释：第一个非空白字符为 '-', 它是一个负号。
        我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
    */
    class Automaton
    {
        string state = "start";
        unordered_map<string, vector<string>> table = {
            {"start", {"start", "signed", "in_number", "end"}},
            {"signed", {"end", "end", "in_number", "end"}},
            {"in_number", {"end", "end", "in_number", "end"}},
            {"end", {"end", "end", "end", "end"}}};

        int get_col(char c)
        {
            if (isspace(c))
                return 0;
            if (c == '+' or c == '-')
                return 1;
            if (isdigit(c))
                return 2;
            return 3;
        }

    public:
        int sign = 1;
        long long ans = 0;

        void get(char c)
        {
            state = table[state][get_col(c)];
            if (state == "in_number")
            {
                ans = ans * 10 + c - '0';
                ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
            }
            else if (state == "signed")
                sign = c == '+' ? 1 : -1;
        }
    };
    int strToInt(string str)
    {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }

} // namespace jianZhi67

namespace jianZhi68_1
{
    /*
        leetCode 剑指 Offer 68 - I. 二叉搜索树的最近公共祖先

        给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

        输入：root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
        输出：6
        解释: 节点 2 和节点 8 的最近公共祖先是 6。
    */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
            return root;
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }

} // namespace jianZhi68_1

namespace jianZhi68_2
{
    /*
        leetCode 剑指 Offer 68 - II. 二叉树的最近公共祖先

        给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

        输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
        输出：3
        解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
    */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q); // 返回空或者更上面的p、q节点
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;            // 如果left与right都非空(即p、q分别在这棵子树的左右子树中)返回当前节点
        return left ? left : right; // 如果left不为空(即p、q都在左子树)，返回左子树的递归结果，反之亦然
    }

} // namespace jianZhi68_2

int main()
{
    // 剑指 Offer 61. 扑克牌中的顺子
    vector<int> nums{1, 2, 3, 4, 5};
    cout << "剑指 Offer 61. 扑克牌中的顺子: " << jianZhi61::isStraight(nums) << endl; // 1

    // 剑指 Offer 62. 圆圈中最后剩下的数字
    cout << "剑指 Offer 62. 圆圈中最后剩下的数字: " << jianZhi62::lastRemaining(5, 3) << endl; // 3

    // 剑指 Offer 63. 股票的最大利润
    vector<int> prices{7, 1, 5, 3, 6, 4};
    cout << "剑指 Offer 63. 股票的最大利润: " << jianZhi63::maxProfit(prices) << endl; // 5

    // 剑指 Offer 64. 求1+2+…+n
    cout << "剑指 Offer 64. 求1+2+…+n: " << jianZhi64::sumNums(3) << endl; // 6

    // 剑指 Offer 65. 不用加减乘除做加法
    cout << "剑指 Offer 65. 不用加减乘除做加法: " << jianZhi65::add(1, 1) << endl; // 2

    // 剑指 Offer 66. 构建乘积数组
    vector<int> a{1, 2, 3, 4, 5};
    cout << "剑指 Offer 66. 构建乘积数组: "; // [120,60,40,30,24]
    vector<int> res = jianZhi66::constructArr(a);
    for (int i : res)
        cout << i << ' ';
    cout << endl;

    // 剑指 Offer 67. 把字符串转换成整数
    cout << "剑指 Offer 67. 把字符串转换成整数: " << jianZhi67::strToInt("   -42") << endl; // -42

    // 剑指 Offer 68 - I. 二叉搜索树的最近公共祖先
    TreeNode *head = new TreeNode(2);
    TreeNode *p = new TreeNode(1);
    TreeNode *q = new TreeNode(3);
    head->left = p;
    head->right = q;
    cout << "Offer 68 - I. 二叉搜索树的最近公共祖先: " << jianZhi68_1::lowestCommonAncestor(head, p, q) << endl; // head

    // 剑指 Offer 68 - II. 二叉树的最近公共祖先
    cout << "Offer 68 - II. 二叉树的最近公共祖先: " << jianZhi68_2::lowestCommonAncestor(head, p, q) << endl; // head
    delete head;
    delete p;
    delete q;

    // 剑指 Offer 64. 求1+2+…+n

    // 剑指 Offer 64. 求1+2+…+n

    // 剑指 Offer 64. 求1+2+…+n

    // 剑指 Offer 64. 求1+2+…+n

    return 0;
}