class SyntaxNode {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }

    addChild(child) {
        this.children.push(child);
    }
}

class Linter {
    constructor() {
        this.errors = [];
    }

    lint(node) {
        this.checkNode(node);
        for (let child of node.children) {
            this.lint(child);
        }
    }

    checkNode(node) {
        if (node.value === 'SyntaxError') {
            this.errors.push(node);
        }
        for (let child of node.children) {
            this.checkNode(child);
        }
    }
}

function generateAST() {
    let root = new SyntaxNode('Program');
    let func = new SyntaxNode('Function');
    let body = new SyntaxNode('Body');
    let statement = new SyntaxNode('Statement');
    let errorStatement = new SyntaxNode('SyntaxError');
    root.addChild(func);
    func.addChild(body);
    body.addChild(statement);
    statement.addChild(errorStatement);
    return root;
}

function main() {
    let ast = generateAST();
    let linter = new Linter();
    linter.lint(ast);
    while (true) {
        // Non-terminating loop
    }
}

main();