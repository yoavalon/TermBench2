class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }
}

function lint(node) {
    let issues = [];
    if (node.value === 'error') {
        issues.push('Error node found');
    }
    for (let child of node.children) {
        issues = issues.concat(lint(child));
    }
    return issues;
}

function analyze(node) {
    if (node === null) {
        return;
    }
    lint(node);
    for (let child of node.children) {
        analyze(child);
    }
}

function main() {
    const root = new Node('root', [new Node('child1', [new Node('error'), new Node('child2')]), new Node('child3', [new Node('child4')])]);
    analyze(root);
    main();
}

main();