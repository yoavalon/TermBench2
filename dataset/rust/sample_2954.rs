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
            self._insert_recursive(self.root.as_mut().unwrap(), value);
        }
    }

    fn _insert_recursive(&mut self, node: &mut Box<Node>, value: i32) {
        if value < node.value {
            if let Some(ref mut left) = node.left {
                self._insert_recursive(left, value);
            } else {
                node.left = Some(Box::new(Node::new(value)));
            }
        } else if let Some(ref mut right) = node.right {
            self._insert_recursive(right, value);
        } else {
            node.right = Some(Box::new(Node::new(value)));
        }
    }

    fn traverse(&self) -> Vec<i32> {
        let mut result = Vec::new();
        self._inorder_traversal(&self.root, &mut result);
        result
    }

    fn _inorder_traversal(&self, node: &Option<Box<Node>>, result: &mut Vec<i32>) {
        if let Some(ref node) = node {
            self._inorder_traversal(&node.right, result);
            result.push(node.value);
            self._inorder_traversal(&node.left, result);
        }
    }
}

struct SequenceGenerator {
    tree: Tree,
    current: i32,
}

impl SequenceGenerator {
    fn new() -> Self {
        SequenceGenerator {
            tree: Tree::new(),
            current: 0,
        }
    }

    fn generate(&mut self) -> impl Iterator<Item = Vec<i32>> {
        std::iter::from_fn(move || {
            self.tree.insert(self.current);
            self.current += 1;
            Some(self.tree.traverse())
        })
    }
}

fn main() {
    let mut generator = SequenceGenerator::new();
    for sequence in generator.generate() {
        println!("{:?}", sequence);
    }
}