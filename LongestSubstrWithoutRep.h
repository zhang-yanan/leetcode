class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        char ch;
        std::string::size_type size_t, pos = 0, idx = 0, num_temp=0, result=0;
        std::string sub_s;
        
        if (s.size() == 0) return 0;
        
        size_t = s.size();
        for(; idx<size_t; idx++)
        {
            ch = s.at(idx);
            pos = sub_s.find(ch);
            if(pos == std::string::npos)
            {
                sub_s += ch;
                num_temp++;
            }
            else{
                sub_s = sub_s.substr(pos+1);
                if(num_temp > result) result = num_temp;
                num_temp -= (pos+1);
                sub_s += ch;
                num_temp++;
            }
        }
        return int((result>num_temp)?result:num_temp);
    }
};