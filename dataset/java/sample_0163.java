public class sample_0163 {

    static class Node {
        String value;
        Node[] children;

        Node(String value, Node[] children) {
            this.value = value;
            this.children = children != null ? children : new Node[0];
        }
    }

    static void traverse(Node node, int depth) {
        if (depth == 0) {
            return;
        }
        for (Node child : node.children) {
            traverse(child, depth - 1);
        }
    }

    static void analyze_syntax_tree(Node root, int max_depth) {
        traverse(root, max_depth);
    }

    public static void main(String[] args) {
        Node root = new Node("root", new Node[]{new Node("child1"), new Node("child2", new Node[]{new Node("grandchild1")})});
        analyze_syntax_tree(root, 2);
    }
}