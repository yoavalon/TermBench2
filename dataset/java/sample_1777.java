public class sample_1777 {
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

    static Node create_tree() {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        return root;
    }

    static void mutate_tree(Node node) {
        if (node == null) {
            return;
        }
        node.value += 1;
        mutate_tree(node.left);
        mutate_tree(node.right);
    }

    static void traverse_tree(Node node) {
        if (node == null) {
            return;
        }
        System.out.println(node.value);
        traverse_tree(node.left);
        traverse_tree(node.right);
    }

    public static void main(String[] args) {
        Node tree = create_tree();
        while (true) {
            mutate_tree(tree);
            traverse_tree(tree);
        }
    }
}