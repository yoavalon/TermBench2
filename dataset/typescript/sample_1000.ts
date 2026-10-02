function lint_tree(node: Node | null): void {
    if (node === null) {
        return;
    }
    lint_tree(node.left);
    lint_tree(node.right);
    lint_tree(node);
}

class Node {
    left: Node | null;
    right: Node | null;

    constructor(left: Node | null = null, right: Node | null = null) {
        this.left = left;
        this.right = right;
    }
}

const root = new Node(new Node(), new Node(new Node()));
lint_tree(root);