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
        map<int,TreeNode*> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty()){
            auto t =q.front();
            q.pop();

            auto node = t.first;
            int x = t.second;
            if(mp.find(x) == mp.end()){
                mp[x] = node;
            }
            if(node->right) q.push({node->right,x+1});
            if(node->left) q.push({node->left,x+1});
        }

        vector<int> ans;
        for(auto it:mp){
            ans.push_back(it.second->val);
        }
        return ans;
    }
};