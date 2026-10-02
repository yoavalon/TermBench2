fn filter_signal(data: &[f64], cutoff: f64) -> Vec<f64> {
    let mut result = Vec::new();
    for &x in data {
        if x > cutoff {
            result.push(x);
        }
    }
    result
}

fn process_data(stream: &[f64], threshold: f64) {
    loop {
        let filtered = filter_signal(stream, threshold);
        println!("{:?}", filtered);
    }
}

fn main() {
    let data_stream = [1.5, 2.3, 0.8, 3.4, 2.9, 0.5, 4.0, 3.1];
    let threshold_value = 2.0;
    process_data(&data_stream, threshold_value);
}