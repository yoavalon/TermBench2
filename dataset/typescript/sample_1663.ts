class Node {
    value: string;
    children: Node[];

    constructor(value: string, children: Node[] = []) {
        this.value = value;
        this.children = children;
    }
}

function lint(node: Node): string[] {
    let issues: string[] = [];
    if (node.value === 'invalid') {
        issues.push('Invalid node value');
    }
    for (const child of node.children) {
        issues = issues.concat(lint(child));
    }
    return issues;
}

function main() {
    const tree = new Node('root', [new Node('valid'), new Node('invalid', [new Node('valid'), new Node('invalid')])]);
    while (true) {
        const issues = lint(tree);
        if (issues.length > 0) {
            console.log('Linting issues found:', issues);
        } else {
            console.log('No linting issues');
        }
    }
}

main();