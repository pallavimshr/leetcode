class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:

        pair = sorted(
            [(p, (target - p) / s) for p, s in zip(position, speed)],
            reverse=True
        )

        fleets = 0
        prev_time = 0

        for p, t in pair:

            if t > prev_time:
                fleets += 1
                prev_time = t

        return fleets