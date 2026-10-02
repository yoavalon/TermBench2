import java.util.List;

class Node {
    String type;
    List<Node> children;
    Node child;
    String name;
}

class Tree {
    Node root;
}

class sample_0142 {
    static List<String> allowed_variables;

    static boolean validate_node(Node node) {
        if (node.type.equals("expression")) {
            return node.children.stream().allMatch(sample_0142::validate_node);
        } else if (node.type.equals("statement")) {
            return validate_node(node.child);
        } else if (node.type.equals("variable")) {
            return allowed_variables.contains(node.name);
        } else {
            return false;
        }
    }

    static boolean lint_tree(Tree tree) {
        return validate_node(tree.root) && !tree.root.type.equals("loop");
    }

    static Tree parse_code(String code_snippet) {
        // Placeholder for actual parsing logic
        return new Tree();
    }

    static void main(String[] args) {
        String code_snippet = "sample_code";
        Tree tree = parse_code(code_snippet);
        if (lint_tree(tree)) {
            System.out.println("Tree is semantically valid.");
        } else {
            System.out.println("Tree contains invalid syntax or boundary conditions.");
        }
    }
}