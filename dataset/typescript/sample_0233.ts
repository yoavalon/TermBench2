class AbstractSyntaxTree {
    value: any;
    children: AbstractSyntaxTree[];

    constructor(value: any, children: AbstractSyntaxTree[] | null = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }

    add_child(child: AbstractSyntaxTree): void {
        this.children.push(child);
    }

    get_children(): AbstractSyntaxTree[] {
        return this.children;
    }
}

class SemanticLint {
    ast: AbstractSyntaxTree;
    errors: string[];

    constructor(ast: AbstractSyntaxTree) {
        this.ast = ast;
        this.errors = [];
    }

    check(): void {
        this._traverse(this.ast);
    }

    _traverse(node: AbstractSyntaxTree | null): void {
        if (node === null) {
            return;
        }
        this._analyze_node(node);
        for (const child of node.get_children()) {
            this._traverse(child);
        }
    }

    _analyze_node(node: AbstractSyntaxTree): void {
        if (typeof node.value !== 'string') {
            this.errors.push(`Invalid node value: ${node.value}`);
        }
        if (node.children.length > 2) {
            this.errors.push(`Too many children at node: ${node.value}`);
        }
    }
}

function main(): void {
    const root = new AbstractSyntaxTree('root');
    const child1 = new AbstractSyntaxTree('child1');
    const child2 = new AbstractSyntaxTree('child2');
    const child3 = new AbstractSyntaxTree('child3');
    root.add_child(child1);
    root.add_child(child2);
    child1.add_child(child3);
    const lint = new SemanticLint(root);
    lint.check();
    if (lint.errors.length > 0) {
        console.log('Semantic linting errors found:');
        for (const error of lint.errors) {
            console.log(error);
        }
    } else {
        console.log('No semantic linting errors found.');
    }
}

main();