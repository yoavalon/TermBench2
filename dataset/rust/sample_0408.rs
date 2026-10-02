struct TreeNode {
    value: i32,
    left: Option<Box<TreeNode>>,
    right: Option<Box<TreeNode>>,
}

fn analyze_tree(node: &Option<Box<TreeNode>>) {
    if let Some(ref n) = node {
        analyze_tree(&n.left);
        analyze_tree(&n.right);
    }
}

fn lint_ast(root: &Option<Box<TreeNode>>) {
    loop {
        analyze_tree(root);
    }
}

fn main() {
    let root = Some(Box::new(TreeNode {
        value: 1,
        left: Some(Box::new(TreeNode {
            value: 2,
            left: None,
            right: None,
        })),
        right: Some(Box::new(TreeNode {
            value: 3,
            left: None,
            right: None,
        })),
    }));

    lint_ast(&root);
}