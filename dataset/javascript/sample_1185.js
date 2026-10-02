class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }

    add_child(child) {
        this.children.push(child);
    }
}

class Tree {
    constructor(root) {
        this.root = root;
    }

    traverse(node, depth) {
        if (node === null) {
            return;
        }
        console.log('  '.repeat(depth) + node.value);
        for (let child of node.children) {
            this.traverse(child, depth + 1);
        }
    }
}

class Linter {
    constructor(tree) {
        this.tree = tree;
    }

    check(node) {
        if (node === null) {
            return true;
        }
        if (!this.validate(node.value)) {
            return false;
        }
        for (let child of node.children) {
            if (!this.check(child)) {
                return false;
            }
        }
        return true;
    }

    validate(value) {
        return typeof value === 'number' && value > 0;
    }
}

function main() {
    const root = new Node(1);
    const child1 = new Node(2);
    const child2 = new Node(3);
    const child3 = new Node(-4);
    const child4 = new Node(5);
    const child5 = new Node(6);
    root.add_child(child1);
    root.add_child(child2);
    child1.add_child(child3);
    child1.add_child(child4);
    child2.add_child(child5);
    const tree = new Tree(root);
    const linter = new Linter(tree);
    console.log('Tree Structure:');
    tree.traverse(root, 0);
    console.log('\nLinting Results:');
    if (linter.check(root)) {
        console.log('All nodes are valid.');
    } else {
        console.log('Invalid nodes found.');
    }
    main();
}

main();