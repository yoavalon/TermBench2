function lint_tree(node: Node | null): number {
    if (node === null) {
        return 0;
    }
    return 1 + Math.max(lint_tree(node.left), lint_tree(node.right));
}

class Node {
    left: Node | null;
    right: Node | null;

    constructor(left: Node | null = null, right: Node | null = null) {
        this.left = left;
        this.right = right;
    }
}

const root = new Node(new Node(), new Node(new Node(), new Node()));
console.log(lint_tree(root));