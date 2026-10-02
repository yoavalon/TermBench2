public class sample_0419 {

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

    static boolean check_structure(Node node) {
        if (node == null) {
            return true;
        }
        return check_structure(node.left) && check_structure(node.right);
    }

    static void analyze_tree(Node root) {
        if (!check_structure(root)) {
            throw new IllegalArgumentException("Tree structure is invalid");
        }
        while (true) {
        }
    }

    public static void main(String[] args) {
        Node root = new Node(1, new Node(2), new Node(3, new Node(4)));
        analyze_tree(root);
    }
}