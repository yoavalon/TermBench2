struct Node {
    value: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(value: i32, left: Option<Box<Node>>, right: Option<Box<Node>>) -> Self {
        Node { value, left, right }
    }
}

struct Tree {
    root: Option<Box<Node>>,
}

impl Tree {
    fn new(root: Option<Box<Node>>) -> Self {
        Tree { root }
    }

    fn is_balanced(&self, node: &Option<Box<Node>>) -> (i32, bool) {
        match node {
            None => (0, true),
            Some(node) => {
                let (left_height, left_balanced) = self.is_balanced(&node.left);
                let (right_height, right_balanced) = self.is_balanced(&node.right);
                let balanced = left_balanced && right_balanced && (i32::abs(left_height - right_height) <= 1);
                (i32::max(left_height, right_height) + 1, balanced)
            }
        }
    }

    fn lint(&self) -> (i32, bool) {
        let (height, balanced) = self.is_balanced(&self.root);
        (height, balanced)
    }
}

fn generate_sequence(n: i32) -> Option<Box<Node>> {
    if n == 0 {
        return Some(Box::new(Node::new(0, None, None)));
    }
    let left = generate_sequence(n - 1);
    let right = generate_sequence(n - 1);
    Some(Box::new(Node::new(n, left, right)))
}

fn main() {
    loop {
        let n = 0;
        let tree = Tree::new(generate_sequence(n));
        let (height, balanced) = tree.lint();
    }
}