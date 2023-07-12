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

namespace leetCode13
{
    /*
        leetCode 13. 罗马数字转整数

        罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
        例如， 罗马数字 2 写做 II ，即为两个并列的 1 。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

        输入: s = "III"
        输出: 3
    */
    int romanToInt(string s)
    {
        /*
            建立一个HashMap来映射符号和值，然后对字符串从左到右来，如果当前字符代表的值不小于其右边，
            就加上该值；否则就减去该值。以此类推到最左边的数，最终得到的结果即是答案
        */
        unordered_map<char, int> map{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (map[s[i]] < map[s[i + 1]])
                res -= map[s[i]];
            else
                res += map[s[i]];
        }
        res += map[s[n - 1]];
        return res;
    }

} // namespace leetCode13

namespace leetCode19
{
    /*
        19. 删除链表的倒数第 N 个结点

        给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

        输入: head = [1,2,3,4,5], n = 2
        输出: [1,2,3,5]
    */
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *x = new ListNode;
        x->next = head;
        ListNode *prev = x;
        ListNode *target = head;
        ListNode *curr = head;
        for (int i = 0; i < n; i++)
        {
            curr = curr->next;
        }
        while (curr != nullptr)
        {
            curr = curr->next;
            target = target->next;
            prev = prev->next;
        }
        prev->next = target->next;
        return x->next;
    }

} // namespace leetCode19

namespace leetCode206
{
    /*
        leetCode 206. 反转链表

        给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

        输入: head = [1,2,3,4,5]
        输出: [5,4,3,2,1]
    */
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

} // namespace leetCode206

namespace leetCode25
{
    /*
        leetCode 25. K 个一组翻转链表

        给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
        k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
        你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

        输入: head = [1,2,3,4,5], k = 2
        输出: [2,1,4,3,5]
    */
    // 翻转一个子链表，并且返回新的头与尾
    pair<ListNode *, ListNode *> myReverse(ListNode *head, ListNode *tail)
    {
        ListNode *prev = tail->next;
        ListNode *p = head;
        while (prev != tail)
        {
            ListNode *nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *hair = new ListNode(0);
        hair->next = head;
        ListNode *pre = hair;

        while (head)
        {
            ListNode *tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i)
            {
                tail = tail->next;
                if (!tail)
                {
                    return hair->next;
                }
            }
            ListNode *nex = tail->next;
            tie(head, tail) = myReverse(head, tail);
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }

} // namespace leetCode25

namespace leetCode42
{
    /*
        leetCode 42.接雨水
        给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，
        计算按此排列的柱子，下雨之后能接多少雨水。

        输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
        输出：6
        解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
    */
    int trap(vector<int> &height)
    {
        // 双指针
        int left = 0, right = height.size() - 1;
        int lmax = 0, rmax = 0;
        int res = 0;
        while (left < right)
        {
            lmax = max(lmax, height[left]);
            rmax = max(rmax, height[right]);

            if (lmax < rmax)
            {
                res += lmax - height[left];
                left++;
            }
            else
            {
                res += rmax - height[right];
                right--;
            }
        }
        return res;
    }

} // namespace leetCode42

namespace leetCode45
{
    /*
        leetCode 45. 跳跃游戏 II

        给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
        每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
            - 0 <= j <= nums[i] 
            - i + j < n
        返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。

        输入：nums = [2,3,1,1,4]
        输出：2
        解释：跳到最后一个位置的最小跳跃数是 2。
        从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
    */
    int jump(vector<int> &nums)
    {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (maxPos >= i)
            {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end)
                {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }

} // namespace leetCode45

int main()
{
    {
        // leetCode 13. 罗马数字转整数
        cout << "leetCode 13. 罗马数字转整数: " << leetCode13::romanToInt("III") << endl; // 3
    }

    {
        // leetCode 19. 删除链表的倒数第 N 个结点
        ListNode *head = new ListNode(1);
        ListNode *temp = head;
        temp->next = new ListNode(2);
        temp = temp->next;
        temp->next = new ListNode(3);
        temp = temp->next;
        temp->next = new ListNode(4);
        temp = temp->next;
        temp->next = new ListNode(5);
        cout << "leetCode 19. 删除链表的倒数第 N 个结点: " << leetCode19::removeNthFromEnd(head, 2) << endl; // [1,2,3,5]
        // delete
    }

    {
        // leetCode 206. 反转链表
        ListNode *head = new ListNode(1);
        ListNode *temp = head;
        temp->next = new ListNode(2);
        temp = temp->next;
        temp->next = new ListNode(3);
        temp = temp->next;
        temp->next = new ListNode(4);
        temp = temp->next;
        temp->next = new ListNode(5);
        cout << "leetCode 206. 反转链表: " << leetCode206::reverseList(head) << endl; // [5,4,3,2,1]
        // delete
    }

    {
        // leetCode 25. K 个一组翻转链表
        ListNode *head = new ListNode(1);
        ListNode *temp = head;
        temp->next = new ListNode(2);
        temp = temp->next;
        temp->next = new ListNode(3);
        temp = temp->next;
        temp->next = new ListNode(4);
        temp = temp->next;
        temp->next = new ListNode(5);
        cout << "25. K 个一组翻转链表: " << leetCode25::reverseKGroup(head, 2) << endl; // [2,1,4,3,5]
        // delete
    }

    {
        // leetCode 42.接雨水
        vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        cout << "leetCode 42.接雨水: " << leetCode42::trap(height) << endl;
    }

    {
        // leetCode 45. 跳跃游戏 II
        vector<int> nums{2, 3, 1, 1, 4};
        cout << "leetCode 45. 跳跃游戏 II: " << leetCode45::jump(nums) << endl; // 
    }

    return 0;
}