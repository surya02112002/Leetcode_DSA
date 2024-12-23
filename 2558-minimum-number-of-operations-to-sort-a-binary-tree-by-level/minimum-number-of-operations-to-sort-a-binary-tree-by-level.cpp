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
    int minimumOperations(TreeNode* root) {
        int count = 0;
        deque<TreeNode*> queue;
        vector<pair<int,int>> sorteds;
        queue.push_back(root);
        //traverse through each level with bfs
        while(!queue.empty()){
            int black = queue.size();
            for(int i = 0; i < black; ++i){
                TreeNode* sup = queue.front();
                queue.pop_front();
                if(sup == nullptr) continue;
                sorteds.push_back({sup->val, i});
                //make sure nullptr do not make it into queue as it will affect the size of queue.
                if(sup->left != nullptr) queue.push_back(sup->left);
                if(sup->right != nullptr) queue.push_back(sup->right);

            }
            sort(sorteds.begin(), sorteds.end());
            //iterate through sorted
            for(int i = 0; i <sorteds.size(); ++i){
                while(sorteds[i].second != i){
                    //loops until the value is at the original index
                    auto temp = sorteds[sorteds[i].second];
                    sorteds[sorteds[i].second] = sorteds[i];
                    sorteds[i] = temp;
                    ++count;

                }
            }
            //resize to ensure sorteds is empty
            sorteds.resize(0);

        }
        return count;
    }
};