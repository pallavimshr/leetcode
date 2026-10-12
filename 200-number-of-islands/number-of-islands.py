
class Solution(object):
    def numIslands(self, grid):
        m = len(grid)
        n = len(grid[0])
        count = 0

        for r in range(m):
            for c in range(n):
                if grid[r][c] == "1":
                    count += 1

                    stack = [(r, c)]
                    grid[r][c] = "0"

                    while stack:
                        row, col = stack.pop()

                        directions = [(1, 0), (-1, 0),
                                      (0, 1), (0, -1)]

                        for dr, dc in directions:
                            nr = row + dr
                            nc = col + dc

                            if (0 <= nr < m and
                                0 <= nc < n and
                                grid[nr][nc] == "1"):

                                grid[nr][nc] = "0"
                                stack.append((nr, nc))

        return count
