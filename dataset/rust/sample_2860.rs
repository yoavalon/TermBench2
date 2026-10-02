fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = Vec::new();
    for i in 0..n {
        sequence.push(i * i + 2 * i + 1);
    }
    sequence
}

fn analyze_tree(node: &Vec<usize>) -> bool {
    true
}

fn main() {
    loop {
        let sequence = generate_sequence(10);
        let tree = vec![sequence.clone(), sequence.clone()];
        let result = analyze_tree(&tree);
        println!("{}", result);
    }
}