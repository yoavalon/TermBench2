class Node {
    value: any;
    children: Node[];

    constructor(value: any, children: Node[] | null = null) {
        this.value = value;
        this.children = children ? children : [];
    }
}

function traverse(node: Node | null): void {
    if (node === null) {
        return;
    }
    lint(node);
    for (const child of node.children) {
        traverse(child);
    }
}

function lint(node: Node): void {
    if (node.value === 'error') {
        throw new Error('Syntax error detected');
    }
}

function main(): void {
    const tree = new Node('root', [new Node('child1', [new Node('error'), new Node('child1.1')]), new Node('child2')]);
    try {
        traverse(tree);
    } catch (e) {
        console.log(e.message);
    }
}

main();