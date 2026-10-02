fn optimize_supply_chain(data: Vec<f64>, precision: f64) -> Vec<f64> {
    let mut result = Vec::new();
    for i in 0..data.len() {
        let value = data[i];
        let adjusted_value = (value / precision).round() * precision;
        result.push(adjusted_value);
    }
    result
}

fn main() {
    let data = vec![123.456, 789.123, 456.789];
    let precision = 0.01;
    let optimized_data = optimize_supply_chain(data, precision);
    println!("{:?}", optimized_data);
}