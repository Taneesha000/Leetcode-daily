class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events by start day
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> pq; // min-heap for end days
        int i = 0;
        int day = 1;
        int count = 0;
        
        while (i < events.size() || !pq.empty()) {
            // Add all events that start on current day to the heap
            while (i < events.size() && events[i][0] <= day) {
                pq.push(events[i][1]);
                i++;
            }
            
            // Remove events that have already ended
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            
            // Attend the event with earliest end day if possible
            if (!pq.empty()) {
                pq.pop();
                count++;
            }
            
            day++;
        }
        
        return count;
    }
};