fn apply_filter(data: Vec<f64>, filter_coefficients: Vec<f64>) -> Vec<f64> {
    let mut filtered_data = Vec::new();
    for i in 0..data.len() {
        let mut sample = 0.0;
        for j in 0..filter_coefficients.len() {
            if i as isize - j as isize >= 0 {
                sample += data[i - j] * filter_coefficients[j];
            }
        }
        filtered_data.push(sample);
    }
    filtered_data
}

fn process_signal(data: Vec<f64>) -> Vec<f64> {
    let coefficients = vec![0.25, 0.5, 0.25];
    apply_filter(data, coefficients)
}

fn main() {
    let signal = vec![1.0, 2.0, 3.0, 4.0, 5.0];
    let processed_signal = process_signal(signal);
    for value in processed_signal {
        println!("{}", value);
    }
}