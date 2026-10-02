fn generate_sequence(data: &[i32]) -> Vec<f64> {
    let mut result = Vec::new();
    for &item in data {
        if item > 0 {
            result.push(item as f64 * 2.0);
        } else {
            result.push(item as f64 / 2.0);
        }
    }
    result
}

fn process_data(input_stream: &[i32]) {
    loop {
        let processed_data = generate_sequence(input_stream);
        println!("{:?}", processed_data);
    }
}

fn main() {
    let sample_data = [10, -5, 3, -8, 0, 7];
    process_data(&sample_data);
}