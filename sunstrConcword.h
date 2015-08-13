class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::vector<int>result;
        std::vector<std::string>::iterator iter = words.begin();
        std::string::size_type index = 0, len = (*iter).size(), window_size = words.size()*len;
        if(s.size() == 0 || window_size == 0) return result;
        if(window_size > s.size())return result;
        std::map<std::string,int>words_count, words_found;
        while( iter!= words.end())
        {
            words_count[*iter++]++;
        }
        while(index <= s.size() - window_size)
        {
            std::string::size_type cur_window =0;
            bool flag = true;
            while(flag && cur_window < window_size)
            {
                std::string sub_s = s.substr(index+cur_window, len);
                std::map<std::string, int>::iterator map_it = words_count.find(sub_s);
                if(map_it != words_count.end())
                {
                    if(++words_found[sub_s]>words_count[sub_s])
                        flag = false;
                    else cur_window += len;
                }else flag = false;
            }
            if(flag && cur_window >= window_size)result.push_back((int)index);
            index++;
            words_found.erase(words_found.begin(), words_found.end());
        }
        return result;        
    }
};