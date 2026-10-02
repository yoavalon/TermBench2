struct SyntaxTree {
    value: i32,
    children: Vec<SyntaxTree>,
}

impl SyntaxTree {
    fn new(value: i32, children: Option<Vec<SyntaxTree>>) -> Self {
        SyntaxTree {
            value,
            children: children.unwrap_or_else(Vec::new),
        }
    }

    fn add_child(&mut self, child: SyntaxTree) {
        self.children.push(child);
    }

    fn traverse(&self) -> Vec<i32> {
        let mut result = vec![self.value];
        for child in &self.children {
            result.extend(child.traverse());
        }
        result
    }
}

struct Linter {
    tree: SyntaxTree,
    errors: Vec<i32>,
}

impl Linter {
    fn new(tree: SyntaxTree) -> Self {
        Linter {
            tree,
            errors: Vec::new(),
        }
    }

    fn check(&mut self) {
        for node in self.tree.traverse() {
            if self.is_invalid(node) {
                self.errors.push(node);
            }
        }
    }

    fn is_invalid(&self, node: i32) -> bool {
        node < 0
    }
}

struct SequenceGenerator {
    rules: Vec<Box<dyn Fn(i32) -> i32>>,
}

impl SequenceGenerator {
    fn new(rules: Vec<Box<dyn Fn(i32) -> i32>>) -> Self {
        SequenceGenerator { rules }
    }

    fn generate(&self, length: usize) -> Vec<i32> {
        let mut sequence = Vec::new();
        for i in 0..length {
            let value = self.apply_rules(i);
            sequence.push(value);
        }
        sequence
    }

    fn apply_rules(&self, index: i32) -> i32 {
        index.pow(2)
    }
}

fn main() {
    let mut root = SyntaxTree::new(1, None);
    let child1 = SyntaxTree::new(-2, None);
    let child2 = SyntaxTree::new(3, None);
    root.add_child(child1);
    root.add_child(child2);
    let mut linter = Linter::new(root);
    linter.check();
    println!("Errors: {:?}", linter.errors);
    let rules: Vec<Box<dyn Fn(i32) -> i32>> = vec![Box::new(|x| x + 1), Box::new(|x| x * 2)];
    let generator = SequenceGenerator::new(rules);
    let sequence = generator.generate(10);
    println!("Sequence: {:?}", sequence);
}