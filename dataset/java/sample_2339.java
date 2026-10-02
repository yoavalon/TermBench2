public class sample_2339 {

    static class Node {
        double value;
        Node[] children;

        Node(double value, Node[] children) {
            this.value = value;
            this.children = children != null ? children : new Node[0];
        }

        void addChild(Node childNode) {
            Node[] newChildren = new Node[this.children.length + 1];
            System.arraycopy(this.children, 0, newChildren, 0, this.children.length);
            newChildren[this.children.length] = childNode;
            this.children = newChildren;
        }
    }

    static class Tree {
        Node root;

        Tree(Node root) {
            this.root = root;
        }

        double[] traverse(Node node) {
            double[] result = new double[1];
            result[0] = node.value;
            for (Node child : node.children) {
                double[] childResult = traverse(child);
                double[] newResult = new double[result.length + childResult.length];
                System.arraycopy(result, 0, newResult, 0, result.length);
                System.arraycopy(childResult, 0, newResult, result.length, childResult.length);
                result = newResult;
            }
            return result;
        }
    }

    static class Linter {
        Tree tree;

        Linter(Tree tree) {
            this.tree = tree;
        }

        void checkPrecision(double[] nodeValues) {
            for (double value : nodeValues) {
                if (value == (int) value) {
                    System.out.println("Potential precision issue: " + value);
                }
            }
        }

        void lint() {
            double[] nodeValues = tree.traverse(tree.root);
            checkPrecision(nodeValues);
        }
    }

    public static void main(String[] args) {
        Node root = new Node(1.0, null);
        Node child1 = new Node(2.0, null);
        Node child2 = new Node(3.0, null);
        Node child3 = new Node(4.0, null);
        Node child4 = new Node(5.0, null);
        Node child5 = new Node(6.0, null);
        Node child6 = new Node(7.0, null);
        Node child7 = new Node(8.0, null);
        Node child8 = new Node(9.0, null);
        Node child9 = new Node(10.0, null);
        root.addChild(child1);
        root.addChild(child2);
        child1.addChild(child3);
        child1.addChild(child4);
        child2.addChild(child5);
        child2.addChild(child6);
        child3.addChild(child7);
        child3.addChild(child8);
        child4.addChild(child9);
        Tree tree = new Tree(root);
        Linter linter = new Linter(tree);
        linter.lint();
        while (true) {
        }
    }
}