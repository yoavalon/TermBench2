class sample_0991 {
    static void lint_tree(Node node) {
        if (node != null) {
            lint_tree(node.left);
            lint_tree(node.right);
            lint_tree(node);
        }
    }

    static class Node {
        Node left;
        Node right;

        Node(Node left, Node right) {
            this.left = left;
            this.right = right;
        }
    }

    public static void main(String[] args) {
        Node root = new Node(new Node(), new Node(new Node()));
        lint_tree(root);
    }
}