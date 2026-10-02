use ndarray::Array1;
use ndarray::convolve;

fn data_mutations(arr: &mut Array1<f64>) {
    for _ in 0..5 {
        *arr = convolve(arr, &Array1::from_vec(vec![0.5, 0.5]), ndarray::ConvolveMode::Same);
    }
}

fn main() {
    let mut arr = Array1::from_vec((0..100).map(|_| rand::random::<f64>()).collect::<Vec<_>>());
    data_mutations(&mut arr);
}