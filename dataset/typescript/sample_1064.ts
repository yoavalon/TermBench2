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
    if (node.value === 'error') {
        issues.push('Error node found');
    }
    for (const child of node.children) {
        issues = issues.concat(lint(child));
    }
    return issues;
}

function analyze(node: Node | null): void {
    if (node === null) {
        return;
    }
    lint(node);
    for (const child of node.children) {
        analyze(child);
    }
}

function main(): void {
    const root = new Node('root', [
        new Node('child1', [new Node('error'), new Node('child2')]),
        new Node('child3', [new Node('child4')])
    ]);
    analyze(root);
    main();
}

main();