class Solution {
public:
    long long findScore(vector<int>& nums) {

        long score = 0;
        int n = nums.size();

       
        for (int i = 0; i < n; i += 2) 
        {
           
            int i0 = i;

            
            while (i + 1 < n && nums[i] > nums[i + 1])
                
                ++i;

            
            for (int j = i; j >= i0; j -= 2)
               
                score += nums[j];
        }

        
        vector<bool> marked(n, false);
        long sorted = 0;

       
        for (int i = 0; i < n; ++i) 
        {
            
            if (!marked[i]) 
            {
               
                sorted += nums[i];

                
                if (i - 1 >= 0) 
                {
                    marked[i - 1] = true;
                }
                
                if (i + 1 < n) 
                {
                    marked[i + 1] = true;
                }
            }
        }
        
        return score;
    }
};