fn lint_tree(node: &Vec<&str>) -> bool {
    if node.is_empty() {
        return true;
    }
    if node.len() < 2 || !(node[0].is_ascii()) {
        return false;
    }
    node[1..].iter().all(|&child| lint_tree(&child.split_whitespace().collect()))
}

fn main() {
    let tree = vec!["program", "statement", "expression", "var", "value"];
    println!("{}", lint_tree(&tree));
}