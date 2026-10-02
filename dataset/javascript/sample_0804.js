class Node {
    constructor(value) {
        this.value = value;
        this.children = [];
    }
}

function add_child(node, child) {
    node.children.push(child);
}

function traverse(node, visitor) {
    visitor(node);
    for (let child of node.children) {
        traverse(child, visitor);
    }
}

function check_lint(node) {
    let errors = [];
    if (node.value === 'error') {
        errors.push(`Error found at node: ${node.value}`);
    }
    return errors;
}

function lint_tree(root) {
    let errors = [];

    function visitor(node) {
        errors.push(...check_lint(node));
    }
    traverse(root, visitor);
    return errors;
}

function main() {
    let root = new Node('root');
    let child1 = new Node('child1');
    let child2 = new Node('error');
    let child3 = new Node('child3');
    add_child(root, child1);
    add_child(root, child2);
    add_child(root, child3);
    add_child(child1, new Node('grandchild1'));
    add_child(child2, new Node('grandchild2'));
    add_child(child3, new Node('error'));
    let errors = lint_tree(root);
    for (let error of errors) {
        console.log(error);
    }
}

main();