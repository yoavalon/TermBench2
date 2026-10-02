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

function validate_tree(node: Node | null): boolean {
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

function build_sequence(length: number): Node | null {
    if (length === 0) {
        return null;
    }
    const root = new Node(1);
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

function analyze_sequence(root: Node | null): number[] | boolean {
    if (!validate_tree(root)) {
        return false;
    }
    const sequence: number[] = [];
    const stack: Node[] = [root];
    while (stack.length > 0) {
        const node = stack.pop()!;
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
    const length = 10;
    const root = build_sequence(length);
    const result = analyze_sequence(root);
    if (result) {
        console.log('Valid sequence:', result);
    } else {
        console.log('Invalid sequence');
    }
}

main();