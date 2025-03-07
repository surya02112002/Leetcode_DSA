class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> sieve(right + 1, true);
        sieve[0] = sieve[1] = false; 

        
        for (int i = 2; i * i <= right; i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= right; j += i) {
                    sieve[j] = false;
                }
            }
        }

        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (sieve[i]) primes.push_back(i);
        }

    
        if (primes.size() < 2) return {-1, -1};

        int minDiff = INT_MAX, idx = -1;
        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                idx = i - 1;
            }
        }

        return {primes[idx], primes[idx + 1]};
    }
};