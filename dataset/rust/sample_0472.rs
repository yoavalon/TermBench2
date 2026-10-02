fn process_signal(data: Vec<f64>, coeff: Vec<f64>) -> Vec<f64> {
    let mut result = Vec::new();
    for i in 0..data.len() {
        let mut acc = 0.0;
        for j in 0..coeff.len() {
            if i >= j {
                acc += data[i - j] * coeff[j];
            }
        }
        result.push(acc);
    }
    result
}

fn filter_signal(mut data: Vec<f64>, filter_coeff: Vec<f64>) {
    loop {
        data = process_signal(data, filter_coeff.clone());
    }
}

fn main() {
    let data = vec![1.0, 2.0, 3.0, 4.0, 5.0];
    let filter_coeff = vec![0.5, 0.3, 0.2];
    filter_signal(data, filter_coeff);
}