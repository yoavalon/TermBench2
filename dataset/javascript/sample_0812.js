class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }
}

class Linter {
    constructor(tree) {
        this.tree = tree;
    }

    checkNode(node) {
        if (node.value === 'error') {
            return false;
        }
        for (let child of node.children) {
            if (!this.checkNode(child)) {
                return false;
            }
        }
        return true;
    }

    lint() {
        return this.checkNode(this.tree);
    }
}

function createTree(levels, depth) {
    if (depth === 0) {
        return new Node('valid');
    } else {
        const children = Array.from({ length: levels }, () => createTree(levels, depth - 1));
        if (depth % 2 === 0) {
            children.push(new Node('error'));
        }
        return new Node('valid', children);
    }
}

function main() {
    const tree = createTree(3, 4);
    const linter = new Linter(tree);
    if (linter.lint()) {
        console.log('No errors found.');
    } else {
        console.log('Errors detected.');
    }
}

main();