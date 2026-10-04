class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == nullptr) {
            return result;
        }

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int lvl = q.front().second;
            q.pop();

            // daca nivelul nu exista inca, il creez
            if (result.size() == lvl) {
                result.push_back({});
            }

            // adaug valoarea pe nivelul corespunzator
            result[lvl].push_back(node->val);

            if (node->left != nullptr) {
                q.push({node->left, lvl + 1});
            }

            if (node->right != nullptr) {
                q.push({node->right, lvl + 1});
            }
        }

        return result;
    }
};