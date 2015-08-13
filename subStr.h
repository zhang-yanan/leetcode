class Solution {
    void getNext(std::string s, int *next)
    {
        int i = 0, j = -1;
        next[i] = j;
        while(i < s.size())
        {
            if(j == -1 || s[j] == s[i])
            {
                i++;
                j++;
                if(s[i] == s[j])
                    next[i] = next[j];
                else
                    next[i] = j;
            }else
                j = next[j];
        }
    }
public:
    int strStr(string haystack, string needle) {
        int haylen = haystack.size(), nlen = needle.size();
        if(haylen < nlen)return -1;
        if( nlen == 0)return 0;
        int i = 0, j = 0;
        int next[nlen];
        getNext(needle, next);
        while(i < haylen && j < nlen)
        {
            if(j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }else
                j = next[j];
        }
        if(j >= nlen)
            return i - nlen;
        else
            return -1;  
    }
};