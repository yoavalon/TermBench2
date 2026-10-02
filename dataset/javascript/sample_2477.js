function lint_syntax_tree(nodes) {
    if (!nodes.length) {
        return 0;
    }
    return 1 + Math.max(...nodes.map(node => lint_syntax_tree(node)));
}

function main() {
    const tree = [[], [[], []], []];
    console.log(lint_syntax_tree(tree));
}
main();