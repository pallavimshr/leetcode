class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {

        int ans = 0;
        int n = nums.size();

        for (int bit = 0; bit < 30; bit++) {

            int count1 = 0;

            for (int num : nums) {
                if (num & (1 << bit)) {
                    count1++;
                }
            }

            int count0 = n - count1;

            ans += count1 * count0;
        }

        return ans;
    }
};