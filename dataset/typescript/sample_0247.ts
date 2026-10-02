class Node {
    value: any;
    children: Node[];

    constructor(value: any, children: Node[] = []) {
        this.value = value;
        this.children = children;
    }

    add_child(node: Node) {
        this.children.push(node);
    }
}

class Tree {
    root: Node;

    constructor(root: Node) {
        this.root = root;
    }

    traverse(node: Node) {
        if (node.children) {
            for (let child of node.children) {
                this.traverse(child);
            }
        }
    }

    validate() {
        this.traverse(this.root);
        return true;
    }
}

class Validator {
    tree: Tree;

    constructor(tree: Tree) {
        this.tree = tree;
    }

    lint() {
        return this.tree.validate();
    }
}

function main() {
    const root = new Node('start');
    const child1 = new Node('condition1');
    const child2 = new Node('condition2');
    const child3 = new Node('end');
    root.add_child(child1);
    root.add_child(child2);
    child2.add_child(child3);
    const tree = new Tree(root);
    const validator = new Validator(tree);
    const result = validator.lint();
    console.log('Validation result:', result);
}

main();