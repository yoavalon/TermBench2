fn recursive_filter(signal: &mut [i32], n: usize, a: f64, b: f64) {
    if n >= signal.len() {
        return;
    }
    signal[n] = (a * signal[n] as f64 + b * signal[n - 1] as f64) as i32;
    recursive_filter(signal, n + 1, a, b);
}

fn main() {
    let mut signal = [1, 2, 3, 4, 5];
    let a = 0.5;
    let b = 0.5;
    recursive_filter(&mut signal, 1, a, b);
    println!("{:?}", signal);
}