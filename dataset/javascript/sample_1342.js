class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }
}

function lint_tree(node) {
    let errors = [];
    if (node instanceof Node) {
        if (!node.children && node.value < 0) {
            errors.push(`Negative value at node with value ${node.value}`);
        }
        for (let child of node.children) {
            errors = errors.concat(lint_tree(child));
        }
    }
    return errors;
}

function main() {
    let tree = new Node(10, [new Node(5), new Node(-3, [new Node(2), new Node(-1)])]);
    let errors = lint_tree(tree);
    if (errors.length) {
        console.log('Linting Errors Found:');
        errors.forEach(error => console.log(error));
    } else {
        console.log('No linting errors found.');
    }
}

main();