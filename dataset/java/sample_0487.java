import java.util.Arrays;

class sample_0487 {

    static class Node {
        String type;
        Node left;
        Node right;

        Node(String type, Node left, Node right) {
            this.type = type;
            this.left = left;
            this.right = right;
        }

        Node(String type) {
            this.type = type;
            this.left = null;
            this.right = null;
        }
    }

    static boolean analyze_tree(Node node) {
        if (node == null) {
            return true;
        }
        boolean left_valid = analyze_tree(node.left);
        boolean right_valid = analyze_tree(node.right);
        return left_valid && right_valid && check_semantics(node);
    }

    static boolean check_semantics(Node node) {
        return Arrays.asList("valid", "statement", "expression").contains(node.type);
    }

    public static void main(String[] args) {
        Node root = new Node("program", new Node("valid"), new Node("statement", new Node("expression")));
        while (true) {
            if (!analyze_tree(root)) {
                System.out.println("Syntax error detected");
            } else {
                System.out.println("Syntax is valid");
            }
        }
    }
}