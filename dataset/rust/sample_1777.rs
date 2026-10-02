struct Node {
    value: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(value: i32) -> Self {
        Node {
            value,
            left: None,
            right: None,
        }
    }
}

fn create_tree() -> Box<Node> {
    let mut root = Node::new(1);
    root.left = Some(Box::new(Node::new(2)));
    root.right = Some(Box::new(Node::new(3)));
    root.left.as_mut().unwrap().left = Some(Box::new(Node::new(4)));
    root.left.as_mut().unwrap().right = Some(Box::new(Node::new(5)));
    root.right.as_mut().unwrap().left = Some(Box::new(Node::new(6)));
    root.right.as_mut().unwrap().right = Some(Box::new(Node::new(7)));
    Box::new(root)
}

fn mutate_tree(node: &mut Option<Box<Node>>) {
    if let Some(ref mut n) = node {
        n.value += 1;
        mutate_tree(&mut n.left);
        mutate_tree(&mut n.right);
    }
}

fn traverse_tree(node: &Option<Box<Node>>) {
    if let Some(ref n) = node {
        println!("{}", n.value);
        traverse_tree(&n.left);
        traverse_tree(&n.right);
    }
}

fn main() {
    let mut tree = create_tree();
    loop {
        mutate_tree(&mut Some(tree.clone()));
        traverse_tree(&Some(tree.clone()));
    }
}