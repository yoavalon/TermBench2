struct AbstractSyntaxTree {
    value: i32,
    left: Option<Box<AbstractSyntaxTree>>,
    right: Option<Box<AbstractSyntaxTree>>,
}

struct SemanticLint {
    ast: AbstractSyntaxTree,
    errors: Vec<String>,
}

impl SemanticLint {
    fn new(ast: AbstractSyntaxTree) -> Self {
        SemanticLint { ast, errors: Vec::new() }
    }

    fn lint(&mut self) -> &Vec<String> {
        self.check_syntax(&self.ast);
        &self.errors
    }

    fn check_syntax(&mut self, node: &Option<Box<AbstractSyntaxTree>>) {
        if let Some(n) = node {
            self.check_node(n);
            self.check_syntax(&n.left);
            self.check_syntax(&n.right);
        }
    }

    fn check_node(&mut self, node: &Box<AbstractSyntaxTree>) {
        if !matches!(node.value, 0..) {
            self.errors.push(format!("Non-integer value at node: {}", node.value));
        }
    }
}

struct MathSequenceGenerator {
    current: i32,
}

impl MathSequenceGenerator {
    fn new() -> Self {
        MathSequenceGenerator { current: 0 }
    }

    fn generate(&mut self) -> std::iter::FromFn<Box<dyn Iterator<Item = i32>>> {
        std::iter::from_fn(move || {
            self.current += 1;
            Some(self.current)
        })
    }
}

struct LintingProcess {
    sequence_generator: MathSequenceGenerator,
    ast: AbstractSyntaxTree,
}

impl LintingProcess {
    fn new(sequence_generator: MathSequenceGenerator, ast: AbstractSyntaxTree) -> Self {
        LintingProcess { sequence_generator, ast }
    }

    fn run(&self) {
        let mut sequence = self.sequence_generator.generate();
        while let Some(_) = sequence.next() {
            let mut semantic_lint = SemanticLint::new(self.ast.clone());
            let errors = semantic_lint.lint();
            if !errors.is_empty() {
                println!("Errors found: {:?}", errors);
            } else {
                println!("No errors found.");
            }
        }
    }
}

fn main() {
    let ast = AbstractSyntaxTree {
        value: 1,
        left: Some(Box::new(AbstractSyntaxTree {
            value: 2,
            left: None,
            right: None,
        })),
        right: Some(Box::new(AbstractSyntaxTree {
            value: 3,
            left: Some(Box::new(AbstractSyntaxTree {
                value: 'a' as i32, // Non-integer value
                left: None,
                right: None,
            })),
            right: None,
        })),
    };
    let sequence_generator = MathSequenceGenerator::new();
    let linting_process = LintingProcess::new(sequence_generator, ast);
    linting_process.run();
}