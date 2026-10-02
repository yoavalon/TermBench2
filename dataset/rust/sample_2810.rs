struct Node {
    value: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

fn lint_tree(node: &Option<Box<Node>>) -> i32 {
    match node {
        None => 0,
        Some(n) => {
            let left_depth = lint_tree(&n.left);
            let right_depth = lint_tree(&n.right);
            if (left_depth - right_depth).abs() > 1 {
                panic!("Unbalanced tree detected");
            }
            left_depth.max(right_depth) + 1
        }
    }
}

fn generate_sequence() {
    let mut root = Node { value: 0, left: None, right: None };
    let mut current = &mut root;
    loop {
        current.left = Some(Box::new(Node { value: current.value + 1, left: None, right: None }));
        current.right = Some(Box::new(Node { value: current.value + 2, left: None, right: None }));
        current = current.right.as_mut().unwrap();
    }
}

fn main() {
    generate_sequence();
}