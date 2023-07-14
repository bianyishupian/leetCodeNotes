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

namespace leetCode209
{
    /*
        leetCode 209. 长度最小的子数组

        给定一个含有 n 个正整数的数组和一个正整数 target 。
        找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr]，
        并返回其长度。如果不存在符合条件的子数组，返回 0 。

        输入：target = 7, nums = [2,3,1,2,4,3]
        输出：2
        解释：子数组 [4,3] 是该条件下的长度最小的子数组。
    */
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int res = INT_MAX;
        int sum = 0;
        int n = nums.size();
        int i = 0, j = 0;
        for (; j < n; j++)
        {
            sum += nums[j];
            while (sum >= target)
            {
                res = min(res, (j - i + 1));
                sum -= nums[i++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }

} // namespace leetCode209

namespace leetCode59
{
    /*
        leetCode 59. 螺旋矩阵 II

        给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

        输入: n = 3
        输出: [[1,2,3],[8,9,4],[7,6,5]]
    */
    vector<vector<int>> generateMatrix(int n)
    {
        int loop = n / 2, mid = n / 2;
        int startx = 0, starty = 0;
        int count = 1;
        vector<vector<int>> res(n, vector<int>(n, 0));
        int offset = 1; // 左闭右开控制
        while (loop--)
        {
            int i = startx, j = starty;

            // left -> right
            for (; j < n - offset; j++)
            {
                res[i][j] = count++;
            }
            // up -> down
            for (; i < n - offset; i++)
            {
                res[i][j] = count++;
            }
            // right -> left
            for (; j >= offset; j--)
            {
                res[i][j] = count++;
            }
            // down -> up
            for (; i >= offset; i--)
            {
                res[i][j] = count++;
            }

            startx++;
            starty++;
            offset++;
        }
        if (n % 2)
        {
            res[mid][mid] = count;
        }
        return res;
    }

} // namespace leetCode59

namespace leetCode203
{
    /*
        leetCode 203. 移除链表元素

        给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

        输入：head = [1,2,6,3,4,5,6], val = 6
        输出：2, nums = [1,2,3,4,5]
    */
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *hair = new ListNode(0, head);
        ListNode *prev = hair;
        ListNode *after = head;
        while (head)
        {
            after = head->next;
            if (head->val == val)
            {
                prev->next = after;
                head = after;
            }
            else
            {
                prev = head;
                head = after;
            }
        }

        return hair->next;
    }
} // namespace leetCode203

namespace leetCode707
{
    /*
        leetCode 707.设计链表

        实现 MyLinkedList 类：
        - MyLinkedList() 初始化 MyLinkedList 对象。
        - int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
        - void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
        - void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
        - void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，
          那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
        - void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
    */
    class MyLinkedList
    {
    public:
        MyLinkedList()
        {
            head = nullptr;
            tail = nullptr;
            num = 0;
        }

        int get(int index)
        {
            if (index >= num)
                return -1;
            ListNode *temp = head;
            while (index--)
            {
                temp = temp->next;
            }
            return temp->val;
        }

        void addAtHead(int val)
        {
            ListNode *node = new ListNode(val, head);
            head = node;
            if (tail == nullptr)
                tail = node;
            num++;
        }

        void addAtTail(int val)
        {
            ListNode *node = new ListNode(val);
            if (tail != nullptr)
            {
                tail->next = node;
                tail = node;
            }
            else
            {
                tail = node;
                head = node;
            }
            num++;
        }

        void addAtIndex(int index, int val)
        {
            if (index > num)
                return;
            if (index == num)
                return this->addAtTail(val);
            if (index == 0)
                return this->addAtHead(val);
            else
            {
                ListNode *node = new ListNode(val);
                ListNode *temp = head;
                while (--index)
                {
                    temp = temp->next;
                }
                node->next = temp->next;
                temp->next = node;
                num++;
            }
            return;
        }

        void deleteAtIndex(int index)
        {
            if (index >= num)
            {
                return;
            }
            ListNode *temp = head;
            if (index == 0)
            {
                head = head->next;
                delete temp;
                num--;
            }
            else
            {
                bool flag = (index == num - 1);
                while (--index)
                {
                    temp = temp->next;
                }
                if (flag)
                    tail = temp;
                ListNode *rm = temp->next;
                temp->next = rm->next;
                delete rm;
                num--;
            }

            return;
        }

    private:
        ListNode *head;
        ListNode *tail;
        int num;
    };
} // namespace leetCode707

namespace leetCode24
{
    /*
        leetCode 24. 两两交换链表中的节点

        给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
        你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

        输入：head = [1,2,3,4]
        输出：[2,1,4,3]
    */
    ListNode *swapPairs(ListNode *head)
    {
        if(head == nullptr) return nullptr;
        ListNode *hair = new ListNode(-1, head);
        ListNode *prev = hair;
        ListNode *curr = head;
        while (prev->next != nullptr && curr->next != nullptr)
        {
            ListNode *temp = curr->next;
            prev->next = temp;
            curr->next = temp->next;
            temp->next = curr;
            prev = curr;
            curr = prev->next;
        }
        return hair->next;
    }
} // namespace leetCode24

int main()
{
    // leetCode 209. 长度最小的子数组
    {
        cout << "leetCode 209. 长度最小的子数组: " << endl;
        vector<int> nums{2, 3, 1, 2, 4, 3};
        cout << leetCode209::minSubArrayLen(7, nums) << endl;
        cout << endl;
    }

    // leetCode 59. 螺旋矩阵 II
    {
        cout << "leetCode 704. 二分查找: " << endl;
        vector<vector<int>> res = leetCode59::generateMatrix(3);
        for (auto a : res)
        {
            for (auto b : a)
            {
                cout << b << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // leetCode 203. 移除链表元素
    {
        cout << "leetCode 27. 移除元素: " << endl;
        // todo
        cout << endl;
    }

    // leetCode 707.设计链表
    {
        cout << "leetCode leetCode 707.设计链表: " << endl;
        // todo
        cout << endl;
    }

    // leetCode 24. 两两交换链表中的节点
    {
        cout << "leetCode 24. 两两交换链表中的节点: " << endl;
        // todo
        cout << endl;
    }

    return 0;
}