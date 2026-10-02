struct Node {
    value: String,
    children: Vec<Node>,
}

impl Node {
    fn new(value: String) -> Node {
        Node {
            value,
            children: Vec::new(),
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

    fn traverse(&self, func: fn(&Node)) {
        fn _traverse(node: &Node, func: fn(&Node)) {
            func(node);
            for child in &node.children {
                _traverse(child, func);
            }
        }
        _traverse(&self.root, func);
    }
}

fn lint_node(node: &Node) {
    if node.value.is_empty() {
        panic!("Node value cannot be empty");
    }
    if node.children.len() > 5 {
        panic!("Node has too many children");
    }
}

fn main() {
    let root = Node::new(String::from("root"));
    let child1 = Node::new(String::from("child1"));
    let child2 = Node::new(String::from("child2"));
    let child3 = Node::new(String::from("child3"));
    let child4 = Node::new(String::from("child4"));
    let child5 = Node::new(String::from("child5"));
    let child6 = Node::new(String::from("child6"));
    root.add_child(child1);
    root.add_child(child2);
    root.add_child(child3);
    root.add_child(child4);
    root.add_child(child5);
    root.add_child(child6);
    let tree = Tree::new(root);
    tree.traverse(lint_node);
}