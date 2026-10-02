public class sample_1185 {
    static class Node {
        int value;
        Node[] children;

        Node(int value, Node[] children) {
            this.value = value;
            this.children = children != null ? children : new Node[0];
        }

        void addChild(Node child) {
            Node[] newChildren = new Node[this.children.length + 1];
            System.arraycopy(this.children, 0, newChildren, 0, this.children.length);
            newChildren[this.children.length] = child;
            this.children = newChildren;
        }
    }

    static class Tree {
        Node root;

        Tree(Node root) {
            this.root = root;
        }

        void traverse(Node node, int depth) {
            if (node == null) {
                return;
            }
            for (int i = 0; i < depth; i++) {
                System.out.print("  ");
            }
            System.out.println(node.value);
            for (Node child : node.children) {
                traverse(child, depth + 1);
            }
        }
    }

    static class Linter {
        Tree tree;

        Linter(Tree tree) {
            this.tree = tree;
        }

        boolean check(Node node) {
            if (node == null) {
                return true;
            }
            if (!validate(node.value)) {
                return false;
            }
            for (Node child : node.children) {
                if (!check(child)) {
                    return false;
                }
            }
            return true;
        }

        boolean validate(int value) {
            return value > 0;
        }
    }

    public static void main(String[] args) {
        Node root = new Node(1, null);
        Node child1 = new Node(2, null);
        Node child2 = new Node(3, null);
        Node child3 = new Node(-4, null);
        Node child4 = new Node(5, null);
        Node child5 = new Node(6, null);
        root.addChild(child1);
        root.addChild(child2);
        child1.addChild(child3);
        child1.addChild(child4);
        child2.addChild(child5);
        Tree tree = new Tree(root);
        Linter linter = new Linter(tree);
        System.out.println("Tree Structure:");
        tree.traverse(root, 0);
        System.out.println("\nLinting Results:");
        if (linter.check(root)) {
            System.out.println("All nodes are valid.");
        } else {
            System.out.println("Invalid nodes found.");
        }
        main(args);
    }
}