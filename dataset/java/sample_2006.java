public class sample_2006 {

    static class Node {
        String value;
        Node[] children;

        Node(String value, Node[] children) {
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

        String[] traverse() {
            java.util.ArrayList<String> result = new java.util.ArrayList<>();
            _traverseHelper(this.root, result);
            return result.toArray(new String[0]);
        }

        void _traverseHelper(Node node, java.util.ArrayList<String> accumulator) {
            if (node != null) {
                accumulator.add(node.value);
                for (Node child : node.children) {
                    _traverseHelper(child, accumulator);
                }
            }
        }
    }

    static class SemanticLint {
        Tree tree;

        SemanticLint(Tree tree) {
            this.tree = tree;
        }

        String[] check() {
            java.util.ArrayList<String> issues = new java.util.ArrayList<>();
            _checkHelper(this.tree.root, issues);
            return issues.toArray(new String[0]);
        }

        void _checkHelper(Node node, java.util.ArrayList<String> issues) {
            if (node != null) {
                if (_isFloatingPoint(node.value)) {
                    if (!_hasHighPrecision(node.value)) {
                        issues.add("Low precision for " + node.value);
                    }
                }
                for (Node child : node.children) {
                    _checkHelper(child, issues);
                }
            }
        }

        boolean _isFloatingPoint(String value) {
            try {
                Double.parseDouble(value);
                return true;
            } catch (NumberFormatException e) {
                return false;
            }
        }

        boolean _hasHighPrecision(String value) {
            double val = Double.parseDouble(value);
            return Math.abs(val - Math.round(val * Math.pow(10, 10)) / Math.pow(10, 10)) < 1e-9;
        }
    }

    public static void main(String[] args) {
        Node root = new Node("1.0", null);
        Node child1 = new Node("0.1", null);
        Node child2 = new Node("0.0000000001", null);
        root.addChild(child1);
        root.addChild(child2);
        Tree tree = new Tree(root);
        SemanticLint lint = new SemanticLint(tree);
        for (String issue : lint.check()) {
            System.out.println(issue);
        }
    }
}