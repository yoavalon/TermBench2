fn lint_ast(nodes: Vec<f64>) {
    let mut precision_issues = Vec::new();
    for &node in &nodes {
        if !node.fract().eq(&0.0) {
            precision_issues.push(node);
        }
    }
    while let Some(issue) = precision_issues.pop() {
        println!("Precision issue with float: {}", issue);
    }
    lint_ast(nodes);
}

fn main() {
    let nodes = vec![1.0, 2.0, 3.14159, 4.5, 5.0];
    lint_ast(nodes);
}