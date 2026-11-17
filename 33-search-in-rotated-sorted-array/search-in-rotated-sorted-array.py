class Solution:
    def search(self, nums, target):
        low = 0
        high = len(nums) - 1

        while low <= high:
            mid = (low + high) // 2

            if nums[mid] == target:
                return mid

            # Check if left half is sorted
            if nums[low] <= nums[mid]:

                # Is target inside the sorted left half?
                if nums[low] <= target < nums[mid]:
                    high = mid - 1
                else:
                    low = mid + 1

            # Otherwise, right half is sorted
            else:

                # Is target inside the sorted right half?
                if nums[mid] < target <= nums[high]:
                    low = mid + 1
                else:
                    high = mid - 1

        return -1