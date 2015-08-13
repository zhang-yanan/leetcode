class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int diff = 0, sum = 0, temp_diff = 0, temp_sum = 0;
        std::vector<int>::iterator iter1, iter2, iter3;
        
        if(num.size() >= 3)
        {
            std::sort(num.begin(),num.end());
            bool f1 = false;
            iter1 = num.begin();
            sum = *iter1 + *(iter1+1) + *(num.end() - 1);
            diff = abs(sum- target);
            
            for(;iter1 != num.end()-2;iter1++)
            {
                if(f1 && *iter1 == *(iter1 - 1)) {continue;}
                f1 = true;
                iter2 = iter1 + 1;
                iter3 = num.end() - 1;
                bool f2 = false, f3 = false;
                while(iter2 != iter3)
                {
                    if (f3 && *iter3 == *(iter3 + 1)){iter3--; continue;}
                    if (f2 && *iter2 == *(iter2 - 1)){iter2++; continue;}

                    temp_sum = *iter1 + *iter2 + *iter3;
                    temp_diff = temp_sum - target;
                    if (temp_diff == 0) {sum = temp_sum;break;}
                    if (abs(temp_diff)< diff) {diff = abs(temp_diff); sum = temp_sum;}
                    
                    if(temp_diff < 0){iter2++; f2 = true;}
                    if(temp_diff > 0){iter3--; f3 = true;}
                }
                    
            }
            
        }
        
        return sum ;
        
    }
};