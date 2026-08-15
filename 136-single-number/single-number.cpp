class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor_result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            xor_result ^= nums[i];
        }
        return xor_result;
    }
};