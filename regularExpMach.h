class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.size() == 0) return (s.size() == 0);
        if (p.size() == 1) return (s.size() == 1 &&(s.at(0) == p.at(0) ||p.at(0) == '.'));
        if (p.at(1) == '*')
        {
            if(isMatch(s, p.substr(2)))
                return true;
            return s.size() > 0
                && (p.at(0)==s.at(0) || p.at(0) == '.')
                && isMatch(s.substr(1), p);
            
        }else
            return s.size() > 0
            && (p.at(0) == s.at(0) || p.at(0) == '.')
            && isMatch(s.substr(1), p.substr(1));
    }
};