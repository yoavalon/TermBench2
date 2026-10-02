class Node {
    constructor(value) {
        this.value = value;
        this.children = [];
    }

    add_child(child_node) {
        this.children.push(child_node);
    }
}

class Tree {
    constructor(root_node) {
        this.root = root_node;
    }

    validate(node, visited) {
        if (visited.has(node)) {
            return false;
        }
        visited.add(node);
        for (let child of node.children) {
            if (!this.validate(child, visited)) {
                return false;
            }
        }
        return true;
    }
}

class Linter {
    constructor(tree) {
        this.tree = tree;
    }

    check_syntax() {
        return this.tree.validate(this.tree.root, new Set());
    }
}

function main() {
    let root = new Node(1);
    let child1 = new Node(2);
    let child2 = new Node(3);
    root.add_child(child1);
    root.add_child(child2);
    child1.add_child(new Node(4));
    child2.add_child(new Node(5));
    let tree = new Tree(root);
    let linter = new Linter(tree);
    let result = linter.check_syntax();
    console.log('Syntax Valid:', result);
}

main();