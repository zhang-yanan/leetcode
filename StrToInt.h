class Solution {
public:
    int myAtoi(string str) {
                int result = 0, i = 0;
        std::string::size_type sizen = str.size();
        if(sizen == 0)return result;
        bool sign = false;
        while(str.at(i) == ' ')
        {
            i++;
            if(sizen == i)return result;
        }
        if(str.at(i) == '+')
        {
            sign = true;
            i++;
        }
        else if(str.at(i) - '0' < 10 && str.at(i) - '0' >= 0)
                sign = true;
        else if (str.at(i) == '-')
            i++;
        else
            return result;
        int bits = 0;
        while(i<sizen)
        {
            if(str.at(i) - '0' < 10 && str.at(i) - '0' >= 0)
            {
                if(bits == 9)
                {
                    if(sizen - i > 1 && str.at(i+1)- '0' < 10 && str.at(i+1) - '0' >= 0)
                        return sign?INT_MAX:INT_MIN;
                    if (result < INT_MAX/10)
                    {
                        result = result*10 + (str.at(i)-'0');
                        return sign?result:-result;
                    }
                    else if(result == INT_MAX/10)
                        {
                            if(str.at(i) - '0' < 8)
                            {
                                result = result*10 + (str.at(i)-'0');
                                return sign?result:-result;
                            }
                            else if(str.at(i) - '0' >= 8)
                                return sign?INT_MAX:INT_MIN;
                        }
                    else 
                       return sign?INT_MAX:INT_MIN;
                }
                else
                    result = result*10 + (str.at(i)-'0');
            }
            else
                return sign?result:-result;
            i++;
            bits++;
        }
        return sign?result:-result;
        
    }
};