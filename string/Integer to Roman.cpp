// https://leetcode.com/problems/integer-to-roman/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution
{
  public:
    string intToRoman(int num)
    {
        int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int len = sizeof(nums) / sizeof(nums[0]);
        string ans;
        for (int i = 0; i < len; i++)
        {
            for (; num >= nums[i];)
            {
                num -= nums[i];
                ans += roman[i];
            }
        }
        return ans;
    }
};

int main()
{
    map<int, string> m;
    m[3] = "III";
    m[4] = "IV";
    m[9] = "IX";
    m[58] = "LVIII";
    m[1994] = "MCMXCIV";
    m[33] = "XXXIII";
    m[123] = "CXXIII";
    m[3999] = "MMMCMXCIX";
    Solution s;
    for (auto &i : m)
    {
        cout << i.first << " | " << i.second << " | " << s.intToRoman(i.first) << endl;
    }
}