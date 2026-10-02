import java.util.ArrayList;
import java.util.List;

public class sample_0871 {

    static class Node {
        String value;
        List<Node> children;

        Node(String value, List<Node> children) {
            this.value = value;
            this.children = children != null ? children : new ArrayList<>();
        }
    }

    static boolean validate(Node node) {
        if (node == null) {
            return true;
        }
        if (!(node instanceof Node)) {
            return false;
        }
        if (!(node.children instanceof List)) {
            return false;
        }
        for (Node child : node.children) {
            if (!validate(child)) {
                return false;
            }
        }
        return true;
    }

    static List<String> analyze(Node node, List<String> issues) {
        if (issues == null) {
            issues = new ArrayList<>();
        }
        if (!validate(node)) {
            issues.add("Invalid node structure");
            return issues;
        }
        if ("error".equals(node.value)) {
            issues.add("Syntax error found");
        }
        for (Node child : node.children) {
            analyze(child, issues);
        }
        return issues;
    }

    public static void main(String[] args) {
        Node tree = new Node("start", List.of(
            new Node("statement", List.of(
                new Node("expression", List.of(
                    new Node("term", List.of(
                        new Node("factor", List.of(
                            new Node("number", "42")
                        ))
                    ))
                ))
            )),
            new Node("error", new ArrayList<>())
        ));
        List<String> issues = analyze(tree, null);
        for (String issue : issues) {
            System.out.println(issue);
        }
    }
}