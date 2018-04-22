class Solution {
public:
    int jump(vector<int>& nums) {
        int cur = 0;   //current can reach
        int next  = 0;  // next can reach
        int steps = 0;
        int i = 0; //index stand 

        while(i<nums.size())
        {
        	if(cur >= nums.size()-1)
        	{
        		//current jump can reach
        		break;
        	}
        	
        }

        return steps ;
    }
};