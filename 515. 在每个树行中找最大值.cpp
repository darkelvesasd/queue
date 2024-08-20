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
vector<int> largestValues(TreeNode* root) {
    queue<TreeNode*> q;
    vector<int>r;
    if (!root)
    {
        return {};
    }
    q.emplace(root);
    while (!q.empty())
    {
        int mx = INT_MIN;
        int sz = q.size();
        for (int i=0;i<sz;i++)
        {
            TreeNode* t = q.front();
            q.pop();
            mx = max(mx,t->val);
            if (t->left)
            {
                q.emplace(t->left);
            }
            if (t->right)
            {
                q.emplace(t->right);
            }
        }
        r.emplace_back(mx);
    }
    return r;
}
};
