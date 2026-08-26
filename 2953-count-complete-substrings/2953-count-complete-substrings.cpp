class Solution {
public:
    int fun(string& s,int st,int end,int k){
        
        int n = end-st+1 , ans=0;
        for(int unique_char=1; unique_char*k <=n && unique_char<=26; unique_char++){

            int len = unique_char*k,l=st,r=st;
            unordered_map<char,int> mp;

            while(r<=end){
                mp[s[r]]++;

                while(l<=r && (r-l+1 > len || mp[s[r]]>k)){
                    mp[s[l]]--;
                    if(mp[s[l]] ==0) mp.erase(s[l]);
                    l++;
                }

                if(mp.size()==unique_char && r-l+1==len) ans++;
                r++;
            }
            
        }

        return ans;
    }
    int countCompleteSubstrings(string word, int k) {
        int lidx = 0,ans=0,n=word.size();
        for(int i=1;i<=n;i++){
            if(i==n || abs(word[i]-word[i-1])>2){
                ans += fun(word,lidx,i-1,k);
                lidx = i;
            }
        }
        return ans;
    }
};