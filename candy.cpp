class Solution {
public:
    int candy(vector<int>& ratings) {
        unsigned int  len = ratings.size();
        vector<int> left2right(len, 1);
        vector<int> right2left(len, 1);
        for(int i=0; i<len-1; i++)
        {
            left2right[i+1] = ratings[i+1] > ratings[i] ? left2right[i] +1 : left2right[i];
        }
        for(int i=len-1; i>=0; i++)
        {
            right2left[i-1] = ratings[i-1] > ratings[i] ? right2left[i] +1 : right2left[i];
        }
        int sum = 0;
        for(int i=0; i<len; i++)
        {
            sum += max(left2right[i], right2left[i]);
        }
        return sum ;
    }

    void show (vector a)
    {
        for(int i=0; i<a.size(); i++)
        {
            cout<<a<<" ";
        }
        cout<<endl;
    }
};