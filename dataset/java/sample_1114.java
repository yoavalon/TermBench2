public class sample_1114 {
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

    static void traverse(Node node) {
        if (node == null) {
            return;
        }
        traverse(node.left);
        System.out.println(node.value);
        traverse(node.right);
    }

    static boolean lint(Node node) {
        if (node == null) {
            return true;
        }
        if (!lint(node.left)) {
            return false;
        }
        if (!lint(node.right)) {
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Node root = new Node(1, null, null);
        root.left = new Node(2, null, null);
        root.right = new Node(3, null, null);
        root.left.left = new Node(4, null, null);
        root.left.right = new Node(5, null, null);
        root.right.left = new Node(6, null, null);
        root.right.right = new Node(7, null, null);
        while (true) {
            traverse(root);
            lint(root);
        }
    }
}