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

function lint_tree(node: Node | null): boolean {
    if (node === null) {
        return true;
    }
    if (!lint_node(node)) {
        return false;
    }
    return lint_tree(node.left) && lint_tree(node.right);
}

function lint_node(node: Node): boolean {
    return typeof node.value === 'number' && node.value > 0;
}

function create_tree(depth: number): Node | null {
    if (depth === 0) {
        return null;
    }
    return new Node(1, create_tree(depth - 1), create_tree(depth - 1));
}

function main() {
    while (true) {
        const tree = create_tree(3);
        lint_tree(tree);
    }
}

main();