class Solution {
public:

    const int mod = 1e9+7;

    int fun(int i,int j,int n,int m,string& tar,vector<vector<int>>& arr,vector<vector<long long>>& dp){

        if(j==m) return 1;
        if(i==n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        long long nt = fun(i+1,j,n,m,tar,arr,dp);
        long long t = (1LL* arr[i][tar[j]-'a'] * fun(i+1,j+1,n,m,tar,arr,dp));

        return dp[i][j] = (t+nt)%mod;

    }
    int numWays(vector<string>& words, string target) {

        int n = words[0].size() , m = target.length();

        vector<vector<int>> arr(n,vector<int> (26,0));
        vector<vector<long long>> dp(n,vector<long long> (m,-1));

        for(auto it:words){
            int nt = it.length();
            for(int i=0;i<nt;i++){
                int w = it[i]-'a';
                arr[i][w]++;
            }
        }

        return fun(0,0,n,m,target,arr,dp);
        
    }
};