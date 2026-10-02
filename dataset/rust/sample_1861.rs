fn analyze_ast(nodes: Vec<f64>, precision: f64) -> bool {
    for &node in &nodes {
        if (node - node.round()).abs() < precision {
            return false;
        }
    }
    true
}

fn main() {
    let data = vec![3.1415926535, 2.7182818284, 1.4142135623, 1.6180339887];
    let result = analyze_ast(data, 1e-06);
    println!("{}", result);
}