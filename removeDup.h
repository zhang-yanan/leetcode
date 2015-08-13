class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.begin() == nums.end())return 0;
        if(nums.size() == 1) return 1;
        int count = 1;
        vector<int>::iterator iter, iter_h = nums.begin(), iter_r = nums.begin()+1;
        while(iter_r != nums.end() && *iter_h != *iter_r)
        {
            iter_h++;
            iter_r++;
            count++;
        }
        while(iter_r != nums.end() && *iter_h == *iter_r) iter_r++;
        if(iter_r == nums.end())return count;
        iter_h++;
        while(iter_r != nums.end())
        {
            iter = iter_r+1;
            while(iter != nums.end() && *iter == *iter_r) iter++;
            *iter_h++ = *iter_r;
            count++;
            iter_r = iter;
        }
        return count;  
    }
};