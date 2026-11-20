
class Solution:
    def isBalanced(self, root):

        # Helper function returns height
        # Or -1 if subtree is unbalanced
        def height(node):

            # Base case: Empty tree has height 0
            if node is None:
                return 0

            # Calculate left subtree height
            left = height(node.left)

            # If left subtree is unbalanced
            # Propagate -1 immediately
            if left == -1:
                return -1

            # Calculate right subtree height
            right = height(node.right)

            # If right subtree is unbalanced
            # Propagate -1 immediately
            if right == -1:
                return -1

            # Check height difference
            if abs(left - right) > 1:
                return -1

            # Return current node's height
            return 1 + max(left, right)

        # Tree is balanced if returned height is not -1
        return height(root) != -1

        