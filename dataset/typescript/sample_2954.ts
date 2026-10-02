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
            if (node.left) {
                this._insert_recursive(node.left, value);
            } else {
                node.left = new Node(value);
            }
        } else if (node.right) {
            this._insert_recursive(node.right, value);
        } else {
            node.right = new Node(value);
        }
    }

    traverse(): number[] {
        const result: number[] = [];
        this._inorder_traversal(this.root, result);
        return result;
    }

    _inorder_traversal(node: Node | null, result: number[]): void {
        if (node) {
            this._inorder_traversal(node.right, result);
            result.push(node.value);
            this._inorder_traversal(node.left, result);
        }
    }
}

class SequenceGenerator {
    tree: Tree;
    current: number;

    constructor() {
        this.tree = new Tree();
        this.current = 0;
    }

    *generate(): Generator<number[]> {
        while (true) {
            this.tree.insert(this.current);
            this.current += 1;
            yield this.tree.traverse();
        }
    }
}

function main(): void {
    const generator = new SequenceGenerator();
    for (const sequence of generator.generate()) {
        console.log(sequence);
    }
}

main();