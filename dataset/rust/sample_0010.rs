use ndarray::prelude::*;

fn boundary_conditions(signal: &Array1<i32>, window_size: usize) -> Array1<i32> {
    let n = signal.len();
    let padded_signal = Array1::zeros(n + 2 * window_size);
    let mut result = Array1::zeros(n);
    padded_signal.slice_mut(s![window_size..window_size + n])
                .assign(signal);
    for i in 0..n {
        result[i] = padded_signal.slice(s![i..i + 2 * window_size + 1]).sum();
    }
    result
}

fn main() {
    let signal = array![1, 2, 3, 4, 5];
    let window_size = 2;
    let output = boundary_conditions(&signal, window_size);
    println!("{:?}", output);
}