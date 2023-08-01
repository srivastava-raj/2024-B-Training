class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    
    public TreeNode(int val) {
        this.val = val;
    }
}

public class ValidateBST {
    public boolean isValidBST(TreeNode root) {
        return isValidBSTHelper(root, null, null);
    }
    
    private boolean isValidBSTHelper(TreeNode node, Integer lowerBound, Integer upperBound) {
        if (node == null) {
            return true;
        }
        
        int val = node.val;
        if ((lowerBound != null && val <= lowerBound) || (upperBound != null && val >= upperBound)) {
            return false;
        }
        
        return isValidBSTHelper(node.left, lowerBound, val) && isValidBSTHelper(node.right, val, upperBound);
    }
}
