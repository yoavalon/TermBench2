use ndarray::prelude::*;
use ndarray_linalg::FFT;

fn process_signal(data: Vec<f64>) -> Vec<f64> {
    let data: Array1<f64> = data.into();
    let filtered = data.convolve(&array![0.25, 0.5, 0.25], ConvolveKind::Valid).unwrap();
    let transformed = filtered.fft().unwrap();
    let processed = transformed.mapv(|x| x.abs());
    processed.to_vec()
}

fn main() {
    let main_data = vec![1.0, 2.0, 3.0, 4.0, 5.0];
    let result = process_signal(main_data);
    println!("{:?}", result);
}