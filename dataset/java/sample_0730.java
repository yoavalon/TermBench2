public class sample_0730 {
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

    static boolean lint(Node node) {
        if (node == null) {
            return true;
        }
        if (!(node.left == null || node.left instanceof Node)) {
            return false;
        }
        if (!(node.right == null || node.right instanceof Node)) {
            return false;
        }
        return lint(node.left) && lint(node.right);
    }

    public static void main(String[] args) {
        Node tree = new Node(1, new Node(2), new Node(3, new Node(4), new Node(5)));
        boolean result = lint(tree);
        System.out.println("Tree is valid: " + result);
    }
}