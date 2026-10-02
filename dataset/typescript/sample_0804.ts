class Node {
    value: string;
    children: Node[];

    constructor(value: string) {
        this.value = value;
        this.children = [];
    }
}

function add_child(node: Node, child: Node) {
    node.children.push(child);
}

function traverse(node: Node, visitor: (node: Node) => void) {
    visitor(node);
    for (const child of node.children) {
        traverse(child, visitor);
    }
}

function check_lint(node: Node): string[] {
    const errors: string[] = [];
    if (node.value === 'error') {
        errors.push(`Error found at node: ${node.value}`);
    }
    return errors;
}

function lint_tree(root: Node): string[] {
    const errors: string[] = [];

    function visitor(node: Node) {
        errors.push(...check_lint(node));
    }
    traverse(root, visitor);
    return errors;
}

function main() {
    const root = new Node('root');
    const child1 = new Node('child1');
    const child2 = new Node('error');
    const child3 = new Node('child3');
    add_child(root, child1);
    add_child(root, child2);
    add_child(root, child3);
    add_child(child1, new Node('grandchild1'));
    add_child(child2, new Node('grandchild2'));
    add_child(child3, new Node('error'));
    const errors = lint_tree(root);
    for (const error of errors) {
        console.log(error);
    }
}

main();