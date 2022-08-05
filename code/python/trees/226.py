# wow i finally did it myself
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root:
            save = root.right
            root.right = root.left
            root.left = save
            self.invertTree(root.left)
            self.invertTree(root.right)
        return root
