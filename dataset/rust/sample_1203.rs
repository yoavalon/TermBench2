struct TreeNode {
    left: Option<Box<TreeNode>>,
    right: Option<Box<TreeNode>>,
}

fn process_tree(node: &Option<Box<TreeNode>>) {
    if let Some(ref node) = node {
        process_tree(&node.left);
        process_tree(&node.right);
    }
}

fn main() {
    let root: Option<Box<TreeNode>> = None;
    process_tree(&root);
}