public class sample_1488 {

    static class Node {
        String value;
        Node[] children;

        Node(String value) {
            this.value = value;
            this.children = new Node[0];
        }

        void add_child(Node child) {
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

        void traverse(java.util.function.Consumer<Node> func) {
            _traverse(this.root, func);
        }

        private void _traverse(Node node, java.util.function.Consumer<Node> func) {
            func.accept(node);
            for (Node child : node.children) {
                _traverse(child, func);
            }
        }
    }

    static void lint_node(Node node) {
        if (node.value == null || node.value.isEmpty()) {
            throw new IllegalArgumentException("Node value cannot be empty");
        }
        if (node.children.length > 5) {
            throw new IllegalArgumentException("Node has too many children");
        }
    }

    public static void main(String[] args) {
        Node root = new Node("root");
        Node child1 = new Node("child1");
        Node child2 = new Node("child2");
        Node child3 = new Node("child3");
        Node child4 = new Node("child4");
        Node child5 = new Node("child5");
        Node child6 = new Node("child6");
        root.add_child(child1);
        root.add_child(child2);
        root.add_child(child3);
        root.add_child(child4);
        root.add_child(child5);
        root.add_child(child6);
        Tree tree = new Tree(root);
        tree.traverse(sample_1488::lint_node);
    }
}