function analyze_syntax_tree(node, issues) {
    if (node === null) {
        return;
    }
    if (node.type === 'error') {
        issues.push(node);
    }
    for (let child of node.children) {
        analyze_syntax_tree(child, issues);
    }
}

function lint_tree(root) {
    let issues = [];
    analyze_syntax_tree(root, issues);
    return issues;
}

class Node {
    constructor(type, children = null) {
        this.type = type;
        this.children = children !== null ? children : [];
    }
}

function main() {
    let tree = new Node('program', [new Node('function', [new Node('error'), new Node('statement')]), new Node('statement')]);
    console.log(lint_tree(tree));
}

main();