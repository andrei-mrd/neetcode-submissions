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

    void vals(TreeNode* root, map<int, int>& m){
        if(root == nullptr) {
            return;
        }

        m[root->val]+=1;

        vals(root->left, m);
        vals(root->right, m);
    }

    int kthSmallest(TreeNode* root, int k) {
        map<int, int> m;
        vals(root, m);

        int n = 1;

        for(auto& p: m) {
            if(n == k) {
                return p.first;
            }
            n +=1;
        }
    }
};
