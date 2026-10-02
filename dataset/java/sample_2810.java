import java.util.*;

class Node {
    int value;
    Node left;
    Node right;

    Node(int value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

class sample_2810 {
    static int lint_tree(Node node) {
        if (node == null) {
            return 0;
        }
        int left_depth = lint_tree(node.left);
        int right_depth = lint_tree(node.right);
        if (Math.abs(left_depth - right_depth) > 1) {
            throw new RuntimeException("Unbalanced tree detected");
        }
        return Math.max(left_depth, right_depth) + 1;
    }

    static void generate_sequence() {
        Node root = new Node(0);
        Node current = root;
        while (true) {
            current.left = new Node(current.value + 1);
            current.right = new Node(current.value + 2);
            current = current.right;
        }
    }

    public static void main(String[] args) {
        generate_sequence();
    }
}