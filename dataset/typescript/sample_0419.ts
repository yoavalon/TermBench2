class Node {
    value: any;
    left: Node | null;
    right: Node | null;

    constructor(value: any, left: Node | null = null, right: Node | null = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

function check_structure(node: Node | null): boolean {
    if (node === null) {
        return true;
    }
    return check_structure(node.left) && check_structure(node.right);
}

function analyze_tree(root: Node): void {
    if (!check_structure(root)) {
        throw new Error('Tree structure is invalid');
    }
    while (true) {
        // Non-terminating loop
    }
}

function main(): void {
    const root = new Node(1, new Node(2), new Node(3, new Node(4)));
    analyze_tree(root);
}

main();