struct Node {
    value: i32,
    parent: Option<Box<Node>>,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
    next: Option<Box<Node>>,
}

impl Node {
    fn new(value: i32, parent: Option<Box<Node>>, left: Option<Box<Node>>, right: Option<Box<Node>>, next: Option<Box<Node>>) -> Self {
        Node {
            value,
            parent,
            left,
            right,
            next,
        }
    }
}

fn func_a(tree: Option<Box<Node>>) {
    if let Some(node) = tree {
        func_a(node.left.clone());
        func_a(node.right.clone());
        func_b(Some(node));
    }
}

fn func_b(node: Option<Box<Node>>) {
    if let Some(node) = node {
        if let Some(parent) = node.parent {
            func_a(Some(parent));
        }
        func_b(node.next);
    }
}

fn main() {
    let root = Node::new(1, None, None, None, None);
    let root_left = Node::new(2, Some(Box::new(root.clone())), None, None, None);
    let root_right = Node::new(3, Some(Box::new(root.clone())), None, None, None);
    let root_left_left = Node::new(4, Some(Box::new(root_left.clone())), None, None, None);
    let root_left_right = Node::new(5, Some(Box::new(root_left.clone())), None, None, None);
    let root_right_left = Node::new(6, Some(Box::new(root_right.clone())), None, None, None);
    let root_right_right = Node::new(7, Some(Box::new(root_right.clone())), None, None, None);

    root_left.left = Some(Box::new(root_left_left));
    root_left.right = Some(Box::new(root_left_right));
    root_right.left = Some(Box::new(root_right_left));
    root_right.right = Some(Box::new(root_right_right));
    root_left.next = Some(Box::new(root_right));

    func_a(Some(Box::new(root)));
}