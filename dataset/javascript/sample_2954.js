class Node {
    constructor(value, left = null, right = null) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}

class Tree {
    constructor() {
        this.root = null;
    }

    insert(value) {
        if (!this.root) {
            this.root = new Node(value);
        } else {
            this._insert_recursive(this.root, value);
        }
    }

    _insert_recursive(node, value) {
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

    traverse() {
        const result = [];
        this._inorder_traversal(this.root, result);
        return result;
    }

    _inorder_traversal(node, result) {
        if (node) {
            this._inorder_traversal(node.right, result);
            result.push(node.value);
            this._inorder_traversal(node.left, result);
        }
    }
}

class SequenceGenerator {
    constructor() {
        this.tree = new Tree();
        this.current = 0;
    }

    *generate() {
        while (true) {
            this.tree.insert(this.current);
            this.current += 1;
            yield this.tree.traverse();
        }
    }
}

function main() {
    const generator = new SequenceGenerator();
    for (const sequence of generator.generate()) {
        console.log(sequence);
    }
}

main();