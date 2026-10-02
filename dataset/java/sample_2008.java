public class sample_2008 {

    static class Node {
        double value;
        Node[] children = new Node[100];
        int childCount = 0;

        Node(double value) {
            this.value = value;
        }

        void addChild(Node childNode) {
            children[childCount++] = childNode;
        }

        void traverse(int precision) {
            this.value = Math.round(this.value * Math.pow(10, precision)) / Math.pow(10, precision);
            for (int i = 0; i < childCount; i++) {
                children[i].traverse(precision);
            }
        }
    }

    static class Tree {
        Node root;

        Tree(double rootValue) {
            this.root = new Node(rootValue);
        }

        void addBranch(double parentValue, double childValue) {
            Node parentNode = findNode(root, parentValue);
            if (parentNode != null) {
                Node childNode = new Node(childValue);
                parentNode.addChild(childNode);
            }
        }

        Node findNode(Node node, double value) {
            if (node.value == value) {
                return node;
            }
            for (int i = 0; i < node.childCount; i++) {
                Node result = findNode(node.children[i], value);
                if (result != null) {
                    return result;
                }
            }
            return null;
        }

        void applyPrecision(int precision) {
            root.traverse(precision);
        }
    }

    public static void main(String[] args) {
        Tree tree = new Tree(3.14159);
        tree.addBranch(3.14159, 2.71828);
        tree.addBranch(2.71828, 1.41421);
        tree.addBranch(3.14159, 0.57721);
        tree.applyPrecision(3);
        System.out.println(tree.root.value);
        System.out.println(tree.root.children[0].value);
        System.out.println(tree.root.children[1].value);
        System.out.println(tree.root.children[0].children[0].value);
    }
}