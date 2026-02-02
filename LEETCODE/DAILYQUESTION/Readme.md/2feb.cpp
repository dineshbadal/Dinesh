//https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/
class Solution {
public:
   typedef pair<int,int> P;  // { nums[i], index }
   typedef long long ll ;
  ll minimumCost(vector<int>& nums, int k, int dist) {
          int n= nums.size();
          set<P>kmini;
          set<P>remain;
          ll sum =0 ;
          int i=1;
          while( i - dist < 1){
            kmini.insert({nums[i],i}); 
            sum+=nums[i];
            if(kmini.size()>k-1){
                 P temp = *kmini.rbegin();
                 sum-=temp.first;
                 remain.insert(temp);
                 kmini.erase(temp);
            }
            i++;
          }
          ll result=LONG_MAX;
          while(i<n){
              kmini.insert({nums[i],i});
              sum+=nums[i];
                if(kmini.size()>k-1){
                 P temp = *kmini.rbegin();
                 sum-=temp.first;
                 remain.insert(temp);
                 kmini.erase(temp);
            }
            // now 
            result=min(result,sum);
            // remove the element 
            P remove = {nums[i-dist],i-dist};
            if(kmini.count(remove)){
                kmini.erase(remove);
                sum-=remove.first;
                if(!remain.empty()){
                    P temp = *remain.begin();
                    kmini.insert(temp);
                    sum+=temp.first;
                    remain.erase(temp);
                }
            }
            else {
                remain.erase(remove);
            }
            i++;
          }
       
         return nums[0]+result;
        
    }
};
