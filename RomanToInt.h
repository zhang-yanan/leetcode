class Solution {
    int converse(char c)
    {
        switch (c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
public:
    int romanToInt(string s) {
        string::size_type len = s.size();
        if(len == 0)return 0;
        int i = len - 1, result = 0, cur = 0, last = 0;
        while(i != -1)
        {
            cur = converse(s.at(i));
            if(cur < last)result -= cur;
            else result += cur;
            i--;
            last = cur;
        }
        return result;
    }
};