// https://leetcode.com/problems/generate-parentheses/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution
{
public:
    vector<string> ans;
    int N;

    vector<string> generateParenthesis(int n)
    {
        vector<string> out;
        out.clear();
        if (n <= 0)
            out.push_back("");
        N = n;
        for (int i = 0; i < n; ++i)
        {
            for (auto &l : generateParenthesis(i))
                for (auto &r : generateParenthesis(n - i - 1))
                    out.push_back(l + "(" + r + ")");
        }
        return out;
    }

    vector<string> generateParenthesis2(int n)
    {
        N = n;
        ans.clear();
        backtrack("", 0, 0);
        return ans;
    }
    void backtrack(string s, int left, int right)
    {
        if (s.size() == 2 * N)
        {
            ans.push_back(s);
            return;
        }
        if (left < N)
            backtrack(s + "(", left + 1, right);
        if (right < left)
            backtrack(s + ")", left, right + 1);
    }
};

void show(vector<string> v)
{
    cout << "------------" << endl;
    for (auto &i : v)
    {
        cout << i << endl;
    }
}

int main()
{
    for (int i = 1; i < 5; i++)
    {
        auto out = Solution().generateParenthesis(i);
        cout << "input: " << i << endl;
        show(out);
    }
}