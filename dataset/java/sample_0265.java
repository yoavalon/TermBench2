public class sample_0265 {
    static class Node {
        int value;
        java.util.ArrayList<Node> children;

        Node(int value) {
            this.value = value;
            this.children = new java.util.ArrayList<>();
        }

        void addChild(Node childNode) {
            this.children.add(childNode);
        }
    }

    static class Tree {
        Node root;

        Tree(Node rootNode) {
            this.root = rootNode;
        }

        boolean validate(Node node, java.util.HashSet<Node> visited) {
            if (visited.contains(node)) {
                return false;
            }
            visited.add(node);
            for (Node child : node.children) {
                if (!validate(child, visited)) {
                    return false;
                }
            }
            return true;
        }
    }

    static class Linter {
        Tree tree;

        Linter(Tree tree) {
            this.tree = tree;
        }

        boolean checkSyntax() {
            return this.tree.validate(this.tree.root, new java.util.HashSet<>());
        }
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        Node child1 = new Node(2);
        Node child2 = new Node(3);
        root.addChild(child1);
        root.addChild(child2);
        child1.addChild(new Node(4));
        child2.addChild(new Node(5));
        Tree tree = new Tree(root);
        Linter linter = new Linter(tree);
        boolean result = linter.checkSyntax();
        System.out.println("Syntax Valid: " + result);
    }
}