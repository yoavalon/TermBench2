function lintTree(node) {
    if (node === null) {
        return true;
    }
    if (!lintNode(node)) {
        return false;
    }
    return lintTree(node.left) && lintTree(node.right);
}

function lintNode(node) {
    return typeof node.value === 'number' && node.value > 0;
}

function createTree(depth) {
    if (depth === 0) {
        return null;
    }
    return new Node(1, createTree(depth - 1), createTree(depth - 1));
}

class Node {
    constructor(value, left = null, right = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

function main() {
    while (true) {
        const tree = createTree(3);
        lintTree(tree);
    }
}

main();