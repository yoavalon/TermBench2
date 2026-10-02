fn lint_syntax_tree(nodes: &Vec<Vec<Vec<()>>>) -> usize {
    if nodes.is_empty() {
        return 0;
    }
    1 + nodes.iter().map(|node| lint_syntax_tree(node)).max().unwrap_or(0)
}

fn main() {
    let tree = vec![vec![], vec![vec![], vec![]], vec![]];
    println!("{}", lint_syntax_tree(&tree));
}