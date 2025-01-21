class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<long long int>first(n,0);

        vector<long long int>second(n,0);
        
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+grid[0][i];
            first[i]=sum;
        }

        sum=0;

        for(int i=0;i<n;i++){
            sum=sum+grid[1][i];
            second[i]=sum;
        }

        long long int mini= LLONG_MAX;
        for(int i=0;i<n;i++){
            if(i==0){
                if(mini>first[n-1]-first[0]){
                    mini=first[n-1]-first[0];
                }
                continue;
            }
            
            long long int bb=max((first[n-1]-first[i]),(second[i-1]));
            mini=min(mini,bb);
        }
        return mini;
    }
};