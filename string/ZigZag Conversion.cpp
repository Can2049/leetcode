// https://leetcode.com/problems/zigzag-conversion/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    string convert(string s, int numRows)
    {
        if (numRows <= 1)
            return s;
        string ans;
        int len = s.length();
        int cycle = 2 * numRows - 2;
        for (int r = 0; r < numRows; r++)
        {
            int d1 = 2 * numRows - 2 * r - 2;
            for (int i = r; i < len; i += cycle)
            {
                ans += s[i];
                if (d1 > 0 && i + d1 < len && d1 < cycle)
                    ans += s[i + d1];
            }
        }
        return ans;
    }
};

int main()
{
    string in[] = {"PAYPALISHIRING"};
    int mode[] = {3, 4};
    string ans[] = {"PAHNAPLSIIGYIR", "PINALSIGYAHRPI"};
    map<string, rows> m;
    m['PAYPALISHIRING'] = 3;
    m['PAYPALISHIRING'] = 4;
    m['A'] = 1;
    int i = 0;
    for (auto &s : in)
        for (auto m : mode)
        {
            string out = Solution().convert(s, m);
            cout << s << "\t" << m << "\t" << out << endl;
        }
}