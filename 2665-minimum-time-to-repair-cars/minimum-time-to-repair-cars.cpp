class Solution {
public:

    bool isPossible(vector<int>& ranks, int givenCars, long long mid){
        int repairedCars = 0;

        for(int rank : ranks){

            if (mid < rank) continue;
            
            int carsByMech = (int)sqrt( (1.0 * mid) / rank); 
            repairedCars += carsByMech;
                    
            if(repairedCars >= givenCars) return true;
        }

        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1;
        long long r =  1LL * (*min_element(ranks.begin(), ranks.end())) * cars * cars;
        

        long long result = r;
    
        while(l <= r){
            long long mid = l + (r-l) / 2;   

            if(isPossible(ranks, cars, mid)){
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
};