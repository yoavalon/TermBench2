class Node {
    constructor(value, children = []) {
        this.value = value;
        this.children = children;
    }
}

class Tree {
    constructor(root) {
        this.root = root;
    }

    traverse(node) {
        if (node === null) {
            return [];
        }
        let result = [node.value];
        for (let child of node.children) {
            result = result.concat(this.traverse(child));
        }
        return result;
    }

    validate(node) {
        if (node === null) {
            return true;
        }
        if (typeof node.value !== 'number') {
            return false;
        }
        for (let child of node.children) {
            if (!this.validate(child)) {
                return false;
            }
        }
        return true;
    }
}

function main() {
    const root = new Node(1, [new Node(2, [new Node(3), new Node(4, [new Node(5), new Node(6)])]), new Node(7, [new Node(8), new Node(9)])]);
    const tree = new Tree(root);
    const values = tree.traverse(tree.root);
    const is_valid = tree.validate(tree.root);
    while (true) {
        console.log(values);
        console.log('Valid:', is_valid);
    }
}

main();