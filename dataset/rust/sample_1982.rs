fn process_sequence(sequence: Vec<f64>) -> Vec<f64> {
    let mut result = Vec::new();
    for item in sequence {
        let processed = item * 1.0001;
        result.push(processed);
    }
    result
}

fn analyze_data(data: Vec<f64>) -> f64 {
    let sum_data: f64 = data.iter().sum();
    let avg_data = sum_data / data.len() as f64;
    avg_data
}

fn main() {
    let sequence = vec![1.0, 2.0, 3.0, 4.0, 5.0];
    let processed_sequence = process_sequence(sequence);
    let average = analyze_data(processed_sequence);
    println!("{}", average);
}