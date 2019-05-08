// https://leetcode.com/problems/string-to-integer-atoi/

#include <iostream>
#include <string>
#include <map>
#include <cctype>  //isdigit
#include <climits> //INT_MAX INT_MIN
using namespace std;

class Solution
{
  public:
    int myAtoi(string str)
    {
        if (str.empty())
            return 0;
        int start = 0;
        while (str[start] == ' ')
            start++;
        int flag = 1;
        if (str[start] == '-')
        {
            flag = -1;
            start++;
        }
        else if (str[start] == '+')
        {
            start++;
        }
        if (start >= str.length() | !isdigit(str[start]))
            return 0;
        int end = start;
        while (end < str.length() && isdigit(str[end]))
            end++;
        long long ans = 0;
        int digit_max = digits(INT_MAX);
        for (int i = start; i < end; i++)
        {
            if (digits(ans) > digit_max)
            {
                if (flag > 0)
                    return INT_MAX;
                if (flag < 0)
                    return INT_MIN;
            }
            ans = ans * 10 + str[i] - '0';
        }
        ans *= flag;
        if (ans < INT_MIN)
            return INT_MIN;
        if (ans > INT_MAX)
            return INT_MAX;
        return ans;
    }

    int digits(long long in)
    {
        int ans;
        for (ans = 0; in > 0; ans++)
        {
            in /= 10;
        }
        return ans;
    }
};

int main()
{
    map<string, int> m;
    m["42"] = 42;
    m["   -42"] = -42;
    m["4193 with words"] = 4193;
    m["words and 987"] = 0;
    m["-91283472332"] = -2147483648;
    m["99999999999999"] = INT_MAX;
    m["20000000000000000000"] = INT_MAX;
    cout << "int min " << INT_MIN << endl;
    cout << "int max " << INT_MAX << endl;
    cout << "* int max digits " << Solution().digits(INT_MAX) << endl;
    for (auto &s : m)
    {
        int out = Solution().myAtoi(s.first);
        cout << s.first << "  |  " << s.second << "  |  " << out << endl;
    }
}
