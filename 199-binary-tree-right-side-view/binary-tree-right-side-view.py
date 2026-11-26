# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    def rightSideView(self, root):

        # Agar tree empty hai
        if not root:
            return []

        result = []

        # Queue mein root node daalo
        queue = deque([root])

        # Jab tak queue empty nahi hoti
        while queue:

            # Current level ke nodes count karo
            size = len(queue)

            # Current level ke saare nodes process karo
            for i in range(size):

                # Queue se node nikalo
                node = queue.popleft()

                # Agar current level ka last node hai
                if i == size - 1:
                    result.append(node.val)

                # Left child queue mein add karo
                if node.left:
                    queue.append(node.left)

                # Right child queue mein add karo
                if node.right:
                    queue.append(node.right)

        return result