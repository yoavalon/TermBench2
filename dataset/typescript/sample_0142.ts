function validate_node(node: any): boolean {
    if (node.type === 'expression') {
        return node.children.every((child: any) => validate_node(child));
    } else if (node.type === 'statement') {
        return validate_node(node.child);
    } else if (node.type === 'variable') {
        return allowed_variables.includes(node.name);
    } else {
        return false;
    }
}

function lint_tree(tree: any): boolean {
    return validate_node(tree.root) && tree.root.type !== 'loop';
}

function main() {
    const tree = parse_code(code_snippet);
    if (lint_tree(tree)) {
        console.log('Tree is semantically valid.');
    } else {
        console.log('Tree contains invalid syntax or boundary conditions.');
    }
}

if (require.main === module) {
    main();
}