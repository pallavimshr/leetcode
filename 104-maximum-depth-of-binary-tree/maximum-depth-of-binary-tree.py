
class Solution:
    def maxDepth(self, root):

        # STEP 1: Base Case
        # If current node is None,
        # its depth is 0
        if root is None:
            return 0

        # STEP 2: Find maximum depth of left subtree
        left = self.maxDepth(root.left)

        # STEP 3: Find maximum depth of right subtree
        right = self.maxDepth(root.right)

        # STEP 4: Add current node (1)
        # Return the greater depth
        return 1 + max(left, right)

        