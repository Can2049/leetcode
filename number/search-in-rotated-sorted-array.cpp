// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return -1;
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] <= nums[high])
            { //Right half is sorted
                if (target > nums[mid] && target <= nums[high])
                {
                    low = mid + 1; //search in right sorted array
                }
                else
                {
                    high = mid - 1; //go left
                }
            }
            else if (nums[mid] >= nums[low])
            { //left half is sorted
                if (target >= nums[low] && target < nums[mid])
                {
                    high = mid - 1; //search in left sorted array
                }
                else
                {
                    low = mid + 1; //go right
                }
            }
        }
        return -1;
    }

    int search2(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int &t = target;
        while (l <= r)
        {
            if (nums[l] == t)
                return l;
            if (nums[r] == t)
                return r;
            int mid = (l + r) / 2;
            if (nums[mid] == t)
                return mid;
            if (nums[l] < t && nums[mid] > t && r != mid)
                r = mid;
            else if (nums[mid] < t && nums[r] > t && l != mid)
                l = mid;
            else if (nums[l] < t && nums[mid] < t)
                r--;
            else
                l++;
        }
        return -1;
    }
};

void show(const vector<int> &in)
{
    for (auto i : in)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<int> input({4, 5, 6, 7, 0, 1, 2});
    vector<int> num({4, 5, 6, 7, 0, 1, 2, -1, 3, 8});
    for (auto &n : num)
    {
        show(input);
        int out = Solution().search(input, n);
        cout << " | " << n << " | " << out << endl;
    }
}
