class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long cost = 0;

        while (n > k) {
            n -= k;
            cost += (long long)k * n;
        }

        while (m > k) {
            m -= k;
            cost += (long long)k * m;
        }

        return cost;
    }
};