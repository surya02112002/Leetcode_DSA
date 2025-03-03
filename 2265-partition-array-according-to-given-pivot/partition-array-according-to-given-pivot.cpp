class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        deque<int> dq;
        for (auto it : nums) {
            if (it < pivot) {
                ans.push_back(it);
            }
            else if (it == pivot) {
                dq.push_front(it);
            }
            else {
                dq.push_back(it);
            }
        }

        while (!dq.empty()) {
            ans.push_back(dq.front());
            dq.pop_front();
        }

        return ans;
    }
};