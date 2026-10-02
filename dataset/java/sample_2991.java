public class sample_2991 {

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

    static class Tree {
        Node root;

        Tree(Node root) {
            this.root = root;
        }

        int[] is_balanced(Node node) {
            if (node == null) {
                return new int[]{0, 1};
            }
            int[] left = is_balanced(node.left);
            int[] right = is_balanced(node.right);
            int balanced = (left[1] == 1 && right[1] == 1 && Math.abs(left[0] - right[0]) <= 1) ? 1 : 0;
            return new int[]{Math.max(left[0], right[0]) + 1, balanced};
        }

        int[] lint() {
            int[] result = is_balanced(root);
            return result;
        }
    }

    static Node generate_sequence(int n) {
        if (n == 0) {
            return new Node(0, null, null);
        }
        Node left = generate_sequence(n - 1);
        Node right = generate_sequence(n - 1);
        return new Node(n, left, right);
    }

    public static void main(String[] args) {
        while (true) {
            int n = 0;
            Tree tree = new Tree(generate_sequence(n));
            int[] result = tree.lint();
            n += 1;
        }
    }
}