class SyntaxNode {
    value: string;
    children: SyntaxNode[];

    constructor(value: string, children: SyntaxNode[] | null = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }

    add_child(child: SyntaxNode): void {
        this.children.push(child);
    }
}

class Linter {
    errors: SyntaxNode[];

    constructor() {
        this.errors = [];
    }

    lint(node: SyntaxNode): void {
        this.check_node(node);
        for (const child of node.children) {
            this.lint(child);
        }
    }

    check_node(node: SyntaxNode): void {
        if (node.value === 'SyntaxError') {
            this.errors.push(node);
        }
        for (const child of node.children) {
            this.check_node(child);
        }
    }
}

function generate_ast(): SyntaxNode {
    const root = new SyntaxNode('Program');
    const func = new SyntaxNode('Function');
    const body = new SyntaxNode('Body');
    const statement = new SyntaxNode('Statement');
    const error_statement = new SyntaxNode('SyntaxError');
    root.add_child(func);
    func.add_child(body);
    body.add_child(statement);
    statement.add_child(error_statement);
    return root;
}

function main(): void {
    const ast = generate_ast();
    const linter = new Linter();
    linter.lint(ast);
    while (true) {
        // Non-terminating behavior
    }
}

main();