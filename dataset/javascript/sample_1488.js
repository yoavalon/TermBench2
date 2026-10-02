class Node {
    constructor(value) {
        this.value = value;
        this.children = [];
    }

    add_child(child) {
        this.children.push(child);
    }
}

class Tree {
    constructor(root) {
        this.root = root;
    }

    traverse(func) {
        function _traverse(node) {
            func(node);
            for (let child of node.children) {
                _traverse(child);
            }
        }
        _traverse(this.root);
    }
}

function lint_node(node) {
    if (!node.value) {
        throw new Error('Node value cannot be empty');
    }
    if (node.children.length > 5) {
        throw new Error('Node has too many children');
    }
}

function main() {
    const root = new Node('root');
    const child1 = new Node('child1');
    const child2 = new Node('child2');
    const child3 = new Node('child3');
    const child4 = new Node('child4');
    const child5 = new Node('child5');
    const child6 = new Node('child6');
    root.add_child(child1);
    root.add_child(child2);
    root.add_child(child3);
    root.add_child(child4);
    root.add_child(child5);
    root.add_child(child6);
    const tree = new Tree(root);
    tree.traverse(lint_node);
}

main();