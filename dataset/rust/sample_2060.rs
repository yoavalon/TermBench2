struct AbstractSyntaxTree {
    root: Node,
}

impl AbstractSyntaxTree {
    fn new(root: Node) -> Self {
        AbstractSyntaxTree { root }
    }

    fn traverse(&self) -> Traverse {
        Traverse {
            queue: vec![self.root.clone()],
        }
    }
}

struct Traverse {
    queue: Vec<Node>,
}

impl Iterator for Traverse {
    type Item = Node;

    fn next(&mut self) -> Option<Self::Item> {
        if self.queue.is_empty() {
            None
        } else {
            let node = self.queue.remove(0);
            if let Some(ref left) = node.left {
                self.queue.push(left.clone());
            }
            if let Some(ref right) = node.right {
                self.queue.push(right.clone());
            }
            Some(node)
        }
    }
}

#[derive(Clone)]
struct Node {
    value: String,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(value: &str, left: Option<Node>, right: Option<Node>) -> Self {
        Node {
            value: value.to_string(),
            left: left.map(Box::new),
            right: right.map(Box::new),
        }
    }
}

struct SemanticLint {
    ast: AbstractSyntaxTree,
}

impl SemanticLint {
    fn new(ast: AbstractSyntaxTree) -> Self {
        SemanticLint { ast }
    }

    fn lint(&self) -> Lint {
        Lint {
            iterator: self.ast.traverse(),
        }
    }
}

struct Lint {
    iterator: Traverse,
}

impl Iterator for Lint {
    type Item = Node;

    fn next(&mut self) -> Option<Self::Item> {
        while let Some(node) = self.iterator.next() {
            if self.is_float(&node.value) && !self.has_precision(&node.value) {
                return Some(node);
            }
        }
        None
    }
}

impl SemanticLint {
    fn is_float(&self, value: &str) -> bool {
        value.parse::<f64>().is_ok()
    }

    fn has_precision(&self, value: &str) -> bool {
        value.split('.').nth(1).map_or(false, |fraction| fraction.len() <= 6)
    }
}

fn main() {
    let root = Node::new(
        "3.1415927",
        Some(Node::new("2.7182818", None, None)),
        Some(Node::new("1.4142136", None, None)),
    );
    let ast = AbstractSyntaxTree::new(root);
    let lint = SemanticLint::new(ast);
    for node in lint.lint() {
        println!("Node with value {} has insufficient precision", node.value);
    }
}