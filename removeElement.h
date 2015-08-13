class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())return 0;
        int count = 0;
        std::vector<int>::iterator iter = nums.begin(), iter_val = nums.begin();
        while(iter_val!=nums.end())
        {
            if(*iter_val != val)
            {
                *iter++ = *iter_val;
                count++;
            }
            iter_val++;
        }
        return count;
    }
};