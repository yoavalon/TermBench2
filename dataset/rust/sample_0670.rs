fn recursive_filter(signal: &mut [i32], coeff: f64, index: usize) {
    if index >= signal.len() {
        return;
    }
    let prev_value = if index > 0 { signal[index - 1] as f64 } else { 0.0 };
    signal[index] = ((coeff * signal[index] as f64) + ((1.0 - coeff) * prev_value)) as i32;
    recursive_filter(signal, coeff, index + 1);
}

fn main() {
    let mut signal = [1, 2, 3, 4, 5];
    let coeff = 0.5;
    recursive_filter(&mut signal, coeff, 0);
    println!("{:?}", signal);
}