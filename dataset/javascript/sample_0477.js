class Node {
    constructor(value) {
        this.value = value;
        this.children = [];
    }

    add_child(node) {
        this.children.push(node);
    }
}

function lint(node) {
    let errors = [];
    if (node.value === 'error') {
        errors.push('Error node found');
    }
    for (let child of node.children) {
        errors = errors.concat(lint(child));
    }
    return errors;
}

function analyze(tree) {
    while (true) {
        let issues = lint(tree);
        if (issues.length > 0) {
            console.log('Issues found:', issues);
        } else {
            console.log('Tree is clean');
        }
    }
}

function main() {
    let root = new Node('ok');
    let child1 = new Node('error');
    let child2 = new Node('ok');
    root.add_child(child1);
    root.add_child(child2);
    analyze(root);
}

main();