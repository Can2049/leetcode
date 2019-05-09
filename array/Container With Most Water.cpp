// https://leetcode.com/problems/container-with-most-water/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int maxarea = 0;
        int start = 0;
        int end = height.size() - 1;
        for (; start < end;)
        {
            int shorter = height[start] < height[end] ? height[start] : height[end];
            int area = shorter * (end - start);
            maxarea = maxarea > area ? maxarea : area;
            if (height[start] < height[end])
                start++;
            else
                end--;
        }
        return maxarea;
    }
};

void show(vector<int> in)
{
    for (auto &i : in)
    {
        cout << i << " ";
    }
}

int main()
{
    map<vector<int>, int> m;
    m[vector<int>({1, 8, 6, 2, 5, 4, 8, 3, 7})] = 49;
    m[vector<int>({1, 2, 4, 3})] = 4;
    for (auto &i : m)
    {
        vector<int> in(i.first.begin(), i.first.end());
        int out = Solution().maxArea(in);
        show(i.first);
        cout << "  |  " << i.second << "  |  " << out << endl;
    }
}