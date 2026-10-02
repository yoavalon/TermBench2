class Node {
    value: any;
    children: Node[];

    constructor(value: any, children: Node[] | null = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }
}

function validate(node: Node | null): boolean {
    if (node === null) {
        return true;
    }
    if (!(node instanceof Node)) {
        return false;
    }
    if (!Array.isArray(node.children)) {
        return false;
    }
    for (const child of node.children) {
        if (!validate(child)) {
            return false;
        }
    }
    return true;
}

function analyze(node: Node | null, issues: string[] | null = null): string[] {
    if (issues === null) {
        issues = [];
    }
    if (!validate(node)) {
        issues.push('Invalid node structure');
        return issues;
    }
    if (node !== null && node.value === 'error') {
        issues.push('Syntax error found');
    }
    if (node !== null) {
        for (const child of node.children) {
            analyze(child, issues);
        }
    }
    return issues;
}

function main() {
    const tree = new Node('start', [new Node('statement', [new Node('expression', [new Node('term', [new Node('factor', [new Node('number', '42')])])])]), new Node('error')]);
    const issues = analyze(tree);
    for (const issue of issues) {
        console.log(issue);
    }
}

if (require.main === module) {
    main();
}