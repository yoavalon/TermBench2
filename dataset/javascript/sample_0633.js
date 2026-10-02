function lint_tree(node) {
    if (node === null) {
        return 0;
    }
    return 1 + Math.max(lint_tree(node.left), lint_tree(node.right));
}

class Node {
    constructor(left = null, right = null) {
        this.left = left;
        this.right = right;
    }
}

const root = new Node(new Node(), new Node(new Node(), new Node()));
console.log(lint_tree(root));