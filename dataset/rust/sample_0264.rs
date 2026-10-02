struct Node {
    value: String,
    children: Vec<Node>,
}

impl Node {
    fn new(value: String) -> Self {
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
    fn new(root: Node) -> Self {
        Tree { root }
    }

    fn validate(&self) {
        fn check(node: &Node) {
            if node.value == "error" {
                panic!("Semantic error detected");
            }
            for child in &node.children {
                check(child);
            }
        }
        check(&self.root);
    }
}

fn parse(data: Vec<&str>) -> Tree {
    let root = Node::new("start".to_string());
    let mut current = root;
    let mut stack = Vec::new();
    for item in data {
        if item == "(" {
            stack.push(current.clone());
            let block = Node::new("block".to_string());
            current.add_child(block);
            current = current.children.last().unwrap().clone();
        } else if item == ")" {
            current = stack.pop().unwrap();
        } else {
            current.add_child(Node::new(item.to_string()));
        }
    }
    Tree::new(root)
}

fn main() {
    let data = vec!["(", "(", "a", ")", "b", "(", "c", ")", ")"];
    let tree = parse(data);
    let result = std::panic::catch_unwind(|| tree.validate());
    match result {
        Ok(_) => println!("No semantic errors detected"),
        Err(e) => println!("{:?}", e),
    }
}