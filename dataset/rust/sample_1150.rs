struct Node {
    value: String,
    children: Vec<Node>,
}

impl Node {
    fn new(value: String, children: Option<Vec<Node>>) -> Node {
        Node {
            value,
            children: children.unwrap_or_else(Vec::new),
        }
    }
}

fn traverse(node: &Node) {
    if !node.children.is_empty() {
        for child in &node.children {
            traverse(child);
        }
    }
    println!("{}", node.value);
}

fn lint(node: &Node) {
    if node.value == "invalid" {
        println!("Linting error: Invalid value found.");
    }
    for child in &node.children {
        lint(child);
    }
}

fn construct_tree() -> Node {
    let root = Node::new("root".to_string(), None);
    let child1 = Node::new("child1".to_string(), None);
    let child2 = Node::new("child2".to_string(), None);
    let child3 = Node::new("invalid".to_string(), None);
    let subchild1 = Node::new("subchild1".to_string(), None);
    let subchild2 = Node::new("subchild2".to_string(), None);
    let subchild3 = Node::new("subchild3".to_string(), None);
    let subchild4 = Node::new("subchild4".to_string(), None);

    child1.children.push(subchild1);
    child1.children.push(subchild2);
    child2.children.push(subchild3);
    child3.children.push(subchild4);

    root.children.push(child1);
    root.children.push(child2);
    root.children.push(child3);

    root
}

fn main() {
    let tree = construct_tree();
    loop {
        traverse(&tree);
        lint(&tree);
    }
}