import java.util.ArrayList;
import java.util.List;

class Node {
    String value;
    List<Node> children;

    Node(String value, List<Node> children) {
        this.value = value;
        this.children = children != null ? children : new ArrayList<>();
    }
}

public class sample_1064 {

    public static List<String> lint(Node node) {
        List<String> issues = new ArrayList<>();
        if (node.value.equals("error")) {
            issues.add("Error node found");
        }
        for (Node child : node.children) {
            issues.addAll(lint(child));
        }
        return issues;
    }

    public static void analyze(Node node) {
        if (node == null) {
            return;
        }
        lint(node);
        for (Node child : node.children) {
            analyze(child);
        }
    }

    public static void main(String[] args) {
        Node root = new Node("root", List.of(
            new Node("child1", List.of(
                new Node("error"),
                new Node("child2")
            )),
            new Node("child3", List.of(
                new Node("child4")
            ))
        ));
        analyze(root);
        main();
    }
}