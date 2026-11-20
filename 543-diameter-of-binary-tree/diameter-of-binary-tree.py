
class Solution:
    def diameterOfBinaryTree(self, root):

        # Store maximum diameter found so far
        diameter = 0

        # Helper function to calculate height
        def height(node):
            nonlocal diameter

            # Base case: Empty node has height 0
            if node is None:
                return 0

            # Calculate left subtree height
            left = height(node.left)

            # Calculate right subtree height
            right = height(node.right)

            # Update maximum diameter
            # Diameter through current node = left + right
            diameter = max(diameter, left + right)

            # Return height to parent node
            return 1 + max(left, right)

        # Start DFS from root
        height(root)

        # Return maximum diameter
        return diameter

        