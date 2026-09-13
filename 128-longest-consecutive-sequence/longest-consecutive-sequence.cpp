class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> numSet;

        // Put all numbers into the set
        for (int num : nums) {
            numSet.insert(num);
        }

        int longest = 0;

        // Check every number
        for (int num : numSet) {

            // Only start if num is the beginning
            // of a consecutive sequence
            if (numSet.find(num - 1) == numSet.end()) {

                int current = num;
                int length = 1;

                // Keep finding the next number
                while (numSet.find(current + 1) != numSet.end()) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};