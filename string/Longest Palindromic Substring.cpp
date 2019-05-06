// https://leetcode.com/problems/longest-palindromic-substring/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int l = expand_center(s, i, i);
            int r = expand_center(s, i, i + 1);
            // cout << "l\t" << l << "\tr\t" << r << endl;
            int len = max(l, r);
            if (len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + (len) / 2;
            }
        }
        // cout << "start\t" << start << "\tend\t" << end << endl;
        return s.substr(start, end - start + 1);
    }

  private:
    int expand_center(string &s, int left, int right)
    {
        int L = left;
        int R = right;
        while (L >= 0 && R <= s.length() && s[L] == s[R])
        {
            L--;
            R++;
        }
        return R - L - 1;
    }
};

int main()
{
    string in[] = {"aa", "babad", "cbbd", "b", "abacdfgdcaba"};
    for (auto &s : in)
    {
        string out = Solution().longestPalindrome(s);
        cout << s << "\t\t\t" << out << endl;
    }
}
