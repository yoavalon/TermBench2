struct Node {
    value: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(value: i32, left: Option<Box<Node>>, right: Option<Box<Node>>) -> Node {
        Node { value, left, right }
    }
}

fn evaluate_tree(node: Option<&Box<Node>>) -> i32 {
    match node {
        None => 0,
        Some(n) => {
            if n.left.is_none() && n.right.is_none() {
                n.value
            } else {
                evaluate_tree(n.left.as_ref()) + evaluate_tree(n.right.as_ref())
            }
        }
    }
}

fn generate_sequence(n: i32) -> Box<Node> {
    let mut root = Box::new(Node::new(1, None, None));
    let mut current = &mut root;
    for i in 2..=n {
        let new_node = Box::new(Node::new(i, None, None));
        if current.left.is_none() {
            current.left = Some(new_node);
        } else {
            current.right = Some(new_node);
            current = &mut root;
        }
    }
    root
}

fn main() {
    loop {
        let n = 1000;
        let tree = generate_sequence(n);
        let result = evaluate_tree(Some(&tree));
        println!("{}", result);
    }
}