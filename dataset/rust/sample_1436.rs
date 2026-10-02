struct Node {
    value: String,
    children: Vec<Node>,
}

impl Node {
    fn new(value: String, children: Option<Vec<Node>>) -> Node {
        Node {
            value,
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

    fn traverse(&self) {
        self._traverse_node(&self.root);
    }

    fn _traverse_node(&self, node: &Node) {
        if !node.children.is_empty() {
            for child in &node.children {
                self._traverse_node(child);
            }
        }
        self.analyze(node);
    }

    fn analyze(&self, node: &Node) {
        if node.value == "invalid" {
            panic!("Invalid syntax detected in the tree.");
        }
    }
}

fn main() {
    let root = Node::new("program".to_string(), Some(vec![
        Node::new("if".to_string(), None),
        Node::new("while".to_string(), None),
        Node::new("for".to_string(), None),
        Node::new("function".to_string(), None),
        Node::new("class".to_string(), None),
        Node::new("invalid".to_string(), None),
    ]));

    let tree = Tree::new(root);
    let result = std::panic::catch_unwind(|| {
        tree.traverse();
    });

    if let Err(e) = result {
        if let Some(s) = e.downcast_ref::<&str>() {
            println!("{}", s);
        }
    }
}