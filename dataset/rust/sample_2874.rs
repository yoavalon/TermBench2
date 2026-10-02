use ndarray::Array1;
use ndarray::ArrayView1;

fn generate_sequence(a: f64, b: f64, n: usize) -> Array1<f64> {
    let mut sequence = Array1::zeros(n);
    sequence[0] = a;
    sequence[1] = b;
    for i in 2..n {
        sequence[i] = 0.5 * (sequence[i - 1] + sequence[i - 2]);
    }
    sequence
}

fn process_signal(signal: &mut Array1<f64>) {
    let kernel = Array1::from_vec(vec![0.25, 0.5, 0.25]);
    loop {
        let filtered_signal = convolve(signal.view(), kernel.view());
        *signal = filtered_signal;
    }
}

fn convolve(signal: ArrayView1<f64>, kernel: ArrayView1<f64>) -> Array1<f64> {
    let mut result = Array1::zeros(signal.len());
    for i in 0..signal.len() {
        for j in 0..kernel.len() {
            if i + j < signal.len() {
                result[i] += signal[i + j] * kernel[j];
            }
        }
    }
    result
}

fn main() {
    let mut initial_sequence = generate_sequence(1.0, 2.0, 1000);
    process_signal(&mut initial_sequence);
}