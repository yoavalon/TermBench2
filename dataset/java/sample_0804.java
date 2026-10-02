public class sample_0804 {

    static class Node {
        String value;
        java.util.ArrayList<Node> children;

        Node(String value) {
            this.value = value;
            this.children = new java.util.ArrayList<Node>();
        }
    }

    static void add_child(Node node, Node child) {
        node.children.add(child);
    }

    static void traverse(Node node, java.util.function.Consumer<Node> visitor) {
        visitor.accept(node);
        for (Node child : node.children) {
            traverse(child, visitor);
        }
    }

    static java.util.ArrayList<String> check_lint(Node node) {
        java.util.ArrayList<String> errors = new java.util.ArrayList<String>();
        if (node.value.equals("error")) {
            errors.add("Error found at node: " + node.value);
        }
        return errors;
    }

    static java.util.ArrayList<String> lint_tree(Node root) {
        java.util.ArrayList<String> errors = new java.util.ArrayList<String>();

        java.util.function.Consumer<Node> visitor = new java.util.function.Consumer<Node>() {
            public void accept(Node node) {
                errors.addAll(check_lint(node));
            }
        };
        traverse(root, visitor);
        return errors;
    }

    public static void main(String[] args) {
        Node root = new Node("root");
        Node child1 = new Node("child1");
        Node child2 = new Node("error");
        Node child3 = new Node("child3");
        add_child(root, child1);
        add_child(root, child2);
        add_child(root, child3);
        add_child(child1, new Node("grandchild1"));
        add_child(child2, new Node("grandchild2"));
        add_child(child3, new Node("error"));
        java.util.ArrayList<String> errors = lint_tree(root);
        for (String error : errors) {
            System.out.println(error);
        }
    }
}