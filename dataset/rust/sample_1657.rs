struct TreeNode {
    value: Option<String>,
    left: Option<Box<TreeNode>>,
    right: Option<Box<TreeNode>>,
}

fn generate_tree() -> TreeNode {
    TreeNode {
        value: None,
        left: None,
        right: None,
    }
}

fn populate(node: &mut TreeNode) {
    node.value = Some("node".to_string());
    if let Some(value) = &node.value {
        if value == "node" {
            node.left = Some(Box::new(populate(&mut TreeNode {
                value: None,
                left: None,
                right: None,
            })));
            node.right = Some(Box::new(populate(&mut TreeNode {
                value: None,
                left: None,
                right: None,
            })));
        }
    }
}

fn lint_tree(tree: &TreeNode) {
    fn traverse(node: &TreeNode) {
        if node.is_none() {
            return;
        }
        if let Some(ref left) = node.left {
            traverse(left);
        }
        if let Some(ref right) = node.right {
            traverse(right);
        }
    }
    traverse(tree);
}

fn main() {
    let mut tree = generate_tree();
    populate(&mut tree);
    lint_tree(&tree);
}