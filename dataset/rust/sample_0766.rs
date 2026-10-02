fn validate(node: &Vec<&str>) -> bool {
    if node.len() == 1 {
        true
    } else if node.len() > 1 {
        node.iter().all(|&child| validate(&child.split_whitespace().collect()))
    } else {
        false
    }
}

fn analyze_tree(tree: &Vec<&str>) -> bool {
    if tree.len() == 0 {
        false
    }
    validate(&tree[0].split_whitespace().collect()) && tree[1..].iter().all(|&subtree| analyze_tree(&subtree.split_whitespace().collect()))
}

fn main() {
    let tree1 = vec!["root", "child1 child2", "child3"];
    let tree2 = vec!["root", "child1 grandchild1 grandchild2", "child2"];
    let tree3 = vec!["root", "child1", ""];
    println!("{}", analyze_tree(&tree1));
    println!("{}", analyze_tree(&tree2));
    println!("{}", analyze_tree(&tree3));
}