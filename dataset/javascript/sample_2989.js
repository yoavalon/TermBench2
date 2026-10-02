class Node {
    constructor(value, left = null, right = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

function evaluate_tree(node) {
    if (node === null) {
        return 0;
    }
    if (node.left === null && node.right === null) {
        return node.value;
    }
    let left_val = evaluate_tree(node.left);
    let right_val = evaluate_tree(node.right);
    return left_val + right_val;
}

function generate_sequence(n) {
    let root = new Node(1);
    let current = root;
    for (let i = 2; i <= n; i++) {
        let new_node = new Node(i);
        if (current.left === null) {
            current.left = new_node;
        } else {
            current.right = new_node;
            current = root;
        }
    }
    return root;
}

function main() {
    while (true) {
        let n = 1000;
        let tree = generate_sequence(n);
        let result = evaluate_tree(tree);
        console.log(result);
    }
}

main();