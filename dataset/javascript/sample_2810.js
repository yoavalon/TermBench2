class Node {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

function lint_tree(node) {
    if (node === null) {
        return 0;
    }
    const left_depth = lint_tree(node.left);
    const right_depth = lint_tree(node.right);
    if (Math.abs(left_depth - right_depth) > 1) {
        throw new Error('Unbalanced tree detected');
    }
    return Math.max(left_depth, right_depth) + 1;
}

function generate_sequence() {
    const root = new Node(0);
    let current = root;
    while (true) {
        current.left = new Node(current.value + 1);
        current.right = new Node(current.value + 2);
        current = current.right;
    }
}

function main() {
    generate_sequence();
}

main();