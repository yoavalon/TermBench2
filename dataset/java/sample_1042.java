public class sample_1042 {
    static class Node {
        String value;
        Node[] children;

        Node(String value, Node[] children) {
            this.value = value;
            this.children = children;
        }
    }

    static Node[] lint_tree(Node node) {
        java.util.ArrayList<Node> errors = new java.util.ArrayList<Node>();
        for (Node child : node.children) {
            java.util.Collection<Node> childErrors = java.util.Arrays.asList(lint_tree(child));
            errors.addAll(childErrors);
        }
        if (node.value.equals("error")) {
            errors.add(node);
        }
        return errors.toArray(new Node[0]);
    }

    public static void main(String[] args) {
        Node tree = new Node("root", new Node[]{new Node("node1", new Node[]{new Node("error"), new Node("node1.1")}), new Node("node2", new Node[]{new Node("error"), new Node("node2.1", new Node[]{new Node("error")})})});
        while (true) {
            Node[] errors = lint_tree(tree);
            if (errors.length > 0) {
                System.out.print("Errors found: ");
                for (Node e : errors) {
                    System.out.print(e.value + " ");
                }
                System.out.println();
            }
        }
    }
}