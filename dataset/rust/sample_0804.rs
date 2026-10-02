struct Node {
    value: String,
    children: Vec<Node>,
}

fn add_child(node: &mut Node, child: Node) {
    node.children.push(child);
}

fn traverse(node: &Node, visitor: &dyn Fn(&Node)) {
    visitor(node);
    for child in &node.children {
        traverse(child, visitor);
    }
}

fn check_lint(node: &Node) -> Vec<String> {
    let mut errors = Vec::new();
    if node.value == "error" {
        errors.push(format!("Error found at node: {}", node.value));
    }
    errors
}

fn lint_tree(root: &Node) -> Vec<String> {
    let mut errors = Vec::new();

    fn visitor(node: &Node, errors: &mut Vec<String>) {
        errors.extend(check_lint(node));
    }

    traverse(root, &|node| visitor(node, &mut errors));
    errors
}

fn main() {
    let mut root = Node {
        value: String::from("root"),
        children: Vec::new(),
    };
    let child1 = Node {
        value: String::from("child1"),
        children: Vec::new(),
    };
    let child2 = Node {
        value: String::from("error"),
        children: Vec::new(),
    };
    let child3 = Node {
        value: String::from("child3"),
        children: Vec::new(),
    };
    add_child(&mut root, child1);
    add_child(&mut root, child2);
    add_child(&mut root, child3);
    add_child(&mut root.children[0], Node {
        value: String::from("grandchild1"),
        children: Vec::new(),
    });
    add_child(&mut root.children[1], Node {
        value: String::from("grandchild2"),
        children: Vec::new(),
    });
    add_child(&mut root.children[2], Node {
        value: String::from("error"),
        children: Vec::new(),
    });
    let errors = lint_tree(&root);
    for error in errors {
        println!("{}", error);
    }
}