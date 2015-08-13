class Solution {
public:
    int reverse(int x) {
        
        if(overflow(x)) return 0;
        
        bool sign = false;
        int temp = 0, result = 0;
        
        if(x > 0) sign = true;
        temp = abs(x);
        while(temp != 0)
        {
            result = result * 10 + temp % 10;
            temp = temp/10;
        }
        if (result < 0) return 0;
        if (sign)
            return result;
        else
            return -result;
    }
private:
    bool overflow(int x)
    {
        if (x == INT_MIN)return true;
        x = abs(x);
        int contr = 1000000000;
        if (x/contr == 0) return false;
        else
            if(x % 10 < 2) return false;
        else if(x % 10  ==2)
        {
            int temp = x;
            int compare = INT_MAX;
            bool flag = false;
            while(compare != 0)
            {
                if (temp%10 > compare/contr && !flag ) return true;
                if(temp%10 < compare/contr) flag = true;
                temp /= 10;
                compare %= contr;
                contr /= 10;
            }
            return false;
        }
        return true;

    }
};