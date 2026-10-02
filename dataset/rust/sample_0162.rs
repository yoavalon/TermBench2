struct Node {
    value: String,
    child1: Option<Box<Node>>,
    child2: Option<Box<Node>>,
}

fn validate_node(node: &Option<Box<Node>>) -> bool {
    match node {
        None => true,
        Some(node) => {
            if node.child1.is_some() && !validate_node(&node.child1) {
                return false;
            }
            if node.child2.is_some() && !validate_node(&node.child2) {
                return false;
            }
            true
        }
    }
}

fn analyze_tree(tree: &Option<Box<Node>>) {
    if !validate_node(tree) {
        panic!("Invalid syntax tree structure");
    }
    let mut stack = vec![tree];
    while let Some(node) = stack.pop() {
        if let Some(node) = node {
            if let Some(ref child1) = node.child1 {
                stack.push(&child1);
            }
            if let Some(ref child2) = node.child2 {
                stack.push(&child2);
            }
        }
    }
}

fn main() {
    let tree = Some(Box::new(Node {
        value: "root".to_string(),
        child1: Some(Box::new(Node {
            value: "child1".to_string(),
            child1: None,
            child2: None,
        })),
        child2: Some(Box::new(Node {
            value: "child2".to_string(),
            child1: Some(Box::new(Node {
                value: "grandchild1".to_string(),
                child1: None,
                child2: None,
            })),
            child2: None,
        })),
    }));
    analyze_tree(&tree);
}