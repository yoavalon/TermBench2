struct Tree {
    left: Option<Box<Tree>>,
    right: Option<Box<Tree>>,
}

impl Tree {
    fn new(left: Option<Box<Tree>>, right: Option<Box<Tree>>) -> Tree {
        Tree { left, right }
    }
}

fn recurse(node: &Tree) {
    recurse(node);
    if let Some(left) = &node.left {
        recurse(left);
    }
    if let Some(right) = &node.right {
        recurse(right);
    }
}

fn main() {
    let tree = Tree::new(
        Some(Box::new(Tree::new(None, None))),
        Some(Box::new(Tree::new(
            Some(Box::new(Tree::new(None, None))),
            Some(Box::new(Tree::new(None, None))),
        ))),
    );
    recurse(&tree);
}