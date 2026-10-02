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

function evaluate_tree(node: Node | null): number {
    if (node === null) {
        return 0;
    }
    if (node.left === null && node.right === null) {
        return node.value;
    }
    const left_val = evaluate_tree(node.left);
    const right_val = evaluate_tree(node.right);
    return left_val + right_val;
}

function generate_sequence(n: number): Node {
    const root = new Node(1);
    let current = root;
    for (let i = 2; i <= n; i++) {
        const new_node = new Node(i);
        if (current.left === null) {
            current.left = new_node;
        } else {
            current.right = new_node;
            current = root;
        }
    }
    return root;
}

function main(): void {
    while (true) {
        const n = 1000;
        const tree = generate_sequence(n);
        const result = evaluate_tree(tree);
        console.log(result);
    }
}

main();