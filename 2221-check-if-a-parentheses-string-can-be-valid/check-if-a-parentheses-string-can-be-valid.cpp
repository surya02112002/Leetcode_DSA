class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false; 

        int minOpen = 0, maxOpen = 0;

        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    ++minOpen;
                    ++maxOpen;
                } else {
                    --minOpen;
                    --maxOpen;
                }
            } else {
                ++maxOpen;    
                --minOpen;   
            }

           
            minOpen = max(minOpen, 0);

           
            if (maxOpen < 0) return false;
        }

        
        return minOpen == 0;
    }
};