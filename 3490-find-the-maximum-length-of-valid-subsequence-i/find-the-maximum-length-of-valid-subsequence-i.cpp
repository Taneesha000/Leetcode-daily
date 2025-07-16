class Solution {
public:

    int f(vector<int>& nums, int next){

        int cur = 0;
        for(int i = 0; i < nums.size(); i++){
            if((nums[i]&1) == next){
                cur++;
                next = 1 - next;
            }
        }

        return cur;
    }

    int maximumLength(vector<int>& nums) {
        
        int ans = count_if(nums.begin(), nums.end(), [](int& v){
            return v&1;
        });

        ans = max(ans, (int)nums.size() - ans);
        ans = max(ans, f(nums, 0));
        ans = max(ans, f(nums, 1));


        return ans;

    }
};