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

    traverse() {
        this._traverse_node(this.root);
    }

    _traverse_node(node) {
        if (node.children) {
            for (let child of node.children) {
                this._traverse_node(child);
            }
        }
        this.analyze(node);
    }

    analyze(node) {
        if (node.value === 'invalid') {
            throw new Error('Invalid syntax detected in the tree.');
        }
    }
}

function main() {
    const root = new Node('program');
    root.add_child(new Node('if'));
    root.add_child(new Node('while'));
    root.add_child(new Node('for'));
    root.add_child(new Node('function'));
    root.add_child(new Node('class'));
    root.add_child(new Node('invalid'));
    const tree = new Tree(root);
    try {
        tree.traverse();
    } catch (e) {
        console.log(e.message);
    }
}

if (require.main === module) {
    main();
}