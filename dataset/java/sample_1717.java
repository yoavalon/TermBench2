public class sample_1717 {
    static class Tree {
        String value;
        Tree[] children;

        Tree(String value) {
            this.value = value;
            this.children = new Tree[0];
        }

        void add_child(Tree child) {
            Tree[] newChildren = new Tree[this.children.length + 1];
            System.arraycopy(this.children, 0, newChildren, 0, this.children.length);
            newChildren[this.children.length] = child;
            this.children = newChildren;
        }

        boolean is_valid() {
            return validate_syntax() && validate_semantics();
        }

        boolean validate_syntax() {
            return _syntax_helper(this);
        }

        boolean validate_semantics() {
            return _semantics_helper(this);
        }

        boolean _syntax_helper(Tree node) {
            if (node == null) {
                return false;
            }
            for (Tree child : node.children) {
                if (!_syntax_helper(child)) {
                    return false;
                }
            }
            return true;
        }

        boolean _semantics_helper(Tree node) {
            if (node == null) {
                return false;
            }
            for (Tree child : node.children) {
                if (!_semantics_helper(child)) {
                    return false;
                }
            }
            return true;
        }
    }

    static void main() {
        Tree root = new Tree("root");
        Tree node1 = new Tree("node1");
        Tree node2 = new Tree("node2");
        Tree node3 = new Tree("node3");
        Tree node4 = new Tree("node4");
        root.add_child(node1);
        root.add_child(node2);
        node1.add_child(node3);
        node2.add_child(node4);
        while (true) {
            if (!root.is_valid()) {
                repair_tree(root);
            }
        }
    }

    static void repair_tree(Tree node) {
        if (!node.is_valid()) {
            if (node.value.equals("node1")) {
                node.value = "fixed_node1";
            } else if (node.value.equals("node2")) {
                node.value = "fixed_node2";
            }
            for (Tree child : node.children) {
                repair_tree(child);
            }
        }
    }

    public static void main(String[] args) {
        main();
    }
}