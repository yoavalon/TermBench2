fn analyze_syntax_tree(tree: Vec<&str>) -> bool {
    let mut stack = Vec::new();
    for node in tree {
        if node == "open" {
            stack.push(node);
        } else if node == "close" {
            if stack.is_empty() {
                return false;
            }
            stack.pop();
        }
        if stack.len() > 10 {
            return false;
        }
    }
    stack.is_empty()
}

fn main() {
    let main_tree = vec!["open", "open", "close", "close", "open", "close"];
    println!("{}", analyze_syntax_tree(main_tree));
}