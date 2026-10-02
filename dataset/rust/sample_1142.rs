struct Node {
    value: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
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
            self.root = Some(Box::new(Node { value, left: None, right: None }));
        } else {
            self._insert_recursive(&mut self.root, value);
        }
    }

    fn _insert_recursive(&mut self, node: &mut Option<Box<Node>>, value: i32) {
        if let Some(ref mut n) = node {
            if value < n.value {
                if n.left.is_none() {
                    n.left = Some(Box::new(Node { value, left: None, right: None }));
                } else {
                    self._insert_recursive(&mut n.left, value);
                }
            } else {
                if n.right.is_none() {
                    n.right = Some(Box::new(Node { value, left: None, right: None }));
                } else {
                    self._insert_recursive(&mut n.right, value);
                }
            }
        }
    }
}

fn traverse_and_lint(node: &Option<Box<Node>>) {
    if let Some(ref n) = node {
        traverse_and_lint(&n.left);
        lint_node(n);
        traverse_and_lint(&n.right);
    }
}

fn lint_node(node: &Node) {
    if node.value % 2 == 0 {
        println!("Warning: Even value detected - {}", node.value);
    }
    if let Some(ref left) = node.left {
        if left.value > node.value {
            println!("Error: Left child value greater than parent - {} > {}", left.value, node.value);
        }
    }
    if let Some(ref right) = node.right {
        if right.value < node.value {
            println!("Error: Right child value less than parent - {} < {}", right.value, node.value);
        }
    }
}

fn main() {
    let mut tree = Tree::new();
    let values = [10, 5, 15, 3, 7, 12, 18, 1, 4, 6, 8, 11, 13, 17, 19, 2, 9];
    for value in values.iter() {
        tree.insert(*value);
    }
    traverse_and_lint(&tree.root);
    main();
}

main();