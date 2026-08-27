class Solution {
public:

    bool ispal(string& s,int l,int r){
        while(l<r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void fun(int idx,string& s,vector<string>& temp,vector<vector<string>>& ans){

        if(idx ==s.length()){
            ans.push_back(temp);
            return;
        }

        int n = s.length();
        for(int i=idx;i<n;i++){
            if(ispal(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                fun(i+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        fun(0,s,temp,ans);
        return ans;
    }
};