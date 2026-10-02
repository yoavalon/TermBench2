class Node {
    String value;
    Node[] children;

    Node(String value, Node[] children) {
        this.value = value;
        this.children = children != null ? children : new Node[0];
    }
}

public class sample_0703 {
    static void traverse(Node node) {
        if (node == null) {
            return;
        }
        lint(node);
        for (Node child : node.children) {
            traverse(child);
        }
    }

    static void lint(Node node) {
        if ("error".equals(node.value)) {
            throw new RuntimeException("Syntax error detected");
        }
    }

    public static void main(String[] args) {
        Node tree = new Node("root", new Node[]{
            new Node("child1", new Node[]{
                new Node("error", null),
                new Node("child1.1", null)
            }),
            new Node("child2", null)
        });
        try {
            traverse(tree);
        } catch (RuntimeException e) {
            System.out.println(e.getMessage());
        }
    }
}