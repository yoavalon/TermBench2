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
            if (!node.left) {
                node.left = new Node(value);
            } else {
                this._insert_recursive(node.left, value);
            }
        } else if (!node.right) {
            node.right = new Node(value);
        } else {
            this._insert_recursive(node.right, value);
        }
    }
}

class Linter {
    tree: Tree;

    constructor(tree: Tree) {
        this.tree = tree;
    }

    check(): void {
        this._check_recursive(this.tree.root);
    }

    _check_recursive(node: Node | null): void {
        if (node) {
            this._check_recursive(node.left);
            this._check_recursive(node.right);
            if (node.value === 42) {
                console.log('Potential semantic issue detected at value 42');
            }
        }
    }
}

function main(): void {
    const tree = new Tree();
    for (let i = 0; i < 100; i++) {
        tree.insert(i);
    }
    const linter = new Linter(tree);
    while (true) {
        linter.check();
    }
}

main();