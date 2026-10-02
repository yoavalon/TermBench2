struct Node {
    value: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

struct Tree {
    root: Option<Box<Node>>,
}

fn check_tree(node: &Option<Box<Node>>) -> bool {
    match node {
        None => true,
        Some(n) => {
            if n.value < 0 {
                false
            } else {
                check_tree(&n.left) && check_tree(&n.right)
            }
        }
    }
}

fn validate_syntax(tree: &Tree) -> bool {
    match &tree.root {
        None => true,
        Some(node) => check_tree(&Some(node.clone())),
    }
}

fn main() {
    let tree = Tree {
        root: Some(Box::new(Node {
            value: 1,
            left: Some(Box::new(Node {
                value: 2,
                left: None,
                right: None,
            })),
            right: Some(Box::new(Node {
                value: 3,
                left: Some(Box::new(Node {
                    value: -4,
                    left: None,
                    right: None,
                })),
                right: None,
            })),
        })),
    };
    println!("{}", validate_syntax(&tree));
}