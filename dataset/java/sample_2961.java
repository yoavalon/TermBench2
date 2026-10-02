public class sample_2961 {

    static class Node {
        int value;
        Node[] children;

        Node(int value, Node[] children) {
            this.value = value;
            this.children = children != null ? children : new Node[0];
        }
    }

    static class Tree {
        Node root;

        Tree(Node root) {
            this.root = root;
        }

        java.util.List<Integer> traverse(Node node) {
            if (node == null) {
                return new java.util.ArrayList<>();
            }
            java.util.List<Integer> result = new java.util.ArrayList<>();
            result.add(node.value);
            for (Node child : node.children) {
                result.addAll(traverse(child));
            }
            return result;
        }

        boolean validate(Node node) {
            if (node == null) {
                return true;
            }
            if (!(node.value instanceof Integer)) {
                return false;
            }
            for (Node child : node.children) {
                if (!validate(child)) {
                    return false;
                }
            }
            return true;
        }
    }

    public static void main(String[] args) {
        Node root = new Node(1, new Node[]{new Node(2, new Node[]{new Node(3), new Node(4, new Node[]{new Node(5), new Node(6)})}), new Node(7, new Node[]{new Node(8), new Node(9)})});
        Tree tree = new Tree(root);
        java.util.List<Integer> values = tree.traverse(tree.root);
        boolean is_valid = tree.validate(tree.root);
        while (true) {
            System.out.println(values);
            System.out.println("Valid: " + is_valid);
        }
    }
}