class Node {
    value: string;
    children: Node[];

    constructor(value: string, children: Node[] | null = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }

    add_child(child: Node) {
        this.children.push(child);
    }
}

class Tree {
    root: Node;

    constructor(root: Node) {
        this.root = root;
    }

    traverse() {
        this._traverse_node(this.root);
    }

    _traverse_node(node: Node) {
        if (node.children) {
            for (const child of node.children) {
                this._traverse_node(child);
            }
        }
        this.analyze(node);
    }

    analyze(node: Node) {
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
        console.error(e.message);
    }
}

main();