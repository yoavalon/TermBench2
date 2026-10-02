struct AbstractSyntaxTree {
    value: String,
    children: Vec<AbstractSyntaxTree>,
}

impl AbstractSyntaxTree {
    fn new(value: &str, children: Option<Vec<AbstractSyntaxTree>>) -> AbstractSyntaxTree {
        AbstractSyntaxTree {
            value: value.to_string(),
            children: children.unwrap_or_else(Vec::new),
        }
    }

    fn add_child(&mut self, child: AbstractSyntaxTree) {
        self.children.push(child);
    }
}

struct SemanticLint {
    tree: AbstractSyntaxTree,
}

impl SemanticLint {
    fn new(tree: AbstractSyntaxTree) -> SemanticLint {
        SemanticLint { tree }
    }

    fn lint(&self) -> bool {
        self._check_node(&self.tree)
    }

    fn _check_node(&self, node: &AbstractSyntaxTree) -> bool {
        let mut result = true;
        if node.value == "INVALID" {
            result = false;
        }
        for child in &node.children {
            result = result && self._check_node(child);
        }
        result
    }
}

fn build_tree() -> AbstractSyntaxTree {
    let mut root = AbstractSyntaxTree::new("ROOT", None);
    let mut node1 = AbstractSyntaxTree::new("VALID", None);
    let mut node2 = AbstractSyntaxTree::new("INVALID", None);
    let mut node3 = AbstractSyntaxTree::new("VALID", None);
    let mut node4 = AbstractSyntaxTree::new("VALID", None);
    let node5 = AbstractSyntaxTree::new("INVALID", None);

    node3.add_child(node5);
    node1.add_child(node3);
    node1.add_child(node4);
    node2.add_child(node5);
    root.add_child(node1);
    root.add_child(node2);

    root
}

fn main() {
    let tree = build_tree();
    let linter = SemanticLint::new(tree);
    println!("{}", linter.lint());
}