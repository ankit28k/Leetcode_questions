class Solution {
public:

    bool found(vector<int>& arr,int tar){
        int l=0,h=arr.size()-1;
        while(l<=h){
            int m = (l+h)/2;
            if(arr[m]==tar) return true;
            else if(arr[m]>tar) h=m-1;
            else l = m+1;
        }
        return false;
    }

    bool splitArraySameAverage(vector<int>& nums) {

        long long sum=0;
        for(int x:nums) sum+=x;
        int n = nums.size();
        int n1 = n/2;
        int n2 = n-n1;

       map<int,vector<int>> mpa,mpb;
        for(int mask = 0;mask<(1LL<<n1);mask++){
            int sum=0,cnt=0;
            for(int i=0;i<n1;i++){
                if((mask>>i)&1) {
                    sum+=nums[i];
                    cnt++;
                }
            }
            mpa[cnt].push_back(sum);
        }

        for(int mask = 0;mask<(1LL<<n2);mask++){
            int sum=0,cnt=0;
            for(int i=0;i<n2;i++){
                if((mask>>i)&1) {
                    sum+=nums[i+n1];
                    cnt++;
                }
            }
            mpb[cnt].push_back(sum);
        }

        for(auto& it:mpb){
            sort(it.second.begin(),it.second.end());
        }

        for(auto it:mpa){
            int k = it.first;
            for(auto val:it.second){

                for(auto it2: mpb){
                    int k = it.first , j = it2.first;
                    int d = k+j;
                    if(k==0 || k+j==n) continue; //both 2 chosen subset must be non zero

                    if((d*sum)%n != 0) continue;
                    int req = (d*sum/n) - val;

                    if(found(it2.second,req)) return true;
                }
            }
        }

        return false;
    }
};