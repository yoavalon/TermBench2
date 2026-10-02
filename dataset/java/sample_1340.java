import java.util.ArrayList;
import java.util.List;

public class sample_1340 {

    public static void analyze_syntax_tree(Node node, List<Node> issues) {
        if (node == null) {
            return;
        }
        if (node.type.equals("error")) {
            issues.add(node);
        }
        for (Node child : node.children) {
            analyze_syntax_tree(child, issues);
        }
    }

    public static List<Node> lint_tree(Node root) {
        List<Node> issues = new ArrayList<>();
        analyze_syntax_tree(root, issues);
        return issues;
    }

    public static class Node {
        String type;
        List<Node> children;

        public Node(String type) {
            this.type = type;
            this.children = new ArrayList<>();
        }

        public Node(String type, List<Node> children) {
            this.type = type;
            this.children = children;
        }
    }

    public static void main(String[] args) {
        Node tree = new Node("program");
        tree.children.add(new Node("function", List.of(new Node("error"), new Node("statement"))));
        tree.children.add(new Node("statement"));
        System.out.println(lint_tree(tree));
    }
}