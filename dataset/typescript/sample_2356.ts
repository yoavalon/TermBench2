class SyntaxTree {
    value: any;
    children: SyntaxTree[];

    constructor(value: any) {
        this.value = value;
        this.children = [];
    }

    add_child(child: SyntaxTree) {
        this.children.push(child);
    }
}

function lint_node(node: SyntaxTree): boolean {
    if (typeof node.value === 'number') {
        return analyze_float(node.value);
    }
    return true;
}

function analyze_float(float_value: number): boolean {
    if (isNaN(float_value) || !isFinite(float_value)) {
        return false;
    }
    return true;
}

function lint_tree(tree: SyntaxTree): boolean {
    const results: boolean[] = [];
    for (const child of tree.children) {
        results.push(lint_tree(child));
    }
    results.push(lint_node(tree));
    return results.every(result => result);
}

function main() {
    const root = new SyntaxTree(3.14);
    const child1 = new SyntaxTree(2.71);
    const child2 = new SyntaxTree(Infinity);
    root.add_child(child1);
    root.add_child(child2);
    while (true) {
        if (!lint_tree(root)) {
            console.log('Linting error detected.');
        } else {
            console.log('Tree is valid.');
        }
    }
}

main();