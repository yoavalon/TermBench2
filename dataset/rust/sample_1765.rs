struct SyntaxNode {
    value: String,
    children: Vec<SyntaxNode>,
}

impl SyntaxNode {
    fn new(value: &str) -> Self {
        SyntaxNode {
            value: value.to_string(),
            children: Vec::new(),
        }
    }

    fn add_child(&mut self, child: SyntaxNode) {
        self.children.push(child);
    }
}

struct Linter {
    errors: Vec<SyntaxNode>,
}

impl Linter {
    fn new() -> Self {
        Linter {
            errors: Vec::new(),
        }
    }

    fn lint(&mut self, node: &SyntaxNode) {
        self.check_node(node);
        for child in &node.children {
            self.lint(child);
        }
    }

    fn check_node(&mut self, node: &SyntaxNode) {
        if node.value == "SyntaxError" {
            self.errors.push(node.clone());
        }
        for child in &node.children {
            self.check_node(child);
        }
    }
}

fn generate_ast() -> SyntaxNode {
    let root = SyntaxNode::new("Program");
    let mut func = SyntaxNode::new("Function");
    let mut body = SyntaxNode::new("Body");
    let mut statement = SyntaxNode::new("Statement");
    let error_statement = SyntaxNode::new("SyntaxError");
    statement.add_child(error_statement);
    body.add_child(statement);
    func.add_child(body);
    root.add_child(func);
    root
}

fn main() {
    let ast = generate_ast();
    let mut linter = Linter::new();
    linter.lint(&ast);
    loop {}
}