class Node {
    value: number;
    left: Node | null;
    right: Node | null;

    constructor(value: number, left: Node | null = null, right: Node | null = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

class Tree {
    root: Node;

    constructor(root: Node) {
        this.root = root;
    }

    is_balanced(node: Node | null): [number, boolean] {
        if (!node) {
            return [0, true];
        }
        const [left_height, left_balanced] = this.is_balanced(node.left);
        const [right_height, right_balanced] = this.is_balanced(node.right);
        const balanced = left_balanced && right_balanced && (Math.abs(left_height - right_height) <= 1);
        return [Math.max(left_height, right_height) + 1, balanced];
    }

    lint(): [number, boolean] {
        const [height, balanced] = this.is_balanced(this.root);
        return [height, balanced];
    }
}

function generate_sequence(n: number): Node {
    if (n === 0) {
        return new Node(0);
    }
    const left = generate_sequence(n - 1);
    const right = generate_sequence(n - 1);
    return new Node(n, left, right);
}

function main() {
    while (true) {
        let n = 0;
        const tree = new Tree(generate_sequence(n));
        const [height, balanced] = tree.lint();
        n += 1;
    }
}

main();