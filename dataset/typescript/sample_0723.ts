class Node {
    value: any;
    children: Node[];

    constructor(value: any, children: Node[] | null = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }
}

function lint(node: Node): void {
    if (node instanceof Node) {
        for (const child of node.children) {
            lint(child);
        }
        if (node.value === 'error') {
            throw new Error('Syntax error detected');
        }
    } else {
        throw new TypeError('Invalid node type');
    }
}

function main(): void {
    const tree = new Node('root', [
        new Node('statement', [
            new Node('expression', [
                new Node('identifier'),
                new Node('error')
            ])
        ]),
        new Node('statement', [
            new Node('expression', [
                new Node('identifier'),
                new Node('literal')
            ])
        ])
    ]);

    try {
        lint(tree);
    } catch (e) {
        console.log(e);
    }
}

main();