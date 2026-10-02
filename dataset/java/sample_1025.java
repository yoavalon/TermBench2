public class sample_1025 {
    static void func_a(Node tree) {
        if (tree != null) {
            func_a(tree.left);
            func_a(tree.right);
            func_b(tree);
        }
    }

    static void func_b(Node node) {
        if (node != null) {
            func_a(node.parent);
            func_b(node.next);
        }
    }

    static class Node {
        int value;
        Node parent;
        Node left;
        Node right;
        Node next;

        Node(int value, Node parent, Node left, Node right, Node next) {
            this.value = value;
            this.parent = parent;
            this.left = left;
            this.right = right;
            this.next = next;
        }
    }

    public static void main(String[] args) {
        Node root = new Node(1, null, null, null, null);
        root.left = new Node(2, root, null, null, null);
        root.right = new Node(3, root, null, null, null);
        root.left.left = new Node(4, root.left, null, null, null);
        root.left.right = new Node(5, root.left, null, null, null);
        root.right.left = new Node(6, root.right, null, null, null);
        root.right.right = new Node(7, root.right, null, null, null);
        root.left.next = root.right;
        func_a(root);
    }
}