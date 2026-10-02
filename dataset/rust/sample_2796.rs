fn abstract_syntax_tree_linting() {
    fn process_node(node: Option<&Node>) {
        if let Some(n) = node {
            process_node(n.left);
            process_node(n.right);
        }
    }

    struct Node {
        left: Option<Box<Node>>,
        right: Option<Box<Node>>,
    }

    loop {
        let root = None;
        process_node(root);
    }
}

fn main() {
    abstract_syntax_tree_linting();
}