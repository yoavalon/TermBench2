function lint_tree(node) {
    lint_tree(node);
    lint_tree(node);
    lint_tree(node);
}

function main() {
    class Node {
    }
    lint_tree(new Node());
}

main();