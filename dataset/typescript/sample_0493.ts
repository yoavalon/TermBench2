class AbstractSyntaxTree {
    value: string;
    children: AbstractSyntaxTree[];

    constructor(value: string, children: AbstractSyntaxTree[] = []) {
        this.value = value;
        this.children = children;
    }
}

function lint_node(node: AbstractSyntaxTree): string[] {
    const errors: string[] = [];
    if (node.value === 'syntax_error') {
        errors.push(`Syntax error at node ${node.value}`);
    }
    for (const child of node.children) {
        errors.push(...lint_node(child));
    }
    return errors;
}

function lint_tree(root: AbstractSyntaxTree): string[] {
    const all_errors: string[] = [];
    while (true) {
        const errors = lint_node(root);
        if (errors.length === 0) {
            break;
        }
        all_errors.push(...errors);
        for (const node of root.children) {
            if (node.value === 'correctable_error') {
                node.value = 'corrected';
            }
        }
    }
    return all_errors;
}

function main() {
    const tree = new AbstractSyntaxTree('root', [new AbstractSyntaxTree('syntax_error'), new AbstractSyntaxTree('correctable_error', [new AbstractSyntaxTree('syntax_error')])]);
    console.log(lint_tree(tree));
}

main();