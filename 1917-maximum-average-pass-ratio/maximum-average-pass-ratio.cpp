class Solution {
public:
    double gain(int pass,int total){
        double ans=double((((double)pass+1)/(total+1))-((double)pass/total));
        return ans;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        // vector<double> r(n);
        // for (int i = 0; i < n; i++) {
        //     r[i] = ((double)classes[i][0] / (double)classes[i][1]);
        // }
        // double mi = *min_element(r.begin(), r.end());
        // for (int i = 0; i < n; i++) {
        //     if (r[i] == mi) {
        //         r[i] = ((double)(classes[i][0] + extraStudents) /
        //                 (classes[i][1] + extraStudents));
                
        //     }
        // }
        // double sum = accumulate(r.begin(), r.end(), 0.0);
        // return (double)(sum / n);
        
        priority_queue<pair<double,pair<int,int>>>pq;
        for(auto it:classes){
            pq.push({gain(it[0],it[1]),{it[0],it[1]}});
        }

        while(extraStudents>0){
            auto it=pq.top();
            pq.pop();
            double currmx=it.first;
            int p=it.second.first;
            int t=it.second.second;
            pq.push({gain(p+1,t+1),{p+1,t+1}}); // now pushing new gain in heap by assigning 1 student
            extraStudents--;
        }
        double sum=0.0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            sum+=((double)it.second.first/(double)it.second.second);
        }
        return sum/n;
    }
};