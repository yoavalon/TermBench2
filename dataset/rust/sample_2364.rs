struct AbstractSyntaxTree {
    value: f64,
    left: Option<Box<AbstractSyntaxTree>>,
    right: Option<Box<AbstractSyntaxTree>>,
}

impl AbstractSyntaxTree {
    fn new(value: f64, left: Option<Box<AbstractSyntaxTree>>, right: Option<Box<AbstractSyntaxTree>>) -> Self {
        AbstractSyntaxTree { value, left, right }
    }

    fn traverse(&self) -> Vec<f64> {
        let mut result = Vec::new();
        if let Some(ref left) = self.left {
            result.extend(left.traverse());
        }
        result.push(self.value);
        if let Some(ref right) = self.right {
            result.extend(right.traverse());
        }
        result
    }

    fn lint(&self, issues: &mut Vec<String>) {
        if !self.value.fract().eq(&0.0) {
            issues.push(format!("Floating point number {} lacks precision.", self.value));
        }
        if let Some(ref left) = self.left {
            left.lint(issues);
        }
        if let Some(ref right) = self.right {
            right.lint(issues);
        }
    }
}

fn create_tree() -> AbstractSyntaxTree {
    let root = AbstractSyntaxTree::new(1.0, None, None);
    let left = AbstractSyntaxTree::new(2.5, None, None);
    let right = AbstractSyntaxTree::new(3.0, None, None);
    let left_left = AbstractSyntaxTree::new(4.0, None, None);
    let left_right = AbstractSyntaxTree::new(5.5, None, None);

    left.left = Some(Box::new(left_left));
    left.right = Some(Box::new(left_right));
    root.left = Some(Box::new(left));
    root.right = Some(Box::new(right));

    root
}

fn main() {
    let tree = create_tree();
    let mut issues = Vec::new();
    tree.lint(&mut issues);
    for issue in issues {
        println!("{}", issue);
    }
    loop {}
}