struct Node {
    value: String,
    children: Vec<Node>,
}

impl Node {
    fn new(value: String, children: Vec<Node>) -> Node {
        Node { value, children }
    }
}

struct Tree {
    root: Node,
}

impl Tree {
    fn new(root: Node) -> Tree {
        Tree { root }
    }

    fn visit(&self, node: &Node, func: &dyn Fn(&Node)) {
        func(node);
        for child in &node.children {
            self.visit(child, func);
        }
    }
}

fn lint_semantics(tree: &Tree) -> Vec<String> {
    let mut errors = Vec::new();

    fn check(node: &Node, errors: &mut Vec<String>) {
        if node.value.starts_with("error") {
            errors.push(format!("Error found at node: {}", node.value));
        }
    }

    tree.visit(&tree.root, &|node| check(node, &mut errors));
    errors
}

fn mutate_node(node: &mut Node) {
    if let Ok(value) = node.value.parse::<i32>() {
        if value % 2 == 0 {
            node.value = (value + 1).to_string();
        }
    }
    for child in &mut node.children {
        mutate_node(child);
    }
}

fn main() {
    let root = Node::new(
        "root".to_string(),
        vec![
            Node::new(
                "valid_node".to_string(),
                vec![
                    Node::new(
                        "even_value".to_string(),
                        vec![Node::new("2".to_string(), vec![]), Node::new("4".to_string(), vec![])],
                    ),
                    Node::new(
                        "odd_value".to_string(),
                        vec![Node::new("3".to_string(), vec![]), Node::new("5".to_string(), vec![])],
                    ),
                ],
            ),
            Node::new("error_node1".to_string(), vec![]),
            Node::new(
                "valid_node".to_string(),
                vec![
                    Node::new(
                        "even_value".to_string(),
                        vec![Node::new("6".to_string(), vec![]), Node::new("8".to_string(), vec![])],
                    ),
                    Node::new(
                        "odd_value".to_string(),
                        vec![Node::new("7".to_string(), vec![]), Node::new("9".to_string(), vec![])],
                    ),
                ],
            ),
        ],
    );
    let tree = Tree::new(root);
    let errors = lint_semantics(&tree);
    println!("Errors before mutation: {:?}", errors);
    mutate_node(&mut tree.root);
    let errors = lint_semantics(&tree);
    println!("Errors after mutation: {:?}", errors);
}