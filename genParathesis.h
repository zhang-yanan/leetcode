class Solution {
    void generator(std::vector<std::string> &vec, int left, int right, std::string s)
    {
        if(left  == 0 && right == 0)
        {
            vec.push_back(s);
            return;
        }
        if(left > 0)
            generator(vec,left-1,right,s+'(');
        if(right > left)
            generator(vec,left,right-1,s+')');
    }
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string s;
        if(n > 0) generator( result, n, n, s);
        return result; 
    }
};