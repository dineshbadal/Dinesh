// hard 3640
class Solution {
public:
    typedef long long ll;
    vector<int> nums;
    static constexpr long long NEG_INF = -1000000000000000000LL; // -1e18
   // vector<vector<int>>t(4,vector<int>( n+1,-1));//
    int n = nums.size();
    ll solve(int i, int trend ,vector<vector<ll>>&t) {
        // Base case will there
        if (i >= n) {
            if (trend == 3) {
                return 0;
            } else {
                return NEG_INF / 2;
            }
          }
         if(t[trend][i]!=NEG_INF){
            return t[trend][i];
        }
        ll take = NEG_INF / 2;
        ll skip = NEG_INF / 2;
        if (trend == 0) {
            skip = solve(i + 1, 0,t);
        }
        if (trend == 3) {
            take = nums[i];
        }
         if(i+1 < n) {
            int curr = nums[i];
            int next = nums[i+1];

            if(trend == 0 && next > curr) {
                take = max(take, curr + solve(i+1, 1,t));
            } else if(trend == 1) {
                if(next > curr) {
                    take = max(take, curr + solve(i+1, 1,t));
                } else if(next < curr) {
                    take = max(take, curr + solve(i+1, 2,t));
                }
            } else if(trend == 2) {
                if(next < curr) {
                    take = max(take, curr + solve(i+1, 2,t));
                } else if(next > curr) {
                    take = max(take, curr + solve(i+1, 3,t) );
                }
            } else if(trend == 3 && next > curr) {
                take = max(take, curr + solve(i+1, 3,t));
            }
        }
        
        return  t[trend][i]=max(take, skip);
    }
    ll maxSumTrionic(vector<int>& num) {
        nums = num;
        vector<vector<ll>>t;
        n = nums.size();
        t.assign(4,vector<ll>(n+1,NEG_INF));
        ll ans = solve(0, 0,t);
        return ans < -1e17 ? 0 : ans;
    }
};
