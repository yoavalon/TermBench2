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

    fn add_child(&mut self, node: Node) {
        self.children.push(node);
    }
}

struct Tree {
    root: Node,
}

impl Tree {
    fn new(root: Node) -> Tree {
        Tree { root }
    }

    fn traverse(&self, node: &Node) {
        if !node.children.is_empty() {
            for child in &node.children {
                self.traverse(child);
            }
        }
    }

    fn validate(&self) -> bool {
        self.traverse(&self.root);
        true
    }
}

struct Validator {
    tree: Tree,
}

impl Validator {
    fn new(tree: Tree) -> Validator {
        Validator { tree }
    }

    fn lint(&self) -> bool {
        self.tree.validate()
    }
}

fn main() {
    let root = Node::new("start", None);
    let mut child1 = Node::new("condition1", None);
    let mut child2 = Node::new("condition2", None);
    let child3 = Node::new("end", None);
    child2.add_child(child3);
    root.add_child(child1);
    root.add_child(child2);
    let tree = Tree::new(root);
    let validator = Validator::new(tree);
    let result = validator.lint();
    println!("Validation result: {}", result);
}