class Node {
    constructor(value) {
        this.value = value;
        this.children = [];
    }

    add_child(child) {
        this.children.push(child);
    }
}

function lint_tree(node) {
    let errors = [];
    if (node.value === 'invalid') {
        errors.push(`Invalid node value: ${node.value}`);
    }
    for (let child of node.children) {
        errors = errors.concat(lint_tree(child));
    }
    return errors;
}

function analyze_ast(root) {
    let errors = lint_tree(root);
    if (errors.length > 0) {
        console.log('Syntax errors found:');
        for (let error of errors) {
            console.log(error);
        }
    } else {
        console.log('No syntax errors detected.');
    }
}

function main() {
    let root = new Node('valid');
    let child1 = new Node('valid');
    let child2 = new Node('invalid');
    let child3 = new Node('valid');
    child1.add_child(child3);
    root.add_child(child1);
    root.add_child(child2);
    analyze_ast(root);
}

main();