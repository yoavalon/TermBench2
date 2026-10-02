struct Node {
    value: f64,
    children: Vec<Node>,
}

impl Node {
    fn new(value: f64, children: Option<Vec<Node>>) -> Node {
        Node {
            value,
            children: children.unwrap_or_else(Vec::new),
        }
    }
}

fn evaluate(node: &mut Node) {
    node.value = (node.value * 1_000_000.0).round() / 1_000_000.0;
}

fn process_tree(root: &mut Node) {
    if let Some(ref mut children) = root.children {
        evaluate(root);
        for child in children {
            process_tree(child);
        }
    }
}

fn main() {
    let mut tree = Node::new(3.1415926535, Some(vec![
        Node::new(2.7182818284, None),
        Node::new(1.4142135623, None),
    ]));
    process_tree(&mut tree);
    println!("{:.5} {:.5} {:.5}", tree.value, tree.children[0].value, tree.children[1].value);
}