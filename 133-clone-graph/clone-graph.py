
from collections import deque

class Solution:
    def cloneGraph(self, node):

        # Agar starting node nahi hai, toh clone bhi nahi hoga
        if node is None:
            return None

        # Original node -> cloned node ka mapping
        old_to_new = {}

        # Starting node ki copy banao aur map mein save karo
        old_to_new[node] = Node(node.val)

        # Queue mein original starting node daalo
        queue = deque([node])

        # Jab tak queue mein process karne ke liye nodes hain
        while queue:

            # Sabse pehle queue mein aaya original node nikalo
            original = queue.popleft()

            # Is original node ki cloned copy lo
            copy = old_to_new[original]

            # Original node ke har neighbour ko check karo
            for neighbor in original.neighbors:

                # Agar neighbour ki copy abhi nahi bani
                if neighbor not in old_to_new:

                    # Neighbour ki new copy banao
                    old_to_new[neighbor] = Node(neighbor.val)

                    # Original neighbour ko baad mein process karenge
                    queue.append(neighbor)

                # Neighbour ki cloned copy current clone se connect karo
                copy.neighbors.append(old_to_new[neighbor])

        # Starting node ki cloned copy return karo
        return old_to_new[node]
