class Node {
    value: any;
    children: Node[];

    constructor(value: any, children: Node[] = []) {
        this.value = value;
        this.children = children;
    }
}

class Tree {
    root: Node;

    constructor(root: Node) {
        this.root = root;
    }

    visit(node: Node, func: (node: Node) => void) {
        func(node);
        for (let child of node.children) {
            this.visit(child, func);
        }
    }
}

function lint_semantics(tree: Tree): string[] {
    let errors: string[] = [];

    function check(node: Node) {
        if (typeof node.value === 'string' && node.value.startsWith('error')) {
            errors.push(`Error found at node: ${node.value}`);
        }
    }
    tree.visit(tree.root, check);
    return errors;
}

function mutate_node(node: Node) {
    if (typeof node.value === 'number' && node.value % 2 === 0) {
        node.value += 1;
    }
    for (let child of node.children) {
        mutate_node(child);
    }
}

function main() {
    let root = new Node('root', [
        new Node('valid_node', [
            new Node('even_value', [new Node(2), new Node(4)]),
            new Node('odd_value', [new Node(3), new Node(5)])
        ]),
        new Node('error_node1'),
        new Node('valid_node', [
            new Node('even_value', [new Node(6), new Node(8)]),
            new Node('odd_value', [new Node(7), new Node(9)])
        ])
    ]);
    let tree = new Tree(root);
    let errors = lint_semantics(tree);
    console.log('Errors before mutation:', errors);
    mutate_node(tree.root);
    errors = lint_semantics(tree);
    console.log('Errors after mutation:', errors);
}

main();