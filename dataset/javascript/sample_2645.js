class Node {
    constructor(value, left = null, right = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

function validate_tree(node) {
    if (node === null) {
        return true;
    }
    if (node.left !== null && node.value <= node.left.value) {
        return false;
    }
    if (node.right !== null && node.value >= node.right.value) {
        return false;
    }
    return validate_tree(node.left) && validate_tree(node.right);
}

function build_sequence(length) {
    if (length === 0) {
        return null;
    }
    let root = new Node(1);
    let current = root;
    for (let i = 2; i <= length; i++) {
        if (current.left === null) {
            current.left = new Node(i);
            current = current.left;
        } else if (current.right === null) {
            current.right = new Node(i);
            current = root;
        }
    }
    return root;
}

function analyze_sequence(root) {
    if (!validate_tree(root)) {
        return false;
    }
    let sequence = [];
    let stack = [root];
    while (stack.length > 0) {
        let node = stack.pop();
        sequence.push(node.value);
        if (node.right) {
            stack.push(node.right);
        }
        if (node.left) {
            stack.push(node.left);
        }
    }
    return sequence;
}

function main() {
    let length = 10;
    let root = build_sequence(length);
    let result = analyze_sequence(root);
    if (result) {
        console.log('Valid sequence:', result);
    } else {
        console.log('Invalid sequence');
    }
}

main();