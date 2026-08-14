class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        
        int n = nums.size();
        int n1 = n/2;
        int n2 = n-n1;

        vector<int> suma,sumb;
        for(int mask = 0;mask<(1LL<<n1);mask++){
            int sum=0;
            for(int i=0;i<n1;i++){
                if((mask>>i)&1) sum+=nums[i];
            }
            suma.push_back(sum);
        }

        for(int mask = 0;mask<(1LL<<n2);mask++){
            int sum=0;
            for(int i=0;i<n2;i++){
                if((mask>>i)&1) sum+=nums[i+n1];
            }
            sumb.push_back(sum);
        }

        sort(sumb.begin(),sumb.end());
        int ans=INT_MAX;
        for(int i=0;i<(1LL<<n1);i++){
            
            int val = goal - suma[i];
            int idx = lower_bound(sumb.begin(),sumb.end(),val) - sumb.begin();
            if(idx<sumb.size()) ans = min(ans,abs(suma[i]+sumb[idx]-goal));
            if(idx>0) ans = min(ans,abs(suma[i]+sumb[idx-1]-goal));
        }

        return ans;
    }
};