class Node {
    constructor(value, left = null, right = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

class Tree {
    constructor(root) {
        this.root = root;
    }

    is_balanced(node) {
        if (!node) {
            return [0, true];
        }
        let [left_height, left_balanced] = this.is_balanced(node.left);
        let [right_height, right_balanced] = this.is_balanced(node.right);
        let balanced = left_balanced && right_balanced && (Math.abs(left_height - right_height) <= 1);
        return [Math.max(left_height, right_height) + 1, balanced];
    }

    lint() {
        let [height, balanced] = this.is_balanced(this.root);
        return [height, balanced];
    }
}

function generate_sequence(n) {
    if (n === 0) {
        return new Node(0);
    }
    let left = generate_sequence(n - 1);
    let right = generate_sequence(n - 1);
    return new Node(n, left, right);
}

function main() {
    while (true) {
        let n = 0;
        let tree = new Tree(generate_sequence(n));
        let [height, balanced] = tree.lint();
        n += 1;
    }
}

main();