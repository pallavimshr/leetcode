class Solution:
    def pacificAtlantic(self, heights):
        # Grid ka size nikaalo.
        rows, cols = len(heights), len(heights[0])

        # In sets mein respective ocean se reachable cells store honge.
        pacific = set()
        atlantic = set()

        # Ocean se reverse direction mein DFS chalao.
        def dfs(r, c, visited):

            # Agar cell pehle visit ho chuka hai, dobara explore mat karo.
            if (r, c) in visited:
                return

            # Is cell ko current ocean se reachable mark karo.
            visited.add((r, c))

            # Chaar directions check karo: down, up, right, left.
            for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                nr, nc = r + dr, c + dc

                # Grid ke bahar jaane wale moves ko ignore karo.
                if not (0 <= nr < rows and 0 <= nc < cols):
                    continue

                # Reverse search mein equal ya higher height par ja sakte hain.
                if heights[nr][nc] >= heights[r][c]:
                    dfs(nr, nc, visited)

        # Pacific top border ko touch karta hai.
        for c in range(cols):
            dfs(0, c, pacific)

        # Pacific left border ko bhi touch karta hai.
        for r in range(rows):
            dfs(r, 0, pacific)

        # Atlantic bottom border ko touch karta hai.
        for c in range(cols):
            dfs(rows - 1, c, atlantic)

        # Atlantic right border ko bhi touch karta hai.
        for r in range(rows):
            dfs(r, cols - 1, atlantic)

        # Dono sets mein common cells answer mein aayenge.
        result = []

        for r in range(rows):
            for c in range(cols):
                if (r, c) in pacific and (r, c) in atlantic:
                    result.append([r, c])

        return result