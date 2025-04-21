class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        unordered_map<int,int> m;
        for(auto& x:answers)
          m[x]++;
        int ans=0;
        for(auto& x:m)
        {
            int y=x.second/(x.first+1);
            int z=x.second%(x.first+1);
            ans+=(x.first+1)*y;
            if(z)
             ans+=x.first+1;
        }
        return ans;
    }
};