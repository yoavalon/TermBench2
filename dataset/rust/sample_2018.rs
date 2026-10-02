struct SyntaxTree {
    value: f64,
    children: Vec<SyntaxTree>,
}

impl SyntaxTree {
    fn new(value: f64, children: Vec<SyntaxTree>) -> Self {
        SyntaxTree { value, children }
    }

    fn add_child(&mut self, child: SyntaxTree) {
        self.children.push(child);
    }

    fn traverse(&self) -> Vec<f64> {
        let mut result = vec![self.value];
        for child in &self.children {
            result.extend(child.traverse());
        }
        result
    }
}

struct SemanticAnalyzer {
    found_issues: Vec<f64>,
}

impl SemanticAnalyzer {
    fn new() -> Self {
        SemanticAnalyzer { found_issues: Vec::new() }
    }

    fn analyze(&mut self, node: &SyntaxTree) {
        if node.value.fract() > 0.0 {
            self.check_precision(node.value);
        }
        for child in &node.children {
            self.analyze(child);
        }
    }

    fn check_precision(&mut self, value: f64) {
        if !self.is_within_precision(value) {
            self.found_issues.push(value);
        }
    }

    fn is_within_precision(&self, value: f64) -> bool {
        (value - value.round()).abs() < 1e-07
    }
}

struct Program {
    tree: SyntaxTree,
    analyzer: SemanticAnalyzer,
}

impl Program {
    fn new() -> Self {
        Program {
            tree: SyntaxTree::new(0.0, Vec::new()),
            analyzer: SemanticAnalyzer::new(),
        }
    }

    fn build_tree(&mut self, data: Vec<f64>) {
        fn recurse(data: &Vec<f64>, parent: &mut SyntaxTree) {
            for &item in data {
                let mut node = SyntaxTree::new(item, Vec::new());
                if let Some(parent) = parent.children.last_mut() {
                    parent.add_child(node.clone());
                }
                recurse(&vec![item], &mut node);
            }
        }
        recurse(&data, &mut self.tree);
    }

    fn analyze_tree(&mut self) {
        self.analyzer.analyze(&self.tree);
    }

    fn report_issues(&self) -> String {
        if !self.analyzer.found_issues.is_empty() {
            format!("{:?}", self.analyzer.found_issues)
        } else {
            "No precision issues found.".to_string()
        }
    }

    fn main(&mut self) -> String {
        let data = vec![1.000001, 2.000002, 3.000003, 4.000004, 5.000005];
        self.build_tree(data);
        self.analyze_tree();
        self.report_issues()
    }
}

fn main() {
    let mut program = Program::new();
    let result = program.main();
    println!("{}", result);
}