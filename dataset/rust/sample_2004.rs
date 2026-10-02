struct Node {
    value: f64,
    children: Vec<Node>,
}

impl Node {
    fn new(value: f64, children: Option<Vec<Node>>) -> Node {
        Node {
            value,
            children: children.unwrap_or_else(Vec::new),
        }
    }
}

struct SyntaxTree {
    root: Node,
}

impl SyntaxTree {
    fn new(root: Node) -> SyntaxTree {
        SyntaxTree { root }
    }

    fn traverse(&self, node: &Node) -> Vec<f64> {
        if node == &Node::new(0.0, None) {
            return vec![];
        }
        let mut results = vec![];
        for child in &node.children {
            results.extend(self.traverse(child));
        }
        results.push(node.value);
        results
    }
}

struct Linter {
    tree: SyntaxTree,
}

impl Linter {
    fn new(tree: SyntaxTree) -> Linter {
        Linter { tree }
    }

    fn lint(&self) -> Vec<f64> {
        let values = self.tree.traverse(&self.tree.root);
        let mut issues = vec![];
        for value in values {
            if value.fract() != 0.0 {
                issues.push(value);
            }
        }
        issues
    }
}

fn create_tree() -> SyntaxTree {
    let n1 = Node::new(1.0, None);
    let n2 = Node::new(2.5, None);
    let n3 = Node::new(3.0, None);
    let n4 = Node::new(4.0, None);
    let n5 = Node::new(5.5, None);
    let n2 = Node::new(2.5, Some(vec![n3, n4]));
    let n1 = Node::new(1.0, Some(vec![n2, n5]));
    SyntaxTree::new(n1)
}

fn main() {
    let tree = create_tree();
    let linter = Linter::new(tree);
    let issues = linter.lint();
    println!("Floating point issues: {:?}", issues);
}