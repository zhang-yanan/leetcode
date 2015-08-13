class Solution {
public:
    int getKthNum(std::vector<int>::iterator start1, int m, std::vector<int>::iterator start2, int n, int k)
    {
        if (m > n) return getKthNum(start2, n, start1, m, k);
        if(m == 0 && n > 0) return *(start2+k-1);
        if (k == 1) return (*start1 < *start2?*start1:*start2);
        
        int i = m<(k/2)?m:(k/2);
        int j = k - i;
        
        if(*(start1+i-1) < *(start2+j-1))
            return getKthNum(start1+i, m-i, start2, n, k-i);
        else
            return getKthNum(start1, m, start2+j, n-j,k-j);

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int>::size_type size1 = 0, size2 = 0;
        size1 = nums1.size();
        size2 = nums2.size();
        if (size1 ==0 && size2 ==0)return -1;
        
        if ((size1 + size2) % 2 == 0)
            return (getKthNum(nums1.begin(),size1,nums2.begin(),size2, (size1+size2)/2) + getKthNum(nums1.begin(),size1,nums2.begin(), size2, (size1+size2)/2+1))/2.0;
        else
            return getKthNum(nums1.begin(),size1, nums2.begin(),size2,(size1+size2)/2+1)/1.0;
        
    }
};