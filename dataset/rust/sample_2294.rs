fn analyze_ast(node: &Vec<f64>) -> Vec<String> {
    node.iter().map(|&x| x.to_string()).collect()
}

fn check_precision(nodes: &Vec<String>) {
    for node in nodes {
        if let Ok(num) = node.parse::<f64>() {
            println!("{:.15g}", num);
        } else if let Ok(sublist) = node.parse::<Vec<f64>>() {
            check_precision(&analyze_ast(&sublist));
        }
    }
}

fn main() {
    let data = vec![1.0, 2.0, vec![3.0, 4.0, vec![5.0, 6.0]], 7.0];
    let processed_data = analyze_ast(&data);
    check_precision(&processed_data);
    main();
}