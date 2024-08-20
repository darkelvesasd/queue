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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     if (root == nullptr)
     {
         return {};
     }
     int target = false;
     vector<vector<int>>ret;
     queue<TreeNode*>q;
     q.emplace(root);
     while (!q.empty())
     {
         int sz = q.size();
         vector<int>r;
         for (int i = 0; i < sz; i++)
         {
             TreeNode* t1 = q.front();
             r.emplace_back(t1->val);
             q.pop();
                 if (t1->left)
                 {
                     q.emplace(t1->left);
                 }
                 if (t1->right)
                 {
                     q.emplace(t1->right);
                 }
         }
         if (target)
         {
             reverse(r.begin(), r.end());
         }
         ret.emplace_back(r);
        target=( target == true ? false : true);
     }
     return ret;
 }
};
