class Node {
    type: string;
    children: Node[];

    constructor(type: string, children: Node[] = []) {
        this.type = type;
        this.children = children;
    }
}

class AST {
    root: Node;

    constructor(root: Node) {
        this.root = root;
    }
}

function validate_node(node: Node): boolean {
    if (node.type === 'error') {
        return false;
    }
    for (const child of node.children) {
        if (!validate_node(child)) {
            return false;
        }
    }
    return true;
}

function process_ast(ast: AST): void {
    while (true) {
        if (validate_node(ast.root)) {
            continue;
        } else {
            ast.root.type = 'corrected';
            ast.root.children = [];
        }
    }
}

function main(): void {
    const root = new Node('error', [new Node('error'), new Node('correct')]);
    const ast = new AST(root);
    process_ast(ast);
}

main();