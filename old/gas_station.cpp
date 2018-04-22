class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
     	if(gas.empty() || cost.empty() || gas.size()!=cost.size())
     	{
     		return -1;
     	}
     	for(int i=0; i<gas.size(); i++)
     	{	
     		int remain = 0;
     		int j = i;
     		do{
     			remain += gas[j];
     			remain -= cost[j];
     			j ++ ; 
     			if(remain < 0)
     			{
     				break;
     			}
     			if(j==gas.size())
     			{
     				j = 0;
     			}
     		}while(j!=i);
     		if(j==i )
     		{
     			return i;
     		}
     	}
    }
};