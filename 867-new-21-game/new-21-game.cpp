class Solution {
public:
    /* double f(int pts, int n, int maxN, int maxPts, int k, vector<double>& dp)
     { if(pts >= k) { if(pts <= n) return 1.0; return 0;
         }
         if(dp[pts] != -1) return dp[pts];

         double chance = 0.0;
         for(int i=1; i<=maxN; i++) {
             chance += f(pts+i, n, maxN, maxPts, k, dp);
         }

         return dp[pts] = chance/maxPts;
     }

     double new21Game(int n, int k, int maxPts) {
         vector<double> dp(n+1, -1.0);
         double prob = f(0, n, min(n, maxPts), maxPts, k, dp);
         return prob;
     }*/
    // Tabulation
    /* double new21Game(int n, int k, int maxPts) {
         vector<double> dp(n+1, 0.0);

         for(int i=k; i<=n; i++) {
             dp[i] = 1.0;
         }
         //already dp[i] for i>=k is computed

         for(int i=k-1; i>=0; i--) {
             for(int j=1; j<=min(n, maxPts); j++) {
                 if(i+j <= n)dp[i] += dp[i+j];
             }
             dp[i] = dp[i]/maxPts;
         }

         return dp[0];
     }*/
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + 1, 0.0);

        double sum = 0.0;
        for (int i = k; i <= n; i++) {
            dp[i] = 1.0;
        }

        for (int r = k; r <= min(n, k - 1 + maxPts); r++) {
            sum += dp[r];
        }
        /*here not upto min(n, maxPts) bcoz the window has to go until i+maxPts
        and i is atmost k-1

        See the innner loop in tabulation j goes from 1 till min(n, maxPts)
        if i=16, i+j = 26, but we dont add to dp[i] if i+j > n
        so,
        dp[16]  = dp[17] + ..... + dp[21] //only upto 21
        and we have sum = dp[17] + ..... + dp[21] precomputed, from now on we
        will just have to add the computed dp[i] also to sum newsum = sum +
        dp[16] 
        
        coz dp[15] = dp[16] + ... + dp[21] = newsum
        .
        .
        dp[11] = dp[12] + dp[13] + ..... dp[21]
        but from now,
        we have to subtract the dp[i]s from last,
        => at i=11 dp[i] = prevsum/maxPts
        sum += dp[i]//to be used for i=10
        but, we have to subtract dp[21] which is dp[i+maxPts]

        dp[10] = dp[11] + ..... dp[10+maxPts] => dp[11] + ... + dp[20]

        Similarly here sum += dp[10] but sum-=dp[20]

        dp[9] = dp[10] + dp[11] +...+dp[19]

        */

        // already dp[i] for i>=k is computed

        for (int i = k - 1; i >= 0; i--) {
            dp[i] += sum / maxPts;
            sum += dp[i];
            if (i + maxPts <= n)
                sum -= dp[i + maxPts];
        }

        return dp[0];
    }
};