#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq2; // frequency map for nums2
    
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        
        // Build frequency map for nums2
        for (int num : nums2) {
            freq2[num]++;
        }
    }
    
    void add(int index, int val) {
        // Remove old value from frequency map
        freq2[nums2[index]]--;
        if (freq2[nums2[index]] == 0) {
            freq2.erase(nums2[index]);
        }
        
        // Update nums2
        nums2[index] += val;
        
        // Add new value to frequency map
        freq2[nums2[index]]++;
    }
    
    int count(int tot) {
        int result = 0;
        
        // For each element in nums1, find how many elements in nums2 
        // can pair with it to make sum = tot
        for (int num1 : nums1) {
            int target = tot - num1;
            if (freq2.find(target) != freq2.end()) {
                result += freq2[target];
            }
        }
        
        return result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */