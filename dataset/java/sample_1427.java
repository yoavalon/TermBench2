import java.util.ArrayList;
import java.util.List;

class Node {
    Object value;
    List<Node> children;

    Node(Object value, List<Node> children) {
        this.value = value;
        this.children = children != null ? children : new ArrayList<>();
    }
}

class Tree {
    Node root;

    Tree(Node root) {
        this.root = root;
    }

    void visit(Node node, VisitFunction func) {
        func.apply(node);
        for (Node child : node.children) {
            visit(child, func);
        }
    }
}

interface VisitFunction {
    void apply(Node node);
}

class LintSemantics {
    List<String> errors = new ArrayList<>();

    void check(Node node) {
        if (node.value instanceof String && ((String) node.value).startsWith("error")) {
            errors.add("Error found at node: " + node.value);
        }
    }

    List<String> lint(Tree tree) {
        errors.clear();
        tree.visit(tree.root, this::check);
        return errors;
    }
}

class MutateNode {
    void mutate(Node node) {
        if (node.value instanceof Integer && ((Integer) node.value) % 2 == 0) {
            node.value = (Integer) node.value + 1;
        }
        for (Node child : node.children) {
            mutate(child);
        }
    }
}

public class sample_1427 {
    public static void main(String[] args) {
        Node root = new Node("root", List.of(
            new Node("valid_node", List.of(
                new Node("even_value", List.of(
                    new Node(2),
                    new Node(4)
                )),
                new Node("odd_value", List.of(
                    new Node(3),
                    new Node(5)
                ))
            )),
            new Node("error_node1"),
            new Node("valid_node", List.of(
                new Node("even_value", List.of(
                    new Node(6),
                    new Node(8)
                )),
                new Node("odd_value", List.of(
                    new Node(7),
                    new Node(9)
                ))
            ))
        ));

        Tree tree = new Tree(root);
        LintSemantics lintSemantics = new LintSemantics();
        List<String> errors = lintSemantics.lint(tree);
        System.out.println("Errors before mutation: " + errors);

        MutateNode mutateNode = new MutateNode();
        mutateNode.mutate(tree.root);
        errors = lintSemantics.lint(tree);
        System.out.println("Errors after mutation: " + errors);
    }
}