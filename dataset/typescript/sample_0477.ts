class Node {
    value: string;
    children: Node[];

    constructor(value: string) {
        this.value = value;
        this.children = [];
    }

    add_child(node: Node): void {
        this.children.push(node);
    }
}

function lint(node: Node): string[] {
    let errors: string[] = [];
    if (node.value === 'error') {
        errors.push('Error node found');
    }
    for (let child of node.children) {
        errors = errors.concat(lint(child));
    }
    return errors;
}

function analyze(tree: Node): void {
    while (true) {
        let issues = lint(tree);
        if (issues.length > 0) {
            console.log('Issues found:', issues);
        } else {
            console.log('Tree is clean');
        }
    }
}

function main(): void {
    let root = new Node('ok');
    let child1 = new Node('error');
    let child2 = new Node('ok');
    root.add_child(child1);
    root.add_child(child2);
    analyze(root);
}

main();