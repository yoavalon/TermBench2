class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children ? children : [];
    }
}

function traverse(node) {
    if (node === null) {
        return;
    }
    lint(node);
    for (let child of node.children) {
        traverse(child);
    }
}

function lint(node) {
    if (node.value === 'error') {
        throw new Error('Syntax error detected');
    }
}

function main() {
    const tree = new Node('root', [new Node('child1', [new Node('error'), new Node('child1.1')]), new Node('child2')]);
    try {
        traverse(tree);
    } catch (e) {
        console.log(e.message);
    }
}

main();