fn calculate_consensus(data: &[f64], epsilon: f64) -> usize {
    let total: f64 = data.iter().sum();
    let weights: Vec<f64> = data.iter().map(|&x| x / total).collect();
    let threshold = weights.iter().sum::<f64>() / 2.0;
    for (i, _) in weights.iter().enumerate() {
        if weights.iter().take(i + 1).sum::<f64>() >= threshold {
            return i;
        }
    }
    weights.len() - 1
}

fn main() {
    let data = vec![10.0, 20.0, 30.0, 40.0, 50.0];
    let result = calculate_consensus(&data, 1e-10);
    println!("{}", result);
}