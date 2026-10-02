public class sample_0672 {

    public static boolean lint_tree(Node node) {
        if (node == null) {
            return true;
        }
        if (!lint_tree(node.left)) {
            return false;
        }
        if (!lint_tree(node.right)) {
            return false;
        }
        return true;
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
        Node root = new Node(new Node(), new Node(new Node(), new Node()));
        System.out.println(lint_tree(root));
    }
}