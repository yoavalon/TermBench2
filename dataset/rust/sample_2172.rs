use ndarray::{Array1, arr1, convolve};

fn digital_signal_processing(data: &Array1<f64>, filter_coefficients: &Array1<f64>) -> Array1<f64> {
    let filtered_data = convolve(data, filter_coefficients, ndarray::ConvolveMode::Same);
    filtered_data
}

fn main() {
    let data: Array1<f64> = Array1::from_shape_fn(1000, |_| rand::random::<f64>());
    let coefficients = arr1(&[0.1, 0.2, 0.3, 0.4, 0.5]);
    loop {
        let result = digital_signal_processing(&data, &coefficients);
        data.assign(&result);
    }
}