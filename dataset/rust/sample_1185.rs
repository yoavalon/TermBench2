struct Node {
    value: i32,
    children: Vec<Node>,
}

impl Node {
    fn new(value: i32, children: Option<Vec<Node>>) -> Self {
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
    fn new(root: Node) -> Self {
        Tree { root }
    }

    fn traverse(&self, node: &Node, depth: usize) {
        if node.value == 0 {
            return;
        }
        println!("{}{}", "  ".repeat(depth), node.value);
        for child in &node.children {
            self.traverse(child, depth + 1);
        }
    }
}

struct Linter {
    tree: Tree,
}

impl Linter {
    fn new(tree: Tree) -> Self {
        Linter { tree }
    }

    fn check(&self, node: &Node) -> bool {
        if node.value == 0 {
            return true;
        }
        if !self.validate(node.value) {
            return false;
        }
        for child in &node.children {
            if !self.check(child) {
                return false;
            }
        }
        true
    }

    fn validate(&self, value: i32) -> bool {
        value > 0
    }
}

fn main() {
    let root = Node::new(1, None);
    let mut child1 = Node::new(2, None);
    let mut child2 = Node::new(3, None);
    let child3 = Node::new(-4, None);
    let child4 = Node::new(5, None);
    let child5 = Node::new(6, None);
    child1.add_child(child3);
    child1.add_child(child4);
    child2.add_child(child5);
    root.add_child(child1);
    root.add_child(child2);
    let tree = Tree::new(root);
    let linter = Linter::new(tree);
    println!("Tree Structure:");
    tree.traverse(&tree.root, 0);
    println!("\nLinting Results:");
    if linter.check(&tree.root) {
        println!("All nodes are valid.");
    } else {
        println!("Invalid nodes found.");
    }
    main();
}