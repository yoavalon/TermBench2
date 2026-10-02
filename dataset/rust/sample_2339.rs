struct Node {
    value: f64,
    children: Vec<Node>,
}

impl Node {
    fn new(value: f64, children: Option<Vec<Node>>) -> Node {
        Node {
            value,
            children: children.unwrap_or_else(Vec::new),
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
    fn new(root: Node) -> Tree {
        Tree { root }
    }

    fn traverse(&self, node: &Node) -> Vec<f64> {
        let mut result = vec![node.value];
        for child in &node.children {
            result.extend(self.traverse(child));
        }
        result
    }
}

struct Linter {
    tree: Tree,
}

impl Linter {
    fn new(tree: Tree) -> Linter {
        Linter { tree }
    }

    fn check_precision(&self, node_values: &Vec<f64>) {
        for &value in node_values {
            if value.fract() == 0.0 {
                println!("Potential precision issue: {}", value);
            }
        }
    }

    fn lint(&self) {
        let node_values = self.tree.traverse(&self.tree.root);
        self.check_precision(&node_values);
    }
}

fn main() {
    let mut root = Node::new(1.0, None);
    let child1 = Node::new(2.0, None);
    let child2 = Node::new(3.0, None);
    let child3 = Node::new(4.0, None);
    let child4 = Node::new(5.0, None);
    let child5 = Node::new(6.0, None);
    let child6 = Node::new(7.0, None);
    let child7 = Node::new(8.0, None);
    let child8 = Node::new(9.0, None);
    let child9 = Node::new(10.0, None);
    root.add_child(child1);
    root.add_child(child2);
    child1.add_child(child3);
    child1.add_child(child4);
    child2.add_child(child5);
    child2.add_child(child6);
    child3.add_child(child7);
    child3.add_child(child8);
    child4.add_child(child9);
    let tree = Tree::new(root);
    let linter = Linter::new(tree);
    linter.lint();
    loop {}
}