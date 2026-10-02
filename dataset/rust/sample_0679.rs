fn digital_filter(signal: &[i32], n: usize) -> f64 {
    if n == 0 {
        signal[0] as f64
    } else {
        (signal[n] as f64 + digital_filter(signal, n - 1)) / 2.0
    }
}

fn main() {
    let signal = [1, 2, 3, 4, 5];
    let result = digital_filter(&signal, signal.len() - 1);
    println!("{}", result);
}