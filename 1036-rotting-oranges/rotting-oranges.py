
from collections import deque

class Solution:
    def orangesRotting(self, grid):
        rows, cols = len(grid), len(grid[0])

        # Queue stores all oranges that are already rotten.
        # Starting with ALL rotten oranges makes this multi-source BFS.
        queue = deque()

        # Count fresh oranges so we know when the job is complete.
        fresh = 0

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    # These oranges can start spreading rot immediately.
                    queue.append((r, c))
                elif grid[r][c] == 1:
                    # We need to know if any fresh oranges remain at the end.
                    fresh += 1

        # If no fresh oranges exist, no time is needed.
        if fresh == 0:
            return 0

        minutes = 0

        # Each iteration processes one complete minute (one BFS level).
        while queue and fresh > 0:

            # Capture the current level's size.
            # Newly rotten oranges must wait until the next minute.
            size = len(queue)

            for _ in range(size):
                # Take one orange from the current level.
                r, c = queue.popleft()

                # Check up, down, left, and right.
                for dr, dc in [(1, 0), (-1, 0),
                               (0, 1), (0, -1)]:
                    nr = r + dr
                    nc = c + dc

                    # Ignore neighbours outside the grid.
                    if not (0 <= nr < rows and 0 <= nc < cols):
                        continue

                    # Only fresh oranges can become newly rotten.
                    if grid[nr][nc] == 1:
                        # Mark it immediately to prevent duplicate processing.
                        grid[nr][nc] = 2

                        # This orange can spread rot in the next minute.
                        queue.append((nr, nc))

                        # One fewer fresh orange remains.
                        fresh -= 1

            # One full level has been processed, so one minute has passed.
            minutes += 1

        # If fresh oranges remain, some could not be reached by rot.
        if fresh > 0:
            return -1

        # Every fresh orange became rotten.
        return minutes
