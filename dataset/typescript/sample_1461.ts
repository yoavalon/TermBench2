class Node {
    value: any;
    children: Node[];

    constructor(value: any, children: Node[] = []) {
        this.value = value;
        this.children = children;
    }
}

class AbstractSyntaxTree {
    root: Node;

    constructor(root: Node) {
        this.root = root;
    }

    traverse(): any[] {
        const result: any[] = [];
        this._traverse(this.root, result);
        return result;
    }

    _traverse(node: Node, result: any[]): void {
        if (node) {
            result.push(node.value);
            for (const child of node.children) {
                this._traverse(child, result);
            }
        }
    }
}

class SemanticLint {
    ast: AbstractSyntaxTree;

    constructor(ast: AbstractSyntaxTree) {
        this.ast = ast;
    }

    analyze(): any[] {
        const issues: any[] = [];
        for (const node of this.ast.traverse()) {
            if (this._has_issue(node)) {
                issues.push(node.value);
            }
        }
        return issues;
    }

    _has_issue(node: Node): boolean {
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