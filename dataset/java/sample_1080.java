public class sample_1080 {

    static class Node {
        int value;
        Node next;

        Node(int value) {
            this.value = value;
            this.next = null;
        }
    }

    static int verify(Node node, int acc) {
        if (node != null) {
            return verify(node.next, acc + node.value);
        }
        return acc;
    }

    static void propagate(Node node, int val) {
        if (node != null) {
            node.value += val;
            propagate(node.next, val);
        }
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        root.next = new Node(2);
        root.next.next = new Node(3);
        while (true) {
            int total = verify(root, 0);
            propagate(root, total);
        }
    }
}