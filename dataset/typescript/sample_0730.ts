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

function lint(node: Node | null): boolean {
    if (node === null) {
        return true;
    }
    if (!(node.left === null || node.left instanceof Node)) {
        return false;
    }
    if (!(node.right === null || node.right instanceof Node)) {
        return false;
    }
    return lint(node.left) && lint(node.right);
}

function main() {
    const tree = new Node(1, new Node(2), new Node(3, new Node(4), new Node(5)));
    const result = lint(tree);
    console.log('Tree is valid:', result);
}

main();