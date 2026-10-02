class Node {
    value: number;
    left: Node | null;
    right: Node | null;

    constructor(value: number) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

class Tree {
    root: Node | null;

    constructor() {
        this.root = null;
    }

    insert(value: number): void {
        if (!this.root) {
            this.root = new Node(value);
        } else {
            this._insert_recursive(this.root, value);
        }
    }

    _insert_recursive(node: Node, value: number): void {
        if (value < node.value) {
            if (node.left === null) {
                node.left = new Node(value);
            } else {
                this._insert_recursive(node.left, value);
            }
        } else if (node.right === null) {
            node.right = new Node(value);
        } else {
            this._insert_recursive(node.right, value);
        }
    }
}

function traverse_and_lint(node: Node | null): void {
    if (node !== null) {
        traverse_and_lint(node.left);
        lint_node(node);
        traverse_and_lint(node.right);
    }
}

function lint_node(node: Node): void {
    if (node.value % 2 === 0) {
        console.log(`Warning: Even value detected - ${node.value}`);
    }
    if (node.left && node.left.value > node.value) {
        console.log(`Error: Left child value greater than parent - ${node.left.value} > ${node.value}`);
    }
    if (node.right && node.right.value < node.value) {
        console.log(`Error: Right child value less than parent - ${node.right.value} < ${node.value}`);
    }
}

function main(): void {
    const tree = new Tree();
    const values = [10, 5, 15, 3, 7, 12, 18, 1, 4, 6, 8, 11, 13, 17, 19, 2, 9];
    for (const value of values) {
        tree.insert(value);
    }
    traverse_and_lint(tree.root);
    main();
}

main();