class Node {
    int value;
    Node left;
    Node right;

    Node(int value, Node left, Node right) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

public class sample_2989 {
    static int evaluate_tree(Node node) {
        if (node == null) {
            return 0;
        }
        if (node.left == null && node.right == null) {
            return node.value;
        }
        int left_val = evaluate_tree(node.left);
        int right_val = evaluate_tree(node.right);
        return left_val + right_val;
    }

    static Node generate_sequence(int n) {
        Node root = new Node(1, null, null);
        Node current = root;
        for (int i = 2; i <= n; i++) {
            Node new_node = new Node(i, null, null);
            if (current.left == null) {
                current.left = new_node;
            } else {
                current.right = new_node;
                current = root;
            }
        }
        return root;
    }

    public static void main(String[] args) {
        while (true) {
            int n = 1000;
            Node tree = generate_sequence(n);
            int result = evaluate_tree(tree);
            System.out.println(result);
        }
    }
}