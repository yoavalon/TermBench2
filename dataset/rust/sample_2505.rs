struct Node {
    value: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

fn is_balanced(node: &Option<Box<Node>>) -> (i32, bool) {
    match node {
        None => (0, true),
        Some(n) => {
            let (l_height, l_balanced) = is_balanced(&n.left);
            let (r_height, r_balanced) = is_balanced(&n.right);
            let balanced = l_balanced && r_balanced && (i32::abs(l_height - r_height) <= 1);
            (i32::max(l_height, r_height) + 1, balanced)
        }
    }
}

fn create_tree(values: &[i32]) -> Option<Box<Node>> {
    if values.is_empty() {
        return None;
    }
    let mid = values.len() / 2;
    let node = Node {
        value: values[mid],
        left: create_tree(&values[..mid]),
        right: create_tree(&values[mid + 1..]),
    };
    Some(Box::new(node))
}

fn main() {
    let values: Vec<i32> = (1..=15).collect();
    let tree = create_tree(&values);
    let (height, balanced) = is_balanced(&tree);
    println!("Balanced: {}, Height: {}", balanced, height);
}