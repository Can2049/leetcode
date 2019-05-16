// https://leetcode.com/problems/divide-two-integers/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <climits>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (divisor == 0)
            return 0;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        long a = dividend;
        long b = divisor;
        bool isNeg = (a < 0) && (b > 0) || (a > 0) && (b < 0);
        a = abs(a);
        b = abs(b);
        int quo = 0;
        while (a >= b)
        {
            int shift = 0;
            while (a >= b << shift)
            {
                shift++;
            }
            a -= b << (shift - 1);
            quo += 1 << (shift - 1);
        }
        return isNeg ? -quo : quo;
    }
};

int main()
{
    vector<vector<int>> v;
    // v.push_back({10, 3, 3});
    // v.push_back({7, -3, -2});
    v.push_back({INT_MAX, -1, INT_MIN + 1});
    v.push_back({INT_MIN, -1, INT_MAX});
    v.push_back({INT_MIN, 1, INT_MIN});
    for (auto &i : v)
    {
        cout << i[0] << "\t/\t" << i[1] << "\t|\t" << i[2] << "\t|\t" << Solution().divide(i[0], i[1]) << endl;
    }
}