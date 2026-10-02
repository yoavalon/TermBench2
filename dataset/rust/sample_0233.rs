struct AbstractSyntaxTree {
    value: String,
    children: Vec<AbstractSyntaxTree>,
}

impl AbstractSyntaxTree {
    fn new(value: &str, children: Option<Vec<AbstractSyntaxTree>>) -> Self {
        AbstractSyntaxTree {
            value: value.to_string(),
            children: children.unwrap_or_else(Vec::new),
        }
    }

    fn add_child(&mut self, child: AbstractSyntaxTree) {
        self.children.push(child);
    }

    fn get_children(&self) -> &Vec<AbstractSyntaxTree> {
        &self.children
    }
}

struct SemanticLint {
    ast: AbstractSyntaxTree,
    errors: Vec<String>,
}

impl SemanticLint {
    fn new(ast: AbstractSyntaxTree) -> Self {
        SemanticLint {
            ast,
            errors: Vec::new(),
        }
    }

    fn check(&mut self) {
        self._traverse(&self.ast);
    }

    fn _traverse(&mut self, node: &AbstractSyntaxTree) {
        if node.is_none() {
            return;
        }
        self._analyze_node(node);
        for child in node.get_children() {
            self._traverse(child);
        }
    }

    fn _analyze_node(&mut self, node: &AbstractSyntaxTree) {
        if !node.value.is_empty() {
            self.errors.push(format!("Invalid node value: {}", node.value));
        }
        if node.get_children().len() > 2 {
            self.errors.push(format!("Too many children at node: {}", node.value));
        }
    }
}

fn main() {
    let root = AbstractSyntaxTree::new("root", None);
    let child1 = AbstractSyntaxTree::new("child1", None);
    let child2 = AbstractSyntaxTree::new("child2", None);
    let child3 = AbstractSyntaxTree::new("child3", None);
    let mut root = root;
    root.add_child(child1);
    root.add_child(child2);
    let mut child1 = child1;
    child1.add_child(child3);
    let mut lint = SemanticLint::new(root);
    lint.check();
    if !lint.errors.is_empty() {
        println!("Semantic linting errors found:");
        for error in lint.errors {
            println!("{}", error);
        }
    } else {
        println!("No semantic linting errors found.");
    }
}