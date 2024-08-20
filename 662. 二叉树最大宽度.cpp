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
int widthOfBinaryTree(TreeNode* root) {
    if (!root)
    {
        return 0;
    }
    queue<pair<TreeNode*,unsigned long long >>q;
    unsigned long long len = 0;
    q.emplace(root,0);
    unsigned long long mn = 0;
    unsigned long long mx = 0;
    while (!q.empty())
    {       
        int sz = q.size();
        mn = q.front().second;
        for (int i=0;i<sz;i++)
        {
            pair<TreeNode*, unsigned long long > t = q.front();
            q.pop();
            if (t.first->left)
            {
                q.emplace(t.first->left,t.second*2+1);
            }
            if (t.first->right)
            {
                q.emplace(t.first->right, t.second * 2 + 2);
            }
            if (i == sz - 1)
            {
                mx = t.second;
            }
        }
        len = mx - mn+1 > len ? mx -mn+1:len;
    }
    return len;
}
};
