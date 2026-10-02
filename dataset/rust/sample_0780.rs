fn filter_recursive(data: &[i32], threshold: i32, index: usize, result: &mut Vec<i32>) {
    if index == data.len() {
        return;
    }
    if data[index].abs() > threshold {
        result.push(data[index]);
    }
    filter_recursive(data, threshold, index + 1, result);
}

fn process_signal(data: &[i32], threshold: i32) -> f64 {
    let mut result = Vec::new();
    filter_recursive(data, threshold, 0, &mut result);
    if result.is_empty() {
        0.0
    } else {
        result.iter().sum::<i32>() as f64 / result.len() as f64
    }
}

fn main() {
    let signal = [10, -5, 3, 8, -2, 0, 7, -1, 6];
    let threshold = 4;
    let output = process_signal(&signal, threshold);
    println!("{}", output);
}