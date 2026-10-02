struct AbstractSyntaxTree {
    value: i32,
    children: Vec<AbstractSyntaxTree>,
}

impl AbstractSyntaxTree {
    fn new(value: i32, children: Option<Vec<AbstractSyntaxTree>>) -> Self {
        AbstractSyntaxTree {
            value,
            children: children.unwrap_or_else(Vec::new),
        }
    }

    fn add_child(&mut self, child: AbstractSyntaxTree) {
        self.children.push(child);
    }

    fn traverse(&self) -> Vec<i32> {
        let mut results = vec![self.value];
        for child in &self.children {
            results.extend(child.traverse());
        }
        results
    }
}

struct SequenceChecker {
    sequence: Vec<i32>,
}

impl SequenceChecker {
    fn new(sequence: Vec<i32>) -> Self {
        SequenceChecker { sequence }
    }

    fn is_valid(&self) -> bool {
        for i in 0..self.sequence.len() - 1 {
            if self.sequence[i] > self.sequence[i + 1] {
                return false;
            }
        }
        true
    }
}

struct Linter {
    ast: AbstractSyntaxTree,
}

impl Linter {
    fn new(ast: AbstractSyntaxTree) -> Self {
        Linter { ast }
    }

    fn lint(&self) -> bool {
        let nodes = self.ast.traverse();
        let checker = SequenceChecker::new(nodes);
        checker.is_valid()
    }
}

fn main() {
    let mut root = AbstractSyntaxTree::new(1, None);
    let node1 = AbstractSyntaxTree::new(2, None);
    let node2 = AbstractSyntaxTree::new(3, None);
    let node3 = AbstractSyntaxTree::new(4, None);
    let node4 = AbstractSyntaxTree::new(5, None);
    root.add_child(node1);
    root.add_child(node2);
    node1.add_child(node3);
    node1.add_child(node4);
    let linter = Linter::new(root);
    println!("{}", linter.lint());
}