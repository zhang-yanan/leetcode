class Solution {
public:
    bool isPalindrome(int x) {
        //if(x <= INT_MIN || x >= INT_MAX)return false;
        //x = abs(x);
        if( x < 0 )return false;
        if( x < 10 )return true;
        int l_contr = 1000000000, r_contr = 10, bits = 10;
        while(x/l_contr == 0)
        {
            bits--;
            l_contr /= 10;
        }
        for(int i = 0; i< bits/2; i++)
        {
            int left = x/l_contr;
            int right = x%r_contr;
            if(left!=right) return false;
            x %= l_contr;
            x /= r_contr;
            l_contr /= 10*10;
        }
        return true;
    }
};