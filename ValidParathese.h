class Solution {
    bool isMatch(char a, char b)
    {
        return ((a == '(' && b == ')' )|| (a == '[' && b ==']')|| (a == '{' && b == '}'));
    }
public:
    bool isValid(string s) {
        vector<char> mystack;
        if((s.size()&1) != 0 || s.size() == 0)return false;
        mystack.push_back(s.at(0));
        for(int i = 1; i<s.size();i++)
        {
            if(isMatch(mystack.back(), s.at(i)))
                mystack.pop_back();
            else
                mystack.push_back(s.at(i));
        }
        if(mystack.size() == 0)
            return true;
        else
            return false; 
    }
};