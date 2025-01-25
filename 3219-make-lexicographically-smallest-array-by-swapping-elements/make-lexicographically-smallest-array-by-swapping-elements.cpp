class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
         int n = nums.size();
        
        vector<int>vec=nums;
        
        sort(begin(vec),end(vec));

        unordered_map<int,int>mp;
        int groupnum=0;
        mp[vec[0]]=groupnum;
        
          unordered_map<int,list<int>>gtl;

          gtl[groupnum].push_back(vec[0]);

        for (int i=1;i<n;i++){
              
              if ((abs(vec[i]-vec[i-1])>limit)){
                  groupnum++;
              }
              mp[vec[i]]=groupnum;
              gtl[groupnum].push_back(vec[i]);
        }

         for (int i=0;i<n;i++){
             
             int num=nums[i];
             int group=mp[num];

             nums[i]=*(gtl[group].begin());
             gtl[group].pop_front();
         }

         return nums;

    }
};