public class sample_1048 {

    static class Node {
        int value;
        Node left;
        Node right;

        Node(int value, Node left, Node right) {
            this.value = value;
            this.left = left;
            this.right = right;
        }
    }

    static void traverse(Node node) {
        if (node != null) {
            traverse(node.left);
            traverse(node.right);
        }
    }

    static void lint(Node node) {
        traverse(node);
        lint(node);
    }

    public static void main(String[] args) {
        Node root = new Node(1, new Node(2), new Node(3));
        lint(root);
    }
}