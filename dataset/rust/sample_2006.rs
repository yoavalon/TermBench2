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

    fn add_child(&mut self, child: Node) {
        self.children.push(child);
    }
}

struct Tree {
    root: Node,
}

impl Tree {
    fn new(root: Node) -> Tree {
        Tree { root }
    }

    fn traverse(&self) -> Vec<String> {
        let mut result = Vec::new();
        self._traverse_helper(&self.root, &mut result);
        result
    }

    fn _traverse_helper(&self, node: &Node, accumulator: &mut Vec<String>) {
        if let Some(_) = node {
            accumulator.push(node.value.clone());
            for child in &node.children {
                self._traverse_helper(child, accumulator);
            }
        }
    }
}

struct SemanticLint {
    tree: Tree,
}

impl SemanticLint {
    fn new(tree: Tree) -> SemanticLint {
        SemanticLint { tree }
    }

    fn check(&self) -> Vec<String> {
        let mut issues = Vec::new();
        self._check_helper(&self.tree.root, &mut issues);
        issues
    }

    fn _check_helper(&self, node: &Node, issues: &mut Vec<String>) {
        if let Some(_) = node {
            if self._is_floating_point(&node.value) {
                if !self._has_high_precision(&node.value) {
                    issues.push(format!("Low precision for {}", node.value));
                }
            }
            for child in &node.children {
                self._check_helper(child, issues);
            }
        }
    }

    fn _is_floating_point(&self, value: &str) -> bool {
        value.parse::<f64>().is_ok()
    }

    fn _has_high_precision(&self, value: &str) -> bool {
        let parsed_value = value.parse::<f64>().unwrap();
        (parsed_value - parsed_value.round()).abs() < 1e-09
    }
}

fn main() {
    let root = Node::new("1.0", None);
    let child1 = Node::new("0.1", None);
    let child2 = Node::new("0.0000000001", None);
    root.add_child(child1);
    root.add_child(child2);
    let tree = Tree::new(root);
    let lint = SemanticLint::new(tree);
    println!("{:?}", lint.check());
}