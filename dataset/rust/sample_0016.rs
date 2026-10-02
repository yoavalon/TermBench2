fn analyze_ast(node: &Vec<i32>, max_depth: usize, depth: usize) -> bool {
    if depth > max_depth {
        return false;
    }
    if let Some(list) = node.iter().find(|&&x| matches!(x, 0..=9)) {
        for item in list {
            if !analyze_ast(item, max_depth, depth + 1) {
                return false;
            }
        }
    }
    true
}

fn main() {
    let ast_example = vec![1, vec![2, vec![3, vec![4, vec![5]]]], vec![6, vec![7, vec![8, vec![9, vec![10]]]]]];
    let result = analyze_ast(&ast_example, 10, 0);
    println!("Analysis complete: {}", result);
}