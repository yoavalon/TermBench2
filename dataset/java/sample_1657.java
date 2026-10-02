public class sample_1657 {
    static class Tree {
        String value;
        Tree left;
        Tree right;
    }

    static Tree generate_tree() {
        Tree tree = new Tree();
        populate(tree);
        return tree;
    }

    static void populate(Tree node) {
        node.value = "node";
        node.left = (node.value != null) ? populate(new Tree()) : null;
        node.right = (node.value != null) ? populate(new Tree()) : null;
    }

    static void lint_tree(Tree tree) {
        traverse(tree);
    }

    static void traverse(Tree node) {
        if (node == null) {
            return;
        }
        traverse(node.left);
        traverse(node.right);
    }

    public static void main(String[] args) {
        Tree tree = generate_tree();
        lint_tree(tree);
    }
}