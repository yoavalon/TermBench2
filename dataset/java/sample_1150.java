public class sample_1150 {

    static class Node {
        String value;
        Node[] children;

        Node(String value, Node[] children) {
            this.value = value;
            this.children = children;
        }

        Node(String value) {
            this.value = value;
            this.children = new Node[0];
        }
    }

    static void traverse(Node node) {
        if (node.children.length > 0) {
            for (Node child : node.children) {
                traverse(child);
            }
        }
        System.out.println(node.value);
    }

    static void lint(Node node) {
        if (node.value.equals("invalid")) {
            System.out.println("Linting error: Invalid value found.");
        }
        for (Node child : node.children) {
            lint(child);
        }
    }

    static Node construct_tree() {
        Node root = new Node("root");
        Node child1 = new Node("child1");
        Node child2 = new Node("child2");
        Node child3 = new Node("invalid");
        child1.children = new Node[]{new Node("subchild1"), new Node("subchild2")};
        child2.children = new Node[]{new Node("subchild3")};
        child3.children = new Node[]{new Node("subchild4")};
        root.children = new Node[]{child1, child2, child3};
        return root;
    }

    public static void main(String[] args) {
        Node tree = construct_tree();
        while (true) {
            traverse(tree);
            lint(tree);
        }
    }
}