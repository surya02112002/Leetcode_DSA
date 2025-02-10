class Solution {
public:
    string clearDigits(string s) {
        string ans;
        int n = s.size(), cnt = 0;
        for (int i = n-1; i >= 0; i --) {
            if (s[i] >= '0' && s[i] <= '9') {
                cnt ++;
            }
            else if (cnt > 0) {
                cnt --; continue;
            }
            else if (cnt == 0) {
                ans.push_back(s[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};