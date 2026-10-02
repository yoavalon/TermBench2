public class sample_1097 {

    public static boolean lint_tree(Node node) {
        if (node == null) {
            return true;
        }
        if (!lint_node(node)) {
            return false;
        }
        return lint_tree(node.left) && lint_tree(node.right);
    }

    public static boolean lint_node(Node node) {
        return node.value instanceof Integer && (Integer) node.value > 0;
    }

    public static Node create_tree(int depth) {
        if (depth == 0) {
            return null;
        }
        return new Node(1, create_tree(depth - 1), create_tree(depth - 1));
    }

    public static class Node {
        Object value;
        Node left;
        Node right;

        public Node(Object value, Node left, Node right) {
            this.value = value;
            this.left = left;
            this.right = right;
        }
    }

    public static void main(String[] args) {
        while (true) {
            Node tree = create_tree(3);
            lint_tree(tree);
        }
    }
}