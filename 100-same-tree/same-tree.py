# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sameTreeList(self, root):

        # Empty node gets a None marker
        if root is None:
            return [None]

        # Store current value
        result = [root.val]

        # Store left subtree representation
        result += self.sameTreeList(root.left)

        # Store right subtree representation
        result += self.sameTreeList(root.right)

        return result

    def isSameTree(self, p, q):

        # Generate representation of both trees
        list1 = self.sameTreeList(p)
        list2 = self.sameTreeList(q)

        # Compare both representations
        return list1 == list2
        