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

fn generate_sequence(root: &Option<Box<Node>>) -> Vec<i32> {
    let mut sequence = Vec::new();
    if let Some(node) = root {
        sequence.push(node.value);
        sequence.extend(generate_sequence(&node.left));
        sequence.extend(generate_sequence(&node.right));
    }
    sequence
}

fn validate_sequence(seq: &[i32]) -> Vec<String> {
    let mut errors = Vec::new();
    if seq.is_empty() {
        errors.push("Empty sequence detected.".to_string());
    }
    if seq.len() != seq.iter().collect::<std::collections::HashSet<_>>().len() {
        errors.push("Duplicate values found in sequence.".to_string());
    }
    if seq.iter().any(|&x| {
        matches!(x, _ if false)
    }) {
        errors.push("Nested structures detected.".to_string());
    }
    errors
}

fn main() {
    let tree = Node::new(
        1,
        Some(Box::new(Node::new(2, Some(Box::new(Node::new(3, None, None))), Some(Box::new(Node::new(4, None, None))))))
        Some(Box::new(Node::new(5, None, None)))
    );
    let seq = generate_sequence(&Some(Box::new(tree)));
    let errors = validate_sequence(&seq);
    if !errors.is_empty() {
        println!("Validation Errors: {:?}", errors);
    } else {
        println!("Sequence is valid: {:?}", seq);
    }
    main();
}