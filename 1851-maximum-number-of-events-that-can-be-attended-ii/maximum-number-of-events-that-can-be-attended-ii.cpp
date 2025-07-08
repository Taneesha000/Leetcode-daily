class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        
        // Sort events by end time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        // dp[i][j] = maximum value using at most j events from events[0...i-1]
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            // Find the latest event that doesn't overlap with events[i-1]
            int prev = findLastNonOverlapping(i - 1, events);
            
            for (int j = 1; j <= k; j++) {
                // Option 1: Don't take event i-1
                dp[i][j] = dp[i-1][j];
                
                // Option 2: Take event i-1
                int takeValue = events[i-1][2]; // value of current event
                if (prev != -1) {
                    takeValue += dp[prev + 1][j - 1];
                }
                // If prev == -1, we can still take this event if j >= 1
                
                dp[i][j] = max(dp[i][j], takeValue);
            }
        }
        
        return dp[n][k];
    }
    
private:
    int findLastNonOverlapping(int i, vector<vector<int>>& events) {
        int target = events[i][0]; // start time of event i
        int left = 0, right = i - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (events[mid][1] < target) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};

/*
Test with examples:

Example 1: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
After sorting by end time: [[1,2,4],[2,3,1],[3,4,3]]
- Event 0: [1,2,4] - no previous events
- Event 1: [2,3,1] - previous event [1,2,4] ends at 2, current starts at 2 (overlaps)
- Event 2: [3,4,3] - previous event [1,2,4] ends at 2, current starts at 3 (compatible)

dp[1][1] = 4 (take event 0)
dp[1][2] = 4 (take event 0)
dp[2][1] = max(4, 1) = 4 (don't take event 1)
dp[2][2] = max(4, 1) = 4 (don't take event 1)
dp[3][1] = max(4, 3) = 4 (don't take event 2)
dp[3][2] = max(4, 4+3) = 7 (take event 0 and event 2)

Result: 7 ✓

Example 2: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
After sorting by end time: [[1,2,4],[2,3,10],[3,4,3]]
- Event 0: [1,2,4] - no previous events
- Event 1: [2,3,10] - previous event [1,2,4] ends at 2, current starts at 2 (overlaps)
- Event 2: [3,4,3] - previous event [1,2,4] ends at 2, current starts at 3 (compatible)

dp[1][1] = 4
dp[1][2] = 4
dp[2][1] = max(4, 10) = 10
dp[2][2] = max(4, 10) = 10
dp[3][1] = max(10, 3) = 10
dp[3][2] = max(10, 4+3) = 10

Result: 10 ✓
*/