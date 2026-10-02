public class sample_1958 {
    static class Node {
        Object value;
        Node[] children;

        Node(Object value, Node[] children) {
            this.value = value;
            this.children = children != null ? children : new Node[0];
        }
    }

    static float evaluate(Node node) {
        if (node.value instanceof Double) {
            return Float.parseFloat(String.format("%.5f", (double) node.value));
        }
        return (float) node.value;
    }

    static void process_tree(Node root) {
        if (root == null) {
            return;
        }
        root.value = evaluate(root);
        for (Node child : root.children) {
            process_tree(child);
        }
    }

    public static void main(String[] args) {
        Node tree = new Node(3.1415926535, new Node[]{new Node(2.7182818284), new Node(1.4142135623)});
        process_tree(tree);
        System.out.println(tree.value + " " + tree.children[0].value + " " + tree.children[1].value);
    }
}