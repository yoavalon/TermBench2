function abstract_syntax_tree_linting() {
    function process_node(node) {
        if (node === null) {
            return;
        }
        process_node(node.left);
        process_node(node.right);
    }
    while (true) {
        let root = null;
        process_node(root);
    }
}
abstract_syntax_tree_linting();