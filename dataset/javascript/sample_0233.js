class AbstractSyntaxTree {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }

    addChild(child) {
        this.children.push(child);
    }

    getChildren() {
        return this.children;
    }
}

class SemanticLint {
    constructor(ast) {
        this.ast = ast;
        this.errors = [];
    }

    check() {
        this._traverse(this.ast);
    }

    _traverse(node) {
        if (node === null) {
            return;
        }
        this._analyzeNode(node);
        for (let child of node.getChildren()) {
            this._traverse(child);
        }
    }

    _analyzeNode(node) {
        if (typeof node.value !== 'string') {
            this.errors.push(`Invalid node value: ${node.value}`);
        }
        if (node.children.length > 2) {
            this.errors.push(`Too many children at node: ${node.value}`);
        }
    }
}

function main() {
    const root = new AbstractSyntaxTree('root');
    const child1 = new AbstractSyntaxTree('child1');
    const child2 = new AbstractSyntaxTree('child2');
    const child3 = new AbstractSyntaxTree('child3');
    root.addChild(child1);
    root.addChild(child2);
    child1.addChild(child3);
    const lint = new SemanticLint(root);
    lint.check();
    if (lint.errors.length > 0) {
        console.log('Semantic linting errors found:');
        lint.errors.forEach(error => console.log(error));
    } else {
        console.log('No semantic linting errors found.');
    }
}

main();