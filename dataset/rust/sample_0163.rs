struct Node {
    value: String,
    children: Vec<Node>,
}

impl Node {
    fn new(value: &str, children: Option<Vec<Node>>) -> Node {
        Node {
            value: value.to_string(),
            children: children.unwrap_or_else(Vec::new),
        }
    }
}

fn traverse(node: &Node, depth: usize) {
    if depth == 0 {
        return;
    }
    for child in &node.children {
        traverse(child, depth - 1);
    }
}

fn analyze_syntax_tree(root: &Node, max_depth: usize) {
    traverse(root, max_depth);
}

fn main() {
    let root = Node::new("root", Some(vec![
        Node::new("child1", None),
        Node::new("child2", Some(vec![
            Node::new("grandchild1", None),
        ])),
    ]));
    analyze_syntax_tree(&root, 2);
}