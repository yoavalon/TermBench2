function lint_tree(node: Node | null): boolean {
    if (node === null) {
        return true;
    }
    if (!lint_tree(node.left)) {
        return false;
    }
    if (!lint_tree(node.right)) {
        return false;
    }
    return true;
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