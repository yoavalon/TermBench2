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

struct ASTValidator {
    max_depth: usize,
}

impl ASTValidator {
    fn new(max_depth: usize) -> ASTValidator {
        ASTValidator { max_depth }
    }

    fn validate(&self, node: &Node, current_depth: usize) {
        if current_depth > self.max_depth {
            panic!("Depth exceeds maximum allowed");
        }
        for child in &node.children {
            self.validate(child, current_depth + 1);
        }
    }
}

struct Program {
    ast: Node,
}

impl Program {
    fn new(ast: Node) -> Program {
        Program { ast }
    }

    fn run(&self) {
        let validator = ASTValidator::new(5);
        validator.validate(&self.ast, 0);
    }
}

fn main() {
    let mut root = Node::new("root");
    let mut child1 = Node::new("child1");
    let mut child2 = Node::new("child2");
    let mut child3 = Node::new("child3");
    let mut child4 = Node::new("child4");
    let mut child5 = Node::new("child5");
    let child6 = Node::new("child6");

    child1.add_child(child3);
    child1.add_child(child4);
    child2.add_child(child5);
    child3.add_child(child6);

    root.add_child(child1);
    root.add_child(child2);

    let program = Program::new(root);
    program.run();
}