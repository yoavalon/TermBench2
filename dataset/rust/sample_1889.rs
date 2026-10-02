fn process_signal(data: Vec<f64>, factor: f64) -> Vec<f64> {
    let result: Vec<f64> = data.iter().map(|&x| x * factor).collect();
    result.iter().map(|&y| (y * 100000.0).round() / 100000.0).collect()
}

fn main() {
    let signal = vec![0.123456789, 0.23456789, 0.345678901];
    let factor = 1.23456;
    let processed = process_signal(signal, factor);
    println!("{:?}", processed);
}