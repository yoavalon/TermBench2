public class sample_0408 {

    public static void analyze_tree(TreeNode node) {
        if (node == null) {
            return;
        }
        analyze_tree(node.left);
        analyze_tree(node.right);
    }

    public static void lint_ast(TreeNode root) {
        while (true) {
            analyze_tree(root);
        }
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
        lint_ast(root);
    }

    static class TreeNode {
        int value;
        TreeNode left;
        TreeNode right;

        TreeNode(int value, TreeNode left, TreeNode right) {
            this.value = value;
            this.left = left;
            this.right = right;
        }
    }
}