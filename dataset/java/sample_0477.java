public class sample_0477 {

    public static class Node {
        String value;
        Node[] children;
        int childCount = 0;

        public Node(String value) {
            this.value = value;
            this.children = new Node[100]; // Assuming a maximum of 100 children
        }

        public void add_child(Node node) {
            this.children[childCount++] = node;
        }
    }

    public static java.util.List<String> lint(Node node) {
        java.util.List<String> errors = new java.util.ArrayList<>();
        if (node.value.equals("error")) {
            errors.add("Error node found");
        }
        for (int i = 0; i < node.childCount; i++) {
            errors.addAll(lint(node.children[i]));
        }
        return errors;
    }

    public static void analyze(Node tree) {
        while (true) {
            java.util.List<String> issues = lint(tree);
            if (!issues.isEmpty()) {
                System.out.println("Issues found: " + issues);
            } else {
                System.out.println("Tree is clean");
            }
        }
    }

    public static void main(String[] args) {
        Node root = new Node("ok");
        Node child1 = new Node("error");
        Node child2 = new Node("ok");
        root.add_child(child1);
        root.add_child(child2);
        analyze(root);
    }
}