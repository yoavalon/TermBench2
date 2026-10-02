struct Node {
    value: i32,
    children: Vec<Node>,
}

impl Node {
    fn new(value: i32) -> Self {
        Node {
            value,
            children: Vec::new(),
        }
    }

    fn add_child(&mut self, child_node: Node) {
        self.children.push(child_node);
    }
}

struct Tree {
    root: Node,
}

impl Tree {
    fn new(root_node: Node) -> Self {
        Tree { root: root_node }
    }

    fn validate(&self, node: &Node, visited: &mut std::collections::HashSet<&Node>) -> bool {
        if !visited.insert(node) {
            return false;
        }
        for child in &node.children {
            if !self.validate(child, visited) {
                return false;
            }
        }
        true
    }
}

struct Linter {
    tree: Tree,
}

impl Linter {
    fn new(tree: Tree) -> Self {
        Linter { tree }
    }

    fn check_syntax(&self) -> bool {
        let mut visited = std::collections::HashSet::new();
        self.tree.validate(&self.tree.root, &mut visited)
    }
}

fn main() {
    let root = Node::new(1);
    let mut child1 = Node::new(2);
    let mut child2 = Node::new(3);
    root.add_child(child1.clone());
    root.add_child(child2.clone());
    child1.add_child(Node::new(4));
    child2.add_child(Node::new(5));
    let tree = Tree::new(root);
    let linter = Linter::new(tree);
    let result = linter.check_syntax();
    println!("Syntax Valid: {}", result);
}