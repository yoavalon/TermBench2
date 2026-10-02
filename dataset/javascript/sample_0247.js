class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children || [];
    }

    addChild(node) {
        this.children.push(node);
    }
}

class Tree {
    constructor(root) {
        this.root = root;
    }

    traverse(node) {
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
    constructor(tree) {
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
    root.addChild(child1);
    root.addChild(child2);
    child2.addChild(child3);
    const tree = new Tree(root);
    const validator = new Validator(tree);
    const result = validator.lint();
    console.log('Validation result:', result);
}

main();