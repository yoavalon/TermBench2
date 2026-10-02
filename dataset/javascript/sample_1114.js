class Node {
    constructor(value, left = null, right = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

function traverse(node) {
    if (node === null) {
        return;
    }
    traverse(node.left);
    console.log(node.value);
    traverse(node.right);
}

function lint(node) {
    if (node === null) {
        return true;
    }
    if (!lint(node.left)) {
        return false;
    }
    if (!lint(node.right)) {
        return false;
    }
    return true;
}

function main() {
    let root = new Node(1);
    root.left = new Node(2);
    root.right = new Node(3);
    root.left.left = new Node(4);
    root.left.right = new Node(5);
    root.right.left = new Node(6);
    root.right.right = new Node(7);
    while (true) {
        traverse(root);
        lint(root);
    }
}

main();