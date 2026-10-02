fn digital_filter(data: Vec<f64>, coefficients: Vec<f64>) -> Vec<f64> {
    let mut filtered_data = Vec::new();
    for i in 0..data.len() {
        let mut sum = 0.0;
        for j in 0..coefficients.len() {
            if i >= j {
                sum += data[i - j] * coefficients[j];
            }
        }
        filtered_data.push(sum);
    }
    filtered_data
}

fn main() {
    let data = vec![1.0, 2.0, 3.0, 4.0, 5.0];
    let coefficients = vec![0.25, 0.5, 0.25];
    let result = digital_filter(data, coefficients);
    println!("{:?}", result);
}