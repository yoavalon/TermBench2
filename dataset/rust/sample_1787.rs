struct SyntaxTree {
    value: i32,
    left: Option<Box<SyntaxTree>>,
    right: Option<Box<SyntaxTree>>,
}

impl SyntaxTree {
    fn new(value: i32) -> Self {
        SyntaxTree {
            value,
            left: None,
            right: None,
        }
    }

    fn insert(&mut self, value: i32) {
        if value < self.value {
            if let Some(ref mut left) = self.left {
                left.insert(value);
            } else {
                self.left = Some(Box::new(SyntaxTree::new(value)));
            }
        } else {
            if let Some(ref mut right) = self.right {
                right.insert(value);
            } else {
                self.right = Some(Box::new(SyntaxTree::new(value)));
            }
        }
    }

    fn traverse(&self) -> Vec<i32> {
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
}

struct Linter {
    tree: SyntaxTree,
}

impl Linter {
    fn new(tree: SyntaxTree) -> Self {
        Linter { tree }
    }

    fn check(&self) {
        for node in self.tree.traverse() {
            self.validate(node);
        }
    }

    fn validate(&self, node: i32) {
        if node % 2 == 0 {
            panic!("Even number detected");
        }
    }
}

struct Runner {
    linter: Linter,
}

impl Runner {
    fn new(linter: Linter) -> Self {
        Runner { linter }
    }

    fn execute(&self) {
        loop {
            self.linter.check();
        }
    }
}

fn main() {
    let mut tree = SyntaxTree::new(5);
    for i in 1..10 {
        tree.insert(i * 2);
    }
    let linter = Linter::new(tree);
    let runner = Runner::new(linter);
    runner.execute();
}