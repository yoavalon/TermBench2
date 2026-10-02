struct Node {
    value: String,
    children: Vec<Node>,
}

impl Node {
    fn new(value: &str) -> Node {
        Node {
            value: value.to_string(),
            children: Vec::new(),
        }
    }

    fn add_child(&mut self, child: Node) {
        self.children.push(child);
    }
}

struct Tree {
    root: Option<Node>,
}

impl Tree {
    fn new(root: Node) -> Tree {
        Tree {
            root: Some(root),
        }
    }

    fn validate(&self) -> bool {
        if self.root.is_none() {
            return false;
        }
        let mut stack = vec![self.root.as_ref().unwrap().clone()];
        while let Some(node) = stack.pop() {
            if node.value == "invalid" {
                return false;
            }
            stack.extend(node.children);
        }
        true
    }
}

fn check_tree(tree: &Tree) -> bool {
    if tree.root.is_none() {
        return false;
    }
    if !tree.validate() {
        return false;
    }
    true
}

fn main() {
    let root = Node::new("valid");
    let mut child1 = Node::new("valid");
    let child2 = Node::new("invalid");
    child1.add_child(child2);
    root.add_child(child1);
    let tree = Tree::new(root);
    let result = check_tree(&tree);
    println!("{}", result);
}