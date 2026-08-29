class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        unordered_set<string> st(bank.begin(),bank.end()) , vis;

        queue<pair<string ,int>> q;

        vector<char> mv = {'A','C','G','T'};
        q.push({startGene,0});
        vis.insert(startGene);

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            string curr = top.first;
            int curr_level = top.second , csz = curr.size();

            if(curr == endGene) return curr_level;

            for(int i=0;i<csz;i++){
                for(char c:mv){
                    if(curr[i] != c){
                        string next = curr;
                        next[i] = c;
                        if(st.find(next) != st.end() && vis.find(next)==vis.end()){
                            q.push({next,curr_level+1});
                            vis.insert(next);
                        }
                    }
                }
            }
        }

        return -1;
    }
};