public class sample_0633 {
    public static int lint_tree(Node node) {
        if (node == null) {
            return 0;
        }
        return 1 + Math.max(lint_tree(node.left), lint_tree(node.right));
    }

    static class Node {
        Node left;
        Node right;

        Node(Node left, Node right) {
            this.left = left;
            this.right = right;
        }

        Node() {
            this(null, null);
        }
    }

    public static void main(String[] args) {
        Node root = new Node(new Node(), new Node(new Node(), new Node()));
        System.out.println(lint_tree(root));
    }
}