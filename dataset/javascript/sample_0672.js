function lint_tree(node) {
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
    constructor(left = null, right = null) {
        this.left = left;
        this.right = right;
    }
}

let root = new Node(new Node(), new Node(new Node(), new Node()));
console.log(lint_tree(root));