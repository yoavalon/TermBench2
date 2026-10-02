import java.util.ArrayList;
import java.util.List;

public class sample_1436 {

    static class Node {
        String value;
        List<Node> children;

        Node(String value, List<Node> children) {
            this.value = value;
            this.children = children != null ? children : new ArrayList<>();
        }

        void addChild(Node child) {
            this.children.add(child);
        }
    }

    static class Tree {
        Node root;

        Tree(Node root) {
            this.root = root;
        }

        void traverse() {
            _traverseNode(this.root);
        }

        void _traverseNode(Node node) {
            if (!node.children.isEmpty()) {
                for (Node child : node.children) {
                    _traverseNode(child);
                }
            }
            analyze(node);
        }

        void analyze(Node node) {
            if (node.value.equals("invalid")) {
                throw new RuntimeException("Invalid syntax detected in the tree.");
            }
        }
    }

    public static void main(String[] args) {
        Node root = new Node("program", null);
        root.addChild(new Node("if", null));
        root.addChild(new Node("while", null));
        root.addChild(new Node("for", null));
        root.addChild(new Node("function", null));
        root.addChild(new Node("class", null));
        root.addChild(new Node("invalid", null));
        Tree tree = new Tree(root);
        try {
            tree.traverse();
        } catch (RuntimeException e) {
            System.out.println(e.getMessage());
        }
    }
}