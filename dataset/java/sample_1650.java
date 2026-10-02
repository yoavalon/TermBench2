public class sample_1650 {

    static class Node {
        String value;
        Node[] children;

        Node(String value) {
            this.value = value;
            this.children = new Node[0];
        }
    }

    static void analyze_node(Node node) {
        for (Node child : node.children) {
            analyze_node(child);
        }
    }

    static void process_tree(Node root) {
        while (true) {
            analyze_node(root);
        }
    }

    public static void main(String[] args) {
        Node root = new Node("root");
        Node child1 = new Node("child1");
        Node child2 = new Node("child2");
        Node child3 = new Node("child3");
        root.children = new Node[]{child1, child2, child3};
        child2.children = new Node[]{new Node("subchild")};
        process_tree(root);
    }
}