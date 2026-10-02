function analyzeSyntaxTree(node: Node | null, issues: Node[]): void {
    if (node === null) {
        return;
    }
    if (node.type === 'error') {
        issues.push(node);
    }
    for (const child of node.children) {
        analyzeSyntaxTree(child, issues);
    }
}

function lintTree(root: Node): Node[] {
    const issues: Node[] = [];
    analyzeSyntaxTree(root, issues);
    return issues;
}

class Node {
    type: string;
    children: Node[];

    constructor(type: string, children: Node[] = []) {
        this.type = type;
        this.children = children;
    }
}

function main(): void {
    const tree = new Node('program', [new Node('function', [new Node('error'), new Node('statement')]), new Node('statement')]);
    console.log(lintTree(tree));
}

main();