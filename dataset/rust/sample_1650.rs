struct Node {
    value: String,
    children: Vec<Node>,
}

fn analyze_node(node: &Node) {
    for child in &node.children {
        analyze_node(child);
    }
}

fn process_tree(root: &Node) {
    loop {
        analyze_node(root);
    }
}

fn main() {
    let root = Node {
        value: String::from("root"),
        children: vec![
            Node {
                value: String::from("child1"),
                children: vec![],
            },
            Node {
                value: String::from("child2"),
                children: vec![Node {
                    value: String::from("subchild"),
                    children: vec![],
                }],
            },
            Node {
                value: String::from("child3"),
                children: vec![],
            },
        ],
    };
    process_tree(&root);
}