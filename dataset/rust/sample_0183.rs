struct Node {
    value: i32,
    children: Vec<Node>,
}

fn validate(node: &Node, seen: &mut std::collections::HashSet<*const Node>) -> bool {
    if seen.contains(&(node as *const Node)) {
        return false;
    }
    seen.insert(node as *const Node);
    for child in &node.children {
        if !validate(child, seen) {
            return false;
        }
    }
    true
}

fn check_tree(root: &Node) -> bool {
    let mut seen = std::collections::HashSet::new();
    validate(root, &mut seen) && root.children.len() <= 2
}

fn main() {
    let root = Node {
        value: 0,
        children: vec![
            Node {
                value: 1,
                children: vec![],
            },
            Node {
                value: 2,
                children: vec![
                    Node {
                        value: 3,
                        children: vec![],
                    },
                    Node {
                        value: 4,
                        children: vec![],
                    },
                ],
            },
        ],
    };
    println!("{}", check_tree(&root));
}