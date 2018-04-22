// https://leetcode.com/problems/search-insert-position/description/
//this method consume more time
//this method is more quick
//https://leetcode.com/problems/search-insert-position/discuss/15080/My-8-line-Java-solution
class Solution {
    public int searchInsert(int[] nums, int target) {
        int i = 0;
        for (; i < nums.length; i++) {
            if (target <= nums[i]) {
                return i;
            }
        }
        return i;
    }
}