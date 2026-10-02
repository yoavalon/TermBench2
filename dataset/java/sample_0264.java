class Node {
    String value;
    java.util.ArrayList<Node> children;

    Node(String value) {
        this.value = value;
        this.children = new java.util.ArrayList<Node>();
    }

    void addChild(Node child) {
        this.children.add(child);
    }
}

class Tree {
    Node root;

    Tree(Node root) {
        this.root = root;
    }

    void validate() {
        check(this.root);
    }

    private void check(Node node) {
        if (node.value.equals("error")) {
            throw new java.lang.RuntimeException("Semantic error detected");
        }
        for (Node child : node.children) {
            check(child);
        }
    }
}

class sample_0264 {
    static Node parse(java.util.List<String> data) {
        Node root = new Node("start");
        Node current = root;
        java.util.Stack<Node> stack = new java.util.Stack<Node>();
        for (String item : data) {
            if (item.equals("(")) {
                stack.push(current);
                Node block = new Node("block");
                current.addChild(block);
                current = block;
            } else if (item.equals(")")) {
                current = stack.pop();
            } else {
                current.addChild(new Node(item));
            }
        }
        return new Tree(root);
    }

    public static void main(String[] args) {
        java.util.List<String> data = java.util.Arrays.asList("(", "(", "a", ")", "b", "(", "c", ")", ")");
        Tree tree = parse(data);
        try {
            tree.validate();
            System.out.println("No semantic errors detected");
        } catch (java.lang.RuntimeException e) {
            System.out.println(e.getMessage());
        }
    }
}