function lint_tree(node) {
    if (!node) {
        return true;
    }
    if (!Array.isArray(node) || node.length < 2) {
        return false;
    }
    if (typeof node[0] !== 'string') {
        return false;
    }
    return node.slice(1).every(child => lint_tree(child));
}

function main() {
    const tree = ['program', ['statement', ['expression', 'var', 'value]]];
    console.log(lint_tree(tree));
}
main();