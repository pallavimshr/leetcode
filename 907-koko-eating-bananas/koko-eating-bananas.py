
  
class Solution:
    def minEatingSpeed(self, piles, h):
        low = 1
        high = max(piles)

        while low <= high:
            mid = (low + high) // 2

            total_hours = 0

            for pile in piles:
                total_hours += (pile + mid - 1) // mid

            if total_hours <= h:
                high = mid - 1
            else:
                low = mid + 1

        return low
