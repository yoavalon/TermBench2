struct Node {
    value: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

fn validate_tree(node: &Option<Box<Node>>) -> bool {
    match node {
        None => true,
        Some(n) => {
            let valid_left = match n.left {
                None => true,
                Some(ref left) => n.value > left.value && validate_tree(&n.left),
            };
            let valid_right = match n.right {
                None => true,
                Some(ref right) => n.value < right.value && validate_tree(&n.right),
            };
            valid_left && valid_right
        }
    }
}

fn build_sequence(length: i32) -> Option<Box<Node>> {
    if length == 0 {
        return None;
    }
    let mut root = Some(Box::new(Node { value: 1, left: None, right: None }));
    let mut current = root.as_mut().unwrap();
    for i in 2..=length {
        if current.left.is_none() {
            current.left = Some(Box::new(Node { value: i, left: None, right: None }));
            current = current.left.as_mut().unwrap();
        } else if current.right.is_none() {
            current.right = Some(Box::new(Node { value: i, left: None, right: None }));
            current = root.as_mut().unwrap();
        }
    }
    root
}

fn analyze_sequence(root: &Option<Box<Node>>) -> Option<Vec<i32>> {
    if !validate_tree(&root) {
        return None;
    }
    let mut sequence = Vec::new();
    let mut stack = vec![root];
    while let Some(node) = stack.pop() {
        if let Some(n) = node {
            sequence.push(n.value);
            stack.push(&n.right);
            stack.push(&n.left);
        }
    }
    Some(sequence)
}

fn main() {
    let length = 10;
    let root = build_sequence(length);
    let result = analyze_sequence(&root);
    if let Some(sequence) = result {
        println!("Valid sequence: {:?}", sequence);
    } else {
        println!("Invalid sequence");
    }
}