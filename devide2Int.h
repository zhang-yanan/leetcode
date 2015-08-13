class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor ==0 || dividend == 0)return 0;
        unsigned int divd = dividend < 0 ? -dividend : dividend;
        unsigned int divs = divisor < 0 ? -divisor : divisor;
        bool sign1 = dividend < 0 ? false : true;
        bool sign2 = divisor < 0 ? false: true;
        unsigned int count = 0, temp_res =1, temp_divs = 0;
        int result = 0;
        while(divs < divd)
        {
            temp_divs = divs;
            if(temp_divs<<1 >=divd)
            {
                divd -= divs;
                divs = divisor < 0 ? -divisor : divisor;
                count += temp_res;
                temp_res = 1;
            }else{
                divs = divs <<1;
                temp_res = temp_res<<1;
            }
        }
        if(divs == divd) count++;
        if(sign1^sign2)
        {
            if(count > INT_MAX)result = INT_MIN;
            else result = -count;

        }else{
            if(count > INT_MAX)result = INT_MAX;
            else result = count;
        }
        return result;
    }
};