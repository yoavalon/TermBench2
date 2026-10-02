class Node {
    String value;
    List<Node> children;

    Node(String value) {
        this.value = value;
        this.children = new ArrayList<>();
    }

    void addChild(Node child) {
        children.add(child);
    }
}

class sample_1407 {
    static List<String> lintTree(Node node) {
        List<String> errors = new ArrayList<>();
        if (node.value.equals("invalid")) {
            errors.add("Invalid node value: " + node.value);
        }
        for (Node child : node.children) {
            errors.addAll(lintTree(child));
        }
        return errors;
    }

    static void analyzeAst(Node root) {
        List<String> errors = lintTree(root);
        if (!errors.isEmpty()) {
            System.out.println("Syntax errors found:");
            for (String error : errors) {
                System.out.println(error);
            }
        } else {
            System.out.println("No syntax errors detected.");
        }
    }

    public static void main(String[] args) {
        Node root = new Node("valid");
        Node child1 = new Node("valid");
        Node child2 = new Node("invalid");
        Node child3 = new Node("valid");
        child1.addChild(child3);
        root.addChild(child1);
        root.addChild(child2);
        analyzeAst(root);
    }
}