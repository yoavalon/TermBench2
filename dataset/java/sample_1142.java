public class sample_1142 {
    static class Node {
        int value;
        Node left;
        Node right;

        Node(int value) {
            this.value = value;
            this.left = null;
            this.right = null;
        }
    }

    static class Tree {
        Node root;

        Tree() {
            this.root = null;
        }

        void insert(int value) {
            if (this.root == null) {
                this.root = new Node(value);
            } else {
                this._insert_recursive(this.root, value);
            }
        }

        void _insert_recursive(Node node, int value) {
            if (value < node.value) {
                if (node.left == null) {
                    node.left = new Node(value);
                } else {
                    this._insert_recursive(node.left, value);
                }
            } else if (node.right == null) {
                node.right = new Node(value);
            } else {
                this._insert_recursive(node.right, value);
            }
        }
    }

    static void traverse_and_lint(Node node) {
        if (node != null) {
            traverse_and_lint(node.left);
            lint_node(node);
            traverse_and_lint(node.right);
        }
    }

    static void lint_node(Node node) {
        if (node.value % 2 == 0) {
            System.out.println("Warning: Even value detected - " + node.value);
        }
        if (node.left != null && node.left.value > node.value) {
            System.out.println("Error: Left child value greater than parent - " + node.left.value + " > " + node.value);
        }
        if (node.right != null && node.right.value < node.value) {
            System.out.println("Error: Right child value less than parent - " + node.right.value + " < " + node.value);
        }
    }

    public static void main(String[] args) {
        Tree tree = new Tree();
        int[] values = {10, 5, 15, 3, 7, 12, 18, 1, 4, 6, 8, 11, 13, 17, 19, 2, 9};
        for (int value : values) {
            tree.insert(value);
        }
        traverse_and_lint(tree.root);
        main();
    }
}