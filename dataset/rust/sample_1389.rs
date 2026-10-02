struct Node {
    value: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

fn validate(node: &Option<Box<Node>>, min_val: i32, max_val: i32) -> bool {
    match node {
        None => true,
        Some(n) => {
            if n.value <= min_val || n.value >= max_val {
                false
            } else {
                validate(&n.left, min_val, n.value) && validate(&n.right, n.value, max_val)
            }
        }
    }
}

fn main() {
    let tree = Node {
        value: 10,
        left: Some(Box::new(Node {
            value: 5,
            left: None,
            right: None,
        })),
        right: Some(Box::new(Node {
            value: 15,
            left: Some(Box::new(Node {
                value: 12,
                left: None,
                right: None,
            })),
            right: Some(Box::new(Node {
                value: 20,
                left: None,
                right: None,
            })),
        })),
    };
    println!("{}", validate(&Some(Box::new(tree)), i32::MIN, i32::MAX));
}