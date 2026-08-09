/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        if(root==NULL) return {};

        //TC-> O(nlogn) , SC->(n)
        // map<int,TreeNode*> mp;
        // queue<pair<TreeNode*,int>> q;
        // q.push({root,0});

        // while(!q.empty()){
        //     auto t =q.front();
        //     q.pop();

        //     auto node = t.first;
        //     int x = t.second;
        //     if(mp.find(x) == mp.end()){
        //         mp[x] = node;
        //     }
        //     if(node->right) q.push({node->right,x+1});
        //     if(node->left) q.push({node->left,x+1});
        // }

        // vector<int> ans;
        // for(auto it:mp){
        //     ans.push_back(it.second->val);
        // }
        // return ans;
        
        //TC-> O(N) , SC->(n)
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;

        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto t =q.front();
                q.pop();

                if(i==0) ans.push_back(t->val);

                if(t->right) q.push(t->right);
                if(t->left) q.push(t->left);
            }
            
        }

        return ans;
    }
};