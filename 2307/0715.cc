#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <deque>
#include <algorithm>

using namespace std;

namespace leetCode242
{
    /*
        leetCode 242. 有效的字母异位词

        给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
        注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

        输入: s = "anagram", t = "nagaram"
        输出: true
    */
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        vector<int> table(26, 0);
        for (auto &ch : s)
        {
            table[ch - 'a']++;
        }
        for (auto &ch : t)
        {
            table[ch - 'a']--;
            if (table[ch - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }

} // namespace leetCode242

namespace leetCode71
{
    /*
        leetCode 71. 简化路径

        给你一个字符串 path ，表示指向某一文件或目录的Unix风格绝对路径 （以 '/' 开头），
        请你将其转化为更加简洁的规范路径。

        输入：path = "/a/./b/../../c/"
        输出："/c"
    */
    string simplifyPath(string path)
    {
        deque<string> st;
        int n = path.size(), i = 0;
        while (i < n)
        {
            if (i < n && path[i] == '/')
                i++;
            else
            {
                string temp;
                while (i < n && path[i] != '/')
                    temp += path[i++];
                if (temp == ".." && !st.empty())
                    st.pop_back();
                else if (temp != ".." && temp != ".")
                    st.push_back(temp);
            }
        }
        string res = "/";
        while (!st.empty())
        {
            res += st.front() + "/";
            st.pop_front();
        }
        if (res.size() > 1)
            res.pop_back();
        return res;
    }
} // namespace leetCode71

namespace leetCode75
{
    /*
        leetCode 75. 颜色分类
        给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，
        使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
        我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
        必须在不使用库内置的 sort 函数的情况下解决这个问题。

        输入：nums = [2,0,2,1,1,0]
        输出：[0,0,1,1,2,2]
    */
    void sortColors(vector<int> &nums)
    {
        quick_sort(nums, 0, nums.size());
    }
    void quick_sort(vector<int> &nums, int l, int r)
    {
        if (l + 1 >= r)
        {
            return;
        }
        int first = l, last = r - 1, key = nums[first];
        while (first < last)
        {
            while (first < last && nums[last] >= key)
            {
                --last;
            }
            nums[first] = nums[last];
            while (first < last && nums[first] <= key)
            {
                ++first;
            }
            nums[last] = nums[first];
        }
        nums[first] = key;
        quick_sort(nums, l, first);
        quick_sort(nums, first + 1, r);
    }
} // namespace leetCode75

int main()
{

    // leetCode 242. 有效的字母异位词
    {
        cout << "leetCode 242. 有效的字母异位词: " << endl;
        string s1 = "hello";
        string s2 = "olleh";
        cout << leetCode242::isAnagram(s1, s2) << endl;
        cout << endl;
    }

    // leetCode 71. 简化路径
    {
        cout << "leetCode 71. 简化路径: " << endl;
        cout << leetCode71::simplifyPath("/a/./b/../../c/") << endl;
        cout << endl;
    }

    // leetCode 75. 颜色分类
    {
        cout << "leetCode 75. 颜色分类: " << endl;
        vector<int> nums{2, 0, 2, 1, 1, 0};
        leetCode75::sortColors(nums);
        for (int i : nums)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}