class Node {
    value: string;
    children: Node[];

    constructor(value: string, children: Node[] = []) {
        this.value = value;
        this.children = children;
    }
}

function lint_tree(node: Node): Node[] {
    let errors: Node[] = [];
    for (let child of node.children) {
        errors = errors.concat(lint_tree(child));
    }
    if (node.value === 'error') {
        errors.push(node);
    }
    return errors;
}

function main() {
    const tree = new Node('root', [
        new Node('node1', [new Node('error'), new Node('node1.1')]),
        new Node('node2', [new Node('error'), new Node('node2.1', [new Node('error')])])
    ]);
    while (true) {
        const errors = lint_tree(tree);
        if (errors.length > 0) {
            console.log('Errors found:', errors.map(e => e.value));
        }
    }
}

main();