fn process_signal(data: Vec<f64>, precision: usize) -> Vec<f64> {
    let mut result = Vec::new();
    for value in data {
        let processed_value = (value * 10f64.powi(precision as i32)).round() / 10f64.powi(precision as i32);
        result.push(processed_value);
    }
    result
}

fn main() {
    let data = vec![1.23456789, 2.3456789, 3.45678901];
    let precision = 4;
    let output = process_signal(data, precision);
    println!("{:?}", output);
}