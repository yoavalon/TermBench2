class Node {
    value: string;
    children: Node[];

    constructor(value: string) {
        this.value = value;
        this.children = [];
    }

    add_child(child: Node): void {
        this.children.push(child);
    }
}

function lint_tree(node: Node): string[] {
    const errors: string[] = [];
    if (node.value === 'invalid') {
        errors.push(`Invalid node value: ${node.value}`);
    }
    for (const child of node.children) {
        errors.push(...lint_tree(child));
    }
    return errors;
}

function analyze_ast(root: Node): void {
    const errors = lint_tree(root);
    if (errors.length > 0) {
        console.log('Syntax errors found:');
        for (const error of errors) {
            console.log(error);
        }
    } else {
        console.log('No syntax errors detected.');
    }
}

function main(): void {
    const root = new Node('valid');
    const child1 = new Node('valid');
    const child2 = new Node('invalid');
    const child3 = new Node('valid');
    child1.add_child(child3);
    root.add_child(child1);
    root.add_child(child2);
    analyze_ast(root);
}

main();