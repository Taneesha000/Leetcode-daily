class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();

        vector<double> diagonals(n);
        
        for(int i=0; i<n; i++){
            int length = dimensions[i][0];
            int width = dimensions[i][1];
            
            double diag = sqrt((length*length)+(width*width));
            diagonals[i] = diag;
        }

        int maxIdx = 0;
        int k = 0;
        while(k < n){
            if(diagonals[maxIdx] < diagonals[k]){
                maxIdx = k;
            }else if (diagonals[maxIdx] == diagonals[k]){
                int len1 = dimensions[maxIdx][0];
                int wid1 = dimensions[maxIdx][1];
                int len2 = dimensions[k][0];
                int wid2 = dimensions[k][1];
                if((len2*wid2) > (len1*wid1)){
                    maxIdx = k;
                }
            }
            k++;
            
        }

        return dimensions[maxIdx][0]*dimensions[maxIdx][1];
    }
};