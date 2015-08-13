class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        std::vector<int>pair(3,-1);
        std::vector<int>::iterator iter1, iter2, iter3;
        std::vector<std::vector<int> >result;
        
        if (num.size() >= 3)
        {
            std::sort(num.begin(),num.end());
            iter1 = num.begin();
            bool f1 = false;
            for(;iter1!=num.end()-2;iter1++)
            {
                if(f1 && *iter1 == *(iter1 - 1)){continue;}
                f1 = true;
                iter2 = iter1+1;
                iter3 = num.end()-1;
                bool f2 = false, f3=false;
                while(iter2 != iter3)
                {
                    if(f3 && *iter3 == *(iter3 + 1)){iter3--; continue;}
                    if(f2 && *iter2 == *(iter2 - 1)){iter2++; continue;}
                    int sum = *iter1 + *iter2 + *iter3;
                    if (sum == 0)
                    {
                        pair[0] = *iter1;
                        pair[1] = *iter2;
                        pair[2] = *iter3;
                        result.push_back(pair);
                    }
                    if (sum > 0)
                    {
                        iter3--;
                        f3 = true;
                    }else{
                        iter2++;
                        f2 = true;
                    }
                }
            }
        }
        return result;
    }

};