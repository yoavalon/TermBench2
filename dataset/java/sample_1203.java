public class sample_1203 {
    static class Node {
        Node left;
        Node right;
    }

    static void process_tree(Node node) {
        if (node == null) {
            return;
        }
        process_tree(node.left);
        process_tree(node.right);
    }

    public static void main(String[] args) {
        Node root = null;
        process_tree(root);
    }
}