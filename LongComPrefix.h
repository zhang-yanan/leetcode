class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<string>::size_type len = strs.size();
        string result;
        if(len == 0)return result;
        if(len == 1)return strs.at(0);

        std::sort(strs.begin(), strs.end());
        int i = 1;
        string::size_type len_s = strs.at(0).size();
        while(i < len)
        {
            if (strs.at(i).size()<len_s)len_s = strs.at(i).size();
            i++;
        }
        i = 0;
        while(i < len_s)
        {
            if(strs.at(0).at(i) == strs.at(len -1).at(i))
            {
                result += strs.at(0).at(i);
                i++;
            }else break;
        }
        return result;
    }
};