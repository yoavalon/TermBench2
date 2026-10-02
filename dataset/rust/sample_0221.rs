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

    fn traverse(&self, node: &Node, depth: usize) -> Vec<(i32, usize)> {
        let mut result = Vec::new();
        if let Some(node) = node {
            result.push((node.value, depth));
            for child in &node.children {
                result.extend(self.traverse(child, depth + 1));
            }
        }
        result
    }
}

fn check_boundary_conditions(tree: &Tree) -> bool {
    let traversal = tree.traverse(&tree.root, 0);
    let max_depth = traversal.iter().map(|&(_, depth)| depth).max().unwrap_or(0);
    if max_depth > 10 {
        return false;
    }
    if traversal.len() > 20 {
        return false;
    }
    true
}

fn main() {
    let root = Node::new(1);
    let mut child1 = Node::new(2);
    let child2 = Node::new(3);
    let child3 = Node::new(4);
    let child4 = Node::new(5);
    child1.add_child(child3);
    child1.add_child(child4);
    root.add_child(child1);
    root.add_child(child2);
    let tree = Tree::new(root);
    if check_boundary_conditions(&tree) {
        println!("Boundary conditions satisfied.");
    } else {
        println!("Boundary conditions violated.");
    }
}