import java.util.ArrayList;
import java.util.List;

class Node {
    int value;
    List<Node> children;

    Node(int value, List<Node> children) {
        this.value = value;
        this.children = children;
    }
}

class sample_1342 {
    static List<String> lint_tree(Node node) {
        List<String> errors = new ArrayList<>();
        if (node instanceof Node) {
            if (node.children.isEmpty() && node.value < 0) {
                errors.add("Negative value at node with value " + node.value);
            }
            for (Node child : node.children) {
                errors.addAll(lint_tree(child));
            }
        }
        return errors;
    }

    public static void main(String[] args) {
        Node tree = new Node(10, List.of(new Node(5), new Node(-3, List.of(new Node(2), new Node(-1)))));
        List<String> errors = lint_tree(tree);
        if (!errors.isEmpty()) {
            System.out.println("Linting Errors Found:");
            for (String error : errors) {
                System.out.println(error);
            }
        } else {
            System.out.println("No linting errors found.");
        }
    }
}