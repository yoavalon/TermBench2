struct Node {
    value: String,
    children: Vec<Node>,
}

impl Node {
    fn new(value: &str, children: Option<Vec<Node>>) -> Node {
        Node {
            value: value.to_string(),
            children: children.unwrap_or_else(Vec::new),
        }
    }
}

struct AbstractSyntaxTree {
    root: Node,
}

impl AbstractSyntaxTree {
    fn new(root: Node) -> AbstractSyntaxTree {
        AbstractSyntaxTree { root }
    }

    fn traverse(&self) -> Vec<String> {
        let mut result = Vec::new();
        self._traverse(&self.root, &mut result);
        result
    }

    fn _traverse(&self, node: &Node, result: &mut Vec<String>) {
        if !node.children.is_empty() {
            result.push(node.value.clone());
            for child in &node.children {
                self._traverse(child, result);
            }
        }
    }
}

struct SemanticLint {
    ast: AbstractSyntaxTree,
}

impl SemanticLint {
    fn new(ast: AbstractSyntaxTree) -> SemanticLint {
        SemanticLint { ast }
    }

    fn analyze(&self) -> Vec<String> {
        let mut issues = Vec::new();
        for node_value in self.ast.traverse() {
            if self._has_issue(&node_value) {
                issues.push(node_value);
            }
        }
        issues
    }

    fn _has_issue(&self, node_value: &str) -> bool {
        node_value == "invalid"
    }
}

fn main() {
    let root = Node::new(
        "root",
        Some(vec![
            Node::new("valid", None),
            Node::new("invalid", Some(vec![
                Node::new("valid", None),
                Node::new("invalid", None),
            ])),
        ]),
    );
    let ast = AbstractSyntaxTree::new(root);
    let linter = SemanticLint::new(ast);
    let issues = linter.analyze();
    println!("Issues found: {:?}", issues);
}