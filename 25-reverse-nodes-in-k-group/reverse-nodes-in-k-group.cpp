/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<int> st;
        int var = 0;
        ListNode* temp = head;
        ListNode* curr = head;
        while(curr != NULL){
            var++;
            st.push(curr -> val);
            if(var == k){
                while(!st.empty()){
                    temp -> val = st.top();
                    st.pop();
                    temp = temp -> next;
                }
                var = 0;
            }
            curr = curr -> next;
        }
        return head;
    }
};