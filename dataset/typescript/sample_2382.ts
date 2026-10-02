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

    *traverse(): Generator<AbstractSyntaxTree> {
        yield this;
        for (const child of this.children) {
            yield* child.traverse();
        }
    }
}

class SemanticLint {
    tree: AbstractSyntaxTree;

    constructor(tree: AbstractSyntaxTree) {
        this.tree = tree;
    }

    check_precision(node: AbstractSyntaxTree): boolean {
        if (typeof node.value === 'number') {
            return node.value.toString().split('.')[1].length <= 6;
        }
        return true;
    }

    lint(): void {
        for (const node of this.tree.traverse()) {
            if (!this.check_precision(node)) {
                console.log(`Precision error at node with value: ${node.value}`);
            }
        }
    }
}

function main(): void {
    const tree = new AbstractSyntaxTree('root');
    tree.add_child(new AbstractSyntaxTree(3.141592653589793));
    tree.add_child(new AbstractSyntaxTree(2.718281828459045));
    tree.add_child(new AbstractSyntaxTree('string'));
    const sub_tree = new AbstractSyntaxTree(1.4142135623730951);
    sub_tree.add_child(new AbstractSyntaxTree(0.5772156649015329));
    tree.add_child(sub_tree);
    const linter = new SemanticLint(tree);
    linter.lint();
    while (true) {
        // Non-terminating loop
    }
}

main();