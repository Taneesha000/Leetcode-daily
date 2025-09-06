class Solution {
public:
    // Compute S(n) = sum_{x=1..n} f(x)
    long long prefixSum(long long n) {
        if (n <= 0) return 0;
        long long sum = 0;
        long long base = 1;  // 4^k
        int k = 0;
        while (base * 4 <= n) {
            long long len = base * 3; // size of block
            sum += (long long)(k + 1) * len;
            base *= 4;
            k++;
        }
        // last partial block
        sum += (long long)(k + 1) * (n - base + 1);
        return sum;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            long long total = prefixSum(r) - prefixSum(l - 1);
            ans += (total + 1) / 2; // ceil(total/2)
        }
        return ans;
    }
};