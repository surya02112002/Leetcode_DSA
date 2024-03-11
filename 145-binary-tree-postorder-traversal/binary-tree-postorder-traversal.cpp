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
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         postorder(root,ans);
//         return ans;
        
//     }
//     void postorder(TreeNode* root, vector<int>&arr){
//         if(root==NULL){
//             return ;
//         }
//         postorder(root->left,arr);
//         postorder(root->right,arr);
//         arr.push_back(root->val);
//     }
// };


//itrative using two stack

// 


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*> st;
        while(root!=NULL|| !st.empty()){
            if (root!=NULL){
                st.push(root);
                root=root->left;

            }
            else{
                TreeNode* temp=st.top()->right;
                if(temp==NULL){
                    temp= st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty()&& temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }else{
                    root=temp;
                }
                
            }
        }
        return ans;
    }

};