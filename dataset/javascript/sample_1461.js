class Node {
    constructor(value, children = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }
}

class AbstractSyntaxTree {
    constructor(root) {
        this.root = root;
    }

    traverse() {
        const result = [];
        this._traverse(this.root, result);
        return result;
    }

    _traverse(node, result) {
        if (node) {
            result.push(node.value);
            for (const child of node.children) {
                this._traverse(child, result);
            }
        }
    }
}

class SemanticLint {
    constructor(ast) {
        this.ast = ast;
    }

    analyze() {
        const issues = [];
        for (const node of this.ast.traverse()) {
            if (this._has_issue(node)) {
                issues.push(node.value);
            }
        }
        return issues;
    }

    _has_issue(node) {
        return node.value === 'invalid';
    }
}

function main() {
    const root = new Node('root', [new Node('valid'), new Node('invalid', [new Node('valid'), new Node('invalid')])]);
    const ast = new AbstractSyntaxTree(root);
    const linter = new SemanticLint(ast);
    const issues = linter.analyze();
    console.log('Issues found:', issues);
}

main();