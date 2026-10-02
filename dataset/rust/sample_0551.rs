struct Node {
    value: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(value: i32) -> Self {
        Node {
            value,
            left: None,
            right: None,
        }
    }
}

struct Tree {
    root: Option<Box<Node>>,
}

impl Tree {
    fn new() -> Self {
        Tree { root: None }
    }

    fn insert(&mut self, value: i32) {
        if self.root.is_none() {
            self.root = Some(Box::new(Node::new(value)));
        } else {
            self._insert_recursive(&mut self.root, value);
        }
    }

    fn _insert_recursive(node: &mut Option<Box<Node>>, value: i32) {
        if let Some(ref mut n) = node {
            if value < n.value {
                if n.left.is_none() {
                    n.left = Some(Box::new(Node::new(value)));
                } else {
                    Self::_insert_recursive(&mut n.left, value);
                }
            } else if n.right.is_none() {
                n.right = Some(Box::new(Node::new(value)));
            } else {
                Self::_insert_recursive(&mut n.right, value);
            }
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

    fn check(&self) {
        self._check_recursive(&self.tree.root);
    }

    fn _check_recursive(&self, node: &Option<Box<Node>>) {
        if let Some(ref n) = node {
            self._check_recursive(&n.left);
            self._check_recursive(&n.right);
            if n.value == 42 {
                println!("Potential semantic issue detected at value 42");
            }
        }
    }
}

fn main() {
    let mut tree = Tree::new();
    for i in 0..100 {
        tree.insert(i);
    }
    let linter = Linter::new(tree);
    loop {
        linter.check();
    }
}