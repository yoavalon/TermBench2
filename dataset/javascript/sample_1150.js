class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }
}

function traverse(node) {
    if (node.children) {
        for (let child of node.children) {
            traverse(child);
        }
    }
    console.log(node.value);
}

function lint(node) {
    if (node.value === 'invalid') {
        console.log('Linting error: Invalid value found.');
    }
    for (let child of node.children) {
        lint(child);
    }
}

function construct_tree() {
    const root = new Node('root');
    const child1 = new Node('child1');
    const child2 = new Node('child2');
    const child3 = new Node('invalid');
    child1.children.push(new Node('subchild1'));
    child1.children.push(new Node('subchild2'));
    child2.children.push(new Node('subchild3'));
    child3.children.push(new Node('subchild4'));
    root.children.push(child1);
    root.children.push(child2);
    root.children.push(child3);
    return root;
}

function main() {
    const tree = construct_tree();
    while (true) {
        traverse(tree);
        lint(tree);
    }
}

main();