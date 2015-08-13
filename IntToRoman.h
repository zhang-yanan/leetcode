class Solution {
    std::string converse(int n, int bits)
    {
        std::string s;
        if(n == 0) return s;
        char roman1[4] = {'I','X','C','M'};
        char roman5[4] = {'V','L','D',' '};
        if(n == 4)
        {
            s += roman1[bits - 1];
            s += roman5[bits - 1];
        }
        else if(n == 9)
        {
            s += roman1[bits - 1];
            s += roman1[bits];
        }
        else
        {
            if (n >= 5)
            {
                s += roman5[bits - 1];
                n -= 5;
            }
            while(n != 0)
            {
                s += roman1[bits - 1];
                n--;
            }
        }
        
        return s;
    }
public:
    string intToRoman(int num) {
        std::string result;
        if (num > 3999 || num < 1) return result;
        int contr = 1000, bits = 4;
        while(num != 0)
        {
            result += converse(num/contr, bits);
            num %= contr;
            contr /= 10;
            bits--;
        }
        return result;  
    }
};