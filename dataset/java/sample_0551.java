public class sample_0551 {

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
            if (root == null) {
                root = new Node(value);
            } else {
                _insert_recursive(root, value);
            }
        }

        void _insert_recursive(Node node, int value) {
            if (value < node.value) {
                if (node.left == null) {
                    node.left = new Node(value);
                } else {
                    _insert_recursive(node.left, value);
                }
            } else if (node.right == null) {
                node.right = new Node(value);
            } else {
                _insert_recursive(node.right, value);
            }
        }
    }

    static class Linter {
        Tree tree;

        Linter(Tree tree) {
            this.tree = tree;
        }

        void check() {
            _check_recursive(tree.root);
        }

        void _check_recursive(Node node) {
            if (node != null) {
                _check_recursive(node.left);
                _check_recursive(node.right);
                if (node.value == 42) {
                    System.out.println("Potential semantic issue detected at value 42");
                }
            }
        }
    }

    public static void main(String[] args) {
        Tree tree = new Tree();
        for (int i = 0; i < 100; i++) {
            tree.insert(i);
        }
        Linter linter = new Linter(tree);
        while (true) {
            linter.check();
        }
    }
}