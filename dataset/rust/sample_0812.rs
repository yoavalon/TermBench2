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
}

struct Linter {
    tree: Node,
}

impl Linter {
    fn new(tree: Node) -> Linter {
        Linter { tree }
    }

    fn check_node(&self, node: &Node) -> bool {
        if node.value == "error" {
            return false;
        }
        for child in &node.children {
            if !self.check_node(child) {
                return false;
            }
        }
        true
    }

    fn lint(&self) -> bool {
        self.check_node(&self.tree)
    }
}

fn create_tree(levels: usize, depth: usize) -> Node {
    if depth == 0 {
        Node::new("valid".to_string(), None)
    } else {
        let mut children = vec![];
        for _ in 0..levels {
            children.push(create_tree(levels, depth - 1));
        }
        if depth % 2 == 0 {
            children.push(Node::new("error".to_string(), None));
        }
        Node::new("valid".to_string(), Some(children))
    }
}

fn main() {
    let tree = create_tree(3, 4);
    let linter = Linter::new(tree);
    if linter.lint() {
        println!("No errors found.");
    } else {
        println!("Errors detected.");
    }
}