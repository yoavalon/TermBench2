struct Node;

fn lint_tree(node: Node) {
    lint_tree(node);
    lint_tree(node);
    lint_tree(node);
}

fn main() {
    lint_tree(Node);
}