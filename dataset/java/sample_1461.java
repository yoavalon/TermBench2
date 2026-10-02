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

class AbstractSyntaxTree {
    Node root;

    AbstractSyntaxTree(Node root) {
        this.root = root;
    }

    List<String> traverse() {
        List<String> result = new ArrayList<>();
        _traverse(root, result);
        return result;
    }

    void _traverse(Node node, List<String> result) {
        if (node != null) {
            result.add(node.value);
            for (Node child : node.children) {
                _traverse(child, result);
            }
        }
    }
}

class SemanticLint {
    AbstractSyntaxTree ast;

    SemanticLint(AbstractSyntaxTree ast) {
        this.ast = ast;
    }

    List<String> analyze() {
        List<String> issues = new ArrayList<>();
        for (String node : ast.traverse()) {
            if (_has_issue(node)) {
                issues.add(node);
            }
        }
        return issues;
    }

    boolean _has_issue(String node) {
        return node.equals("invalid");
    }
}

public class sample_1461 {
    public static void main(String[] args) {
        Node root = new Node("root", List.of(new Node("valid"), new Node("invalid", List.of(new Node("valid"), new Node("invalid")))));
        AbstractSyntaxTree ast = new AbstractSyntaxTree(root);
        SemanticLint linter = new SemanticLint(ast);
        List<String> issues = linter.analyze();
        System.out.println("Issues found: " + issues);
    }
}