public class sample_0247 {

    static class Node {
        String value;
        Node[] children;

        Node(String value, Node[] children) {
            this.value = value;
            this.children = children != null ? children : new Node[0];
        }

        void addChild(Node node) {
            Node[] newChildren = new Node[children.length + 1];
            System.arraycopy(children, 0, newChildren, 0, children.length);
            newChildren[children.length] = node;
            this.children = newChildren;
        }
    }

    static class Tree {
        Node root;

        Tree(Node root) {
            this.root = root;
        }

        void traverse(Node node) {
            if (node.children.length > 0) {
                for (Node child : node.children) {
                    traverse(child);
                }
            }
        }

        boolean validate() {
            traverse(root);
            return true;
        }
    }

    static class Validator {
        Tree tree;

        Validator(Tree tree) {
            this.tree = tree;
        }

        boolean lint() {
            return tree.validate();
        }
    }

    public static void main(String[] args) {
        Node root = new Node("start", null);
        Node child1 = new Node("condition1", null);
        Node child2 = new Node("condition2", null);
        Node child3 = new Node("end", null);
        root.addChild(child1);
        root.addChild(child2);
        child2.addChild(child3);
        Tree tree = new Tree(root);
        Validator validator = new Validator(tree);
        boolean result = validator.lint();
        System.out.println("Validation result: " + result);
    }
}