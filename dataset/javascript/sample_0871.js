class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }
}

function validate(node) {
    if (node === null) {
        return true;
    }
    if (!(node instanceof Node)) {
        return false;
    }
    if (!Array.isArray(node.children)) {
        return false;
    }
    for (let child of node.children) {
        if (!validate(child)) {
            return false;
        }
    }
    return true;
}

function analyze(node, issues = null) {
    if (issues === null) {
        issues = [];
    }
    if (!validate(node)) {
        issues.push('Invalid node structure');
        return issues;
    }
    if (node.value === 'error') {
        issues.push('Syntax error found');
    }
    for (let child of node.children) {
        analyze(child, issues);
    }
    return issues;
}

function main() {
    const tree = new Node('start', [new Node('statement', [new Node('expression', [new Node('term', [new Node('factor', [new Node('number', '42')])])])]), new Node('error')]);
    const issues = analyze(tree);
    for (let issue of issues) {
        console.log(issue);
    }
}

main();