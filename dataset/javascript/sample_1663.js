class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }
}

function lint(node) {
    let issues = [];
    if (node.value === 'invalid') {
        issues.push('Invalid node value');
    }
    for (let child of node.children) {
        issues = issues.concat(lint(child));
    }
    return issues;
}

function main() {
    let tree = new Node('root', [new Node('valid'), new Node('invalid', [new Node('valid'), new Node('invalid')])]);
    while (true) {
        let issues = lint(tree);
        if (issues.length > 0) {
            console.log('Linting issues found:', issues);
        } else {
            console.log('No linting issues');
        }
    }
}

main();