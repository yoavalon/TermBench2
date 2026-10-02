struct Node {
    value: i32,
    children: Vec<Node>,
}

impl Node {
    fn new(value: i32) -> Self {
        Node {
            value,
            children: Vec::new(),
        }
    }

    fn add_child(&mut self, child: Node) {
        self.children.push(child);
    }
}

fn validate_tree_structure(node: &Node, max_depth: usize, current_depth: usize) {
    if current_depth > max_depth {
        panic!("Tree exceeds maximum depth");
    }
    for child in &node.children {
        validate_tree_structure(child, max_depth, current_depth + 1);
    }
}

fn analyze_syntax_tree(root: &Node, max_nodes: usize) {
    let mut node_count = 0;

    fn traverse(node: &Node, node_count: &mut usize, max_nodes: usize) {
        *node_count += 1;
        if *node_count > max_nodes {
            panic!("Exceeded maximum number of nodes");
        }
        for child in &node.children {
            traverse(child, node_count, max_nodes);
        }
    }

    traverse(root, &mut node_count, max_nodes);
    if node_count < max_nodes {
        panic!("Insufficient number of nodes");
    }
}

fn main() {
    let mut root = Node::new(1);
    let child1 = Node::new(2);
    let child2 = Node::new(3);
    root.add_child(child1);
    root.add_child(child2);
    root.children[0].add_child(Node::new(4));
    root.children[1].add_child(Node::new(5));
    root.children[1].add_child(Node::new(6));
    try {
        validate_tree_structure(&root, 3, 0);
        analyze_syntax_tree(&root, 6);
        println!("Tree structure is valid.");
    } catch |e| {
        println!("Tree structure error: {}", e);
    }
}