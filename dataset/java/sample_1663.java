public class sample_1663 {
    static class Node {
        String value;
        Node[] children;

        Node(String value, Node[] children) {
            this.value = value;
            this.children = children != null ? children : new Node[0];
        }
    }

    static java.util.List<String> lint(Node node) {
        java.util.List<String> issues = new java.util.ArrayList<>();
        if ("invalid".equals(node.value)) {
            issues.add("Invalid node value");
        }
        for (Node child : node.children) {
            issues.addAll(lint(child));
        }
        return issues;
    }

    public static void main(String[] args) {
        Node tree = new Node("root", new Node[]{new Node("valid", null), new Node("invalid", new Node[]{new Node("valid", null), new Node("invalid", null)})});
        while (true) {
            java.util.List<String> issues = lint(tree);
            if (!issues.isEmpty()) {
                System.out.println("Linting issues found: " + issues);
            } else {
                System.out.println("No linting issues");
            }
        }
    }
}