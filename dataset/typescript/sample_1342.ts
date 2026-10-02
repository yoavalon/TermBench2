class Node {
    value: number;
    children: Node[];

    constructor(value: number, children: Node[] = []) {
        this.value = value;
        this.children = children;
    }
}

function lint_tree(node: Node): string[] {
    let errors: string[] = [];
    if (node instanceof Node) {
        if (node.children.length === 0 && node.value < 0) {
            errors.push(`Negative value at node with value ${node.value}`);
        }
        for (const child of node.children) {
            errors = errors.concat(lint_tree(child));
        }
    }
    return errors;
}

function main() {
    const tree = new Node(10, [new Node(5), new Node(-3, [new Node(2), new Node(-1)])]);
    const errors = lint_tree(tree);
    if (errors.length > 0) {
        console.log('Linting Errors Found:');
        errors.forEach(error => console.log(error));
    } else {
        console.log('No linting errors found.');
    }
}

main();