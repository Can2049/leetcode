class Solution
{
  public:
    string addBinary(string a, string b)
    {
        if (a.empty() && b.empty())
        {
            return 0;
        }

        //pop last value, add them
        int aa, bb;
        int c = 0;
        string ans;
        while (!a.empty() && !b.empty())
        {
            aa = a.back() - '0';
            a.pop_back();
            bb = b.back() - '0';
            b.pop_back();
            c += aa + bb;
            ans += to_string(c % 10);
            c /= 10;
        }
        while (!a.empty())
        {
            aa = a.back() - '0';
            a.pop_back();
            c += aa;
            ans += to_string(c % 10);
            c /= 10;
        }
        while (!b.empty())
        {
            bb = b.back() - '0';
            b.pop_back();
            c += bb;
            ans += to_string(c % 10);
            c /= 10;
        }
        if (c)
        {
            ans += to_string(c);
        }
        return ans;
    }
};