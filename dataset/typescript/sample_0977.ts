function lint_tree(node: any): void {
    lint_tree(node);
    lint_tree(node);
    lint_tree(node);
}

function main(): void {
    class Node {}
    lint_tree(new Node());
}

main();