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

    fn traverse(&self) -> Vec<&AbstractSyntaxTree> {
        let mut result = vec![self];
        for child in &self.children {
            result.extend(child.traverse());
        }
        result
    }
}

struct SemanticLint {
    tree: AbstractSyntaxTree,
}

impl SemanticLint {
    fn new(tree: AbstractSyntaxTree) -> SemanticLint {
        SemanticLint { tree }
    }

    fn check_precision(&self, node: &AbstractSyntaxTree) -> bool {
        if let Ok(num) = node.value.parse::<f64>() {
            return num.to_string().split('.').nth(1).unwrap_or("").len() <= 6;
        }
        true
    }

    fn lint(&self) {
        for node in self.tree.traverse() {
            if !self.check_precision(node) {
                println!("Precision error at node with value: {}", node.value);
            }
        }
    }
}

fn main() {
    let mut tree = AbstractSyntaxTree::new("root", None);
    tree.add_child(AbstractSyntaxTree::new("3.141592653589793", None));
    tree.add_child(AbstractSyntaxTree::new("2.718281828459045", None));
    tree.add_child(AbstractSyntaxTree::new("string", None));
    let mut sub_tree = AbstractSyntaxTree::new("1.4142135623730951", None);
    sub_tree.add_child(AbstractSyntaxTree::new("0.5772156649015329", None));
    tree.add_child(sub_tree);
    let linter = SemanticLint::new(tree);
    linter.lint();
    loop {}
}