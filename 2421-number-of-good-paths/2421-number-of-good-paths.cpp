class dsu{
public:
    vector<int> par,size;
    dsu(int n){
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) par[i]=i;
    }

    int fup(int n){
        if(par[n]==n) return n;
        return par[n] = fup(par[n]);
    }

    void ubs(int u,int v){
        int upu = fup(u),upv = fup(v);
        if(upu==upv) return;

        if(size[upu]>=size[upv]){
            size[upu] += size[upv];
            par[upv] = upu;
        }

        else {
            size[upv] += size[upu];
            par[upu] = upv;
        }
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {

        int n = vals.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++) {
            mp[vals[i]].push_back(i);
        }

        dsu ds(n);
        vector<vector<int>> gr(n);
        for(auto it:edges){
            int a = it[0],b = it[1];
            gr[a].push_back(b);
            gr[b].push_back(a);
        }

        vector<bool> active(n,false);

        int ans=0;

        for(auto it:mp){
            vector<int>& temp = it.second;

            for(int x:temp){
                for(int cx:gr[x]){
                    if(active[cx]) ds.ubs(cx,x);
                }
                active[x] = true;
            }

            unordered_map<int,int> par_sz;
            for(int x:temp){
                int par = ds.fup(x);
                par_sz[par]++;
            }

            for(auto it2:par_sz){
                int val = it2.second;
                if(val>1) ans+= val*(val-1)/2;
            }
        }

        return ans + n;

    }
};