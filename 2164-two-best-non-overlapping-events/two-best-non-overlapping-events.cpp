class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size(),ans=0;
        vector<int> mx(n),st(n);
        mx[n-1]=events[n-1][2];
        for(int i=n-2;i>=0;i--) {
            mx[i]=max(mx[i+1],events[i][2]);
        }
        mx.push_back(0);
        for(int i=0;i<n;i++) {
            st[i]=events[i][0];
        }
        for(int i=0;i<n;i++) {
            int x=upper_bound(st.begin(),st.end(),events[i][1])-st.begin();
            ans=max(ans,events[i][2]+mx[x]);
        }
        return ans;
    }
};