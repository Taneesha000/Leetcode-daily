class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dis1=abs(x-z);
        int dis2=abs(y-z);

        if(dis1<dis2){
            return 1;
        }

        else if(dis2<dis1){
            return 2;
        }
        else{
            return 0;
        }
        





        
    }
};