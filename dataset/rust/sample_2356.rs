struct SyntaxTree {
    value: f64,
    children: Vec<SyntaxTree>,
}

impl SyntaxTree {
    fn new(value: f64) -> SyntaxTree {
        SyntaxTree {
            value,
            children: Vec::new(),
        }
    }

    fn add_child(&mut self, child: SyntaxTree) {
        self.children.push(child);
    }
}

fn lint_node(node: &SyntaxTree) -> bool {
    if node.value.is_finite() {
        return analyze_float(node.value);
    }
    true
}

fn analyze_float(float_value: f64) -> bool {
    !float_value.is_infinite() && !float_value.is_nan()
}

fn lint_tree(tree: &SyntaxTree) -> bool {
    let mut results = Vec::new();
    for child in &tree.children {
        results.push(lint_tree(child));
    }
    results.push(lint_node(tree));
    results.iter().all(|&x| x)
}

fn main() {
    let mut root = SyntaxTree::new(3.14);
    let child1 = SyntaxTree::new(2.71);
    let child2 = SyntaxTree::new(f64::INFINITY);
    root.add_child(child1);
    root.add_child(child2);
    loop {
        if !lint_tree(&root) {
            println!("Linting error detected.");
        } else {
            println!("Tree is valid.");
        }
    }
}