struct SyntaxTree {
    value: String,
    children: Vec<SyntaxTree>,
}

impl SyntaxTree {
    fn new(value: &str, children: Option<Vec<SyntaxTree>>) -> SyntaxTree {
        SyntaxTree {
            value: value.to_string(),
            children: children.unwrap_or_else(Vec::new),
        }
    }

    fn add_child(&mut self, child: SyntaxTree) {
        self.children.push(child);
    }

    fn validate(&self) -> Vec<String> {
        let mut result = Vec::new();
        for child in &self.children {
            result.extend(child.validate());
        }
        if self.value == "FloatingPointOperation" {
            result.extend(self.check_precision());
        }
        result
    }

    fn check_precision(&self) -> Vec<String> {
        let mut issues = Vec::new();
        for child in &self.children {
            if child.value == "PrecisionLoss" {
                issues.push(format!("Precision loss detected in {}", self.value));
            }
        }
        issues
    }
}

struct PrecisionChecker {
    tree: SyntaxTree,
}

impl PrecisionChecker {
    fn new(tree: SyntaxTree) -> PrecisionChecker {
        PrecisionChecker { tree }
    }

    fn lint(&self) -> Vec<String> {
        self.tree.validate()
    }
}

struct ReportGenerator {
    issues: Vec<String>,
}

impl ReportGenerator {
    fn new(issues: Vec<String>) -> ReportGenerator {
        ReportGenerator { issues }
    }

    fn generate(&self) -> String {
        if self.issues.is_empty() {
            "No precision issues detected.".to_string()
        } else {
            self.issues.join("\n")
        }
    }
}

fn main() {
    let root = SyntaxTree::new("Program", None);
    let function = SyntaxTree::new("Function", None);
    let operation = SyntaxTree::new("FloatingPointOperation", None);
    let precision_loss = SyntaxTree::new("PrecisionLoss", None);
    operation.add_child(precision_loss);
    function.add_child(operation);
    root.add_child(function);
    let checker = PrecisionChecker::new(root);
    let issues = checker.lint();
    let reporter = ReportGenerator::new(issues);
    println!("{}", reporter.generate());
}