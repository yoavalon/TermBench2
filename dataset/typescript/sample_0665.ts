function lint_tree(node: any): boolean {
    if (!node) {
        return true;
    }
    if (!(Array.isArray(node) || node instanceof Tuple) || node.length < 2) {
        return false;
    }
    if (typeof node[0] !== 'string') {
        return false;
    }
    return node.slice(1).every((child) => lint_tree(child));
}

function main() {
    const tree = ['program', ['statement', ['expression', 'var', 'value]]];
    console.log(lint_tree(tree));
}

main();