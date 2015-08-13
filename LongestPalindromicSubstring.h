class Solution {
public:
    string longestPalindrome(string s) {
        std::string temp1, temp2, result;
        int num=0, max_num1=0, max_num2 = 0;
        std::string::size_type sizen = s.size();
        
        if (sizen == 0) return result;
        if (sizen == 1) return s;
        
        for(int i=0; i < sizen; i++)
        {
            int k = i, j=i+1;
            while(k>=0 && j< sizen && s.at(k) == s.at(j))
            {
                num += 2;
                k--;
                j++;
            }
            if (num > max_num1)
            {
                max_num1 = num;
                temp1 = s.substr(k+1, max_num1);
            }
            num = 0;
        }
        for(int i=1; i < sizen; i++)
        {
            int j = i+1, k = i-1;
            while(k>=0 && j< sizen && s.at(k) == s.at(j))
            {
                num += 2;
                k--;
                j++;
            }
            if (num > max_num2)
            {
                max_num2 = num +1;
                temp2 = s.substr(k+1, max_num2);
            }
            num =  0;
        }
        if(max_num1 >  max_num2)result = temp1;
        else
            result = temp2;
        return result;
    }
};