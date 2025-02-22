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
    int idx;
    int nxtDepth, nxtValue;
    void dfs(TreeNode *cur, int depth, string &traversal) {
        int n = traversal.size();
        nxtDepth = 0, nxtValue = 0;
        while (idx < n && traversal[idx] == '-') {
            idx += 1, nxtDepth += 1;
        }
        while (idx < n && traversal[idx] != '-') {
            nxtValue = nxtValue * 10 + traversal[idx] - '0';
            idx += 1;
        }
        if (nxtDepth != depth + 1) return;
        TreeNode *nxt = new TreeNode(nxtValue);
        cur -> left = nxt;
        dfs(nxt, depth + 1, traversal);
        if (nxtDepth == depth + 1) {
            TreeNode *nxt = new TreeNode(nxtValue);
            dfs(nxt, depth + 1, traversal);
            cur -> right = nxt;
        }
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        TreeNode *root = new TreeNode();
        idx = 0;
        dfs(root, -1, traversal);
        return root -> left;
    }
};