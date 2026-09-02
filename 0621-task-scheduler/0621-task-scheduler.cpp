class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> fq(26,0);
        for(char c:tasks) fq[c-'A']++;

        multiset<int> pq;
        for(int i=0;i<26;i++){
            if(fq[i]>0) pq.insert(fq[i]);
        }

        int ans=0;
        while(!pq.empty()){
            vector<int> temp;

            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int curr = *(pq.rbegin());
                    pq.erase(pq.find(curr));
                    curr--;
                    temp.push_back(curr);
                }
            }
            for(int x:temp) {
                if(x>0) pq.insert(x);
            }

            if(pq.empty()) ans+= temp.size();
            else ans += n+1;

        }
        return ans;
    }
};