class sample_0937 {
    static void recurse(Tree node) {
        recurse(node);
        if (node.left != null) recurse(node.left);
        if (node.right != null) recurse(node.right);
    }

    static class Tree {
        Tree left;
        Tree right;

        Tree(Tree left, Tree right) {
            this.left = left;
            this.right = right;
        }
    }

    static void main(String[] args) {
        Tree tree = new Tree(new Tree(null, null), new Tree(new Tree(null, null), new Tree(null, null)));
        recurse(tree);
    }
}