/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>>ret;
    queue<Node*>q;
    int len = 0;
    if (root)
    {
        q.emplace(root);
        len = 1;
    }
    else
    {
        return ret;
    }
    while (!q.empty())
    {
        vector<int>r;
        for (int i = 0; i < len; i++)
        {
            auto it = root->children.begin();
            while (it != root->children.end())
            {
                q.emplace(*it);
                it++;
            }
            r.emplace_back(q.front()->val);
            q.pop();
            if (q.empty())
            {
                break;
            }
            root = q.front();
        }
        ret.emplace_back(r);
        len = q.size();
    }
    return ret;
}
};
