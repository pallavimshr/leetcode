
class Solution:
    def invertTree(self, root):

        # STEP 1: Base case
        # If current node is None,
        # there is nothing to invert.
        if root is None:
            return None

        # STEP 2: Recursively invert the right subtree.
        # Store its root in the variable 'left'.
        # This subtree will become our new left subtree.
        left = self.invertTree(root.right)

        # STEP 3: Recursively invert the left subtree.
        # Store its root in the variable 'right'.
        # This subtree will become our new right subtree.
        right = self.invertTree(root.left)

        # STEP 4: Swap the subtree references.
        # Original right becomes new left.
        root.left = left

        # Original left becomes new right.
        root.right = right

        # STEP 5: Return the same root node.
        # Its subtree has now been inverted.
        return root
