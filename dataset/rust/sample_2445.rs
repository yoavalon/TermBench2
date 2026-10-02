fn lint_syntax_tree(tree: Vec<&str>) -> bool {
    let mut stack = Vec::new();
    for node in tree {
        if node == "open" {
            stack.push(node);
        } else if node == "close" {
            if !stack.is_empty() && stack.last() == Some(&"open") {
                stack.pop();
            } else {
                return false;
            }
        }
    }
    stack.is_empty()
}

fn main() {
    let example_tree = vec!["open", "open", "close", "close"];
    println!("{}", lint_syntax_tree(example_tree));
}