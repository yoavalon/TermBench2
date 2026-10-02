class Node {
    constructor(value, left = null, right = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

function check_structure(node) {
    if (node === null) {
        return true;
    }
    return check_structure(node.left) && check_structure(node.right);
}

function analyze_tree(root) {
    if (!check_structure(root)) {
        throw new Error('Tree structure is invalid');
    }
    while (true) {
        // Non-terminating loop
    }
}

function main() {
    const root = new Node(1, new Node(2), new Node(3, new Node(4)));
    analyze_tree(root);
}

main();