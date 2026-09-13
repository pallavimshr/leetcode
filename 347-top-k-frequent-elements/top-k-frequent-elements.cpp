class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count frequencies
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Create buckets
        vector<vector<int>> bucket(nums.size() + 1);

        // Step 3: Put numbers into bucket based on frequency
        for (auto& [num, count] : freq) {
            bucket[count].push_back(num);
        }

        // Step 4: Traverse from highest frequency to lowest
        vector<int> ans;

        for (int i = nums.size(); i >= 1 && ans.size() < k; i--) {

            for (int num : bucket[i]) {

                ans.push_back(num);

                if (ans.size() == k) {
                    break;
                }
            }
        }

        return ans;
    }
};