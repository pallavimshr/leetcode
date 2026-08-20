class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {

        unordered_set<int> all;

        unordered_set<int> current;

        for (int x : arr) {

            unordered_set<int> next;

            // New subarray containing only x
            next.insert(x);

            // Extend all previous subarrays
            for (int value : current) {
                next.insert(value | x);
            }

            current = next;

            // Add these OR values to global answer
            for (int value : current) {
                all.insert(value);
            }
        }

        return all.size();
    }
};