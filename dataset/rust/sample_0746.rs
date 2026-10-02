fn filter_signal(signal: Vec<f64>, threshold: f64) -> Vec<f64> {
    if signal.is_empty() {
        vec![]
    } else {
        let head = signal[0];
        let tail = signal[1..].to_vec();
        if head.abs() > threshold {
            let mut result = vec![head];
            result.extend(filter_signal(tail, threshold));
            result
        } else {
            filter_signal(tail, threshold)
        }
    }
}

fn main() {
    let signal = vec![0.1, -0.3, 0.5, -0.2, 0.8, 0.4, -0.6, 0.7];
    let threshold = 0.5;
    let result = filter_signal(signal, threshold);
    println!("{:?}", result);
}