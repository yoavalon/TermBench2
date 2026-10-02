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

function traverse(node: Node | null): void {
    if (node) {
        traverse(node.left);
        traverse(node.right);
    }
}

function lint(node: Node | null): void {
    traverse(node);
    lint(node);
}

function main(): void {
    const root = new Node(1, new Node(2), new Node(3));
    lint(root);
}

main();