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
    int findcroot(int l,int val,vector<int>& inorder){
        int n = inorder.size();
        for(int i=l;i<n;i++){
            if(inorder[i]==val) return i;
        }
        return -1;

    }
    TreeNode* fun(int l,int r,int& idx,vector<int>& preorder, vector<int>& inorder){

        if(l>r)  return NULL;

        int croot = preorder[idx];
        int i = findcroot(l,croot,inorder);
        
        idx++;
        TreeNode* lf = fun(l,i-1,idx,preorder,inorder);
        TreeNode* rt = fun(i+1,r,idx,preorder,inorder);

        TreeNode* curr = new TreeNode(croot);
        curr->left = lf;
        curr->right = rt;
        return curr;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int idx=0;
        return fun(0,n-1,idx,preorder,inorder);
    }
};