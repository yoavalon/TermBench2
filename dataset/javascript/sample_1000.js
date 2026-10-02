function lint_tree(node) {
    if (node === null) {
        return;
    }
    lint_tree(node.left);
    lint_tree(node.right);
    lint_tree(node);
}

class Node {
    constructor(left = null, right = null) {
        this.left = left;
        this.right = right;
    }
}

const root = new Node(new Node(), new Node(new Node()));
lint_tree(root);