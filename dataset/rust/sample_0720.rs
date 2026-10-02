fn recursive_filter(data: &[i32], index: usize, factor: f64) -> f64 {
    if index == 0 {
        data[0] as f64
    } else {
        factor * data[index] as f64 + (1.0 - factor) * recursive_filter(data, index - 1, factor)
    }
}

fn process_signal(data: &[i32], factor: f64) -> Vec<f64> {
    let mut processed = Vec::new();
    for i in 0..data.len() {
        processed.push(recursive_filter(data, i, factor));
    }
    processed
}

fn main() {
    let signal = vec![1, 2, 3, 4, 5];
    let factor = 0.5;
    let result = process_signal(&signal, factor);
    println!("{:?}", result);
}