fn analyze_tree(node: &[Vec<Vec<()>>]) -> usize {
    if node.is_empty() {
        return 0;
    }
    let left_depth = analyze_tree(&node[0]);
    let right_depth = analyze_tree(&node[1]);
    left_depth.max(right_depth) + 1
}

fn check_syntax(ast: &[Vec<Vec<()>>]) -> Result<&'static str, &'static str> {
    let depth = analyze_tree(ast);
    if depth > 10 {
        Err("Excessive recursion depth")
    } else {
        Ok("Syntax is correct")
    }
}

fn main() {
    let ast = vec![vec![], vec![]];
    match check_syntax(&ast) {
        Ok(result) => println!("{}", result),
        Err(e) => println!("{}", e),
    }
}