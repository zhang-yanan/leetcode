class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::vector<std::string>result, temp_result;
        std::string temp_s;
        if(digits.size() == 0)return result;
        std::string str[] = {""," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i = 0; i< digits.size(); i++)
        {
            std::string::size_type len_s = str[digits.at(i)-'0'].size();
            std::vector<std::string>::size_type len_v = result.size();
            temp_result = result;
            for(int j = 0; j< len_s; j++)
            {
                int temp_len_v = len_v;
                if(len_v == 0)
                {
                    temp_s += str[digits.at(i)-'0'].at(j);
                    result.push_back(temp_s);
                    temp_s.clear();
                }else{
                    if(j != len_s-1)
                    {
                        result.insert(result.end(), temp_result.begin(), temp_result.end());
                    }
                    while(temp_len_v > 0)
                    {
                        result.at(j*len_v+temp_len_v -1) += str[digits.at(i)-'0'].at(j);
                        temp_len_v--;
                    }
                }
            }
        }
        return result;
    }
};