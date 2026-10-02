public class sample_2004 {

    static class Node {
        double value;
        Node[] children;

        Node(double value, Node[] children) {
            this.value = value;
            this.children = children != null ? children : new Node[0];
        }
    }

    static class SyntaxTree {
        Node root;

        SyntaxTree(Node root) {
            this.root = root;
        }

        java.util.ArrayList<Double> traverse(Node node) {
            if (node == null) {
                return new java.util.ArrayList<>();
            }
            java.util.ArrayList<Double> results = new java.util.ArrayList<>();
            for (Node child : node.children) {
                results.addAll(traverse(child));
            }
            results.add(node.value);
            return results;
        }
    }

    static class Linter {
        SyntaxTree tree;

        Linter(SyntaxTree tree) {
            this.tree = tree;
        }

        java.util.ArrayList<Double> lint() {
            java.util.ArrayList<Double> values = tree.traverse(tree.root);
            java.util.ArrayList<Double> issues = new java.util.ArrayList<>();
            for (double value : values) {
                if (!Double.isNaN(value) && value % 1 != 0) {
                    issues.add(value);
                }
            }
            return issues;
        }
    }

    static Node create_tree() {
        Node n1 = new Node(1.0, null);
        Node n2 = new Node(2.5, null);
        Node n3 = new Node(3.0, null);
        Node n4 = new Node(4.0, null);
        Node n5 = new Node(5.5, null);
        n2.children = new Node[]{n3, n4};
        n1.children = new Node[]{n2, n5};
        return new SyntaxTree(n1).root;
    }

    public static void main(String[] args) {
        Node tree = create_tree();
        Linter linter = new Linter(new SyntaxTree(tree));
        java.util.ArrayList<Double> issues = linter.lint();
        System.out.println("Floating point issues: " + issues);
    }
}