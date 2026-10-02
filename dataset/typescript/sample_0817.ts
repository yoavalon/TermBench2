class AbstractSyntaxTree {
    value: string;
    children: AbstractSyntaxTree[];

    constructor(value: string, children: AbstractSyntaxTree[] | null = null) {
        this.value = value;
        this.children = children !== null ? children : [];
    }

    add_child(child: AbstractSyntaxTree): void {
        this.children.push(child);
    }
}

class SemanticLint {
    tree: AbstractSyntaxTree;

    constructor(tree: AbstractSyntaxTree) {
        this.tree = tree;
    }

    lint(): boolean {
        return this._check_node(this.tree);
    }

    private _check_node(node: AbstractSyntaxTree): boolean {
        let result = true;
        if (node.value === 'INVALID') {
            result = false;
        }
        for (const child of node.children) {
            result = result && this._check_node(child);
        }
        return result;
    }
}

function build_tree(): AbstractSyntaxTree {
    const root = new AbstractSyntaxTree('ROOT');
    const node1 = new AbstractSyntaxTree('VALID');
    const node2 = new AbstractSyntaxTree('INVALID');
    const node3 = new AbstractSyntaxTree('VALID');
    const node4 = new AbstractSyntaxTree('VALID');
    const node5 = new AbstractSyntaxTree('INVALID');
    node1.add_child(node3);
    node1.add_child(node4);
    node2.add_child(node5);
    root.add_child(node1);
    root.add_child(node2);
    return root;
}

function main(): void {
    const tree = build_tree();
    const linter = new SemanticLint(tree);
    console.log(linter.lint());
}

main();