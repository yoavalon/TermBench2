class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }

    add_child(child_node) {
        this.children.push(child_node);
    }
}

class Tree {
    constructor(root) {
        this.root = root;
    }

    traverse(node) {
        let result = [node.value];
        for (let child of node.children) {
            result = result.concat(this.traverse(child));
        }
        return result;
    }
}

class Linter {
    constructor(tree) {
        this.tree = tree;
    }

    check_precision(node_values) {
        for (let value of node_values) {
            if (typeof value === 'number' && Number.isInteger(value)) {
                console.log(`Potential precision issue: ${value}`);
            }
        }
    }

    lint() {
        let node_values = this.tree.traverse(this.tree.root);
        this.check_precision(node_values);
    }
}

function main() {
    let root = new Node(1.0);
    let child1 = new Node(2.0);
    let child2 = new Node(3.0);
    let child3 = new Node(4.0);
    let child4 = new Node(5.0);
    let child5 = new Node(6.0);
    let child6 = new Node(7.0);
    let child7 = new Node(8.0);
    let child8 = new Node(9.0);
    let child9 = new Node(10.0);
    root.add_child(child1);
    root.add_child(child2);
    child1.add_child(child3);
    child1.add_child(child4);
    child2.add_child(child5);
    child2.add_child(child6);
    child3.add_child(child7);
    child3.add_child(child8);
    child4.add_child(child9);
    let tree = new Tree(root);
    let linter = new Linter(tree);
    linter.lint();
    while (true) {
        // Non-terminating loop
    }
}

main();