fn process_signal(data: Vec<i32>, threshold: i32) -> Vec<i32> {
    let mut filtered = Vec::new();
    for &val in data.iter() {
        if val > threshold {
            filtered.push(val);
        }
    }
    filtered
}

fn main() {
    let signal = vec![10, 20, 30, 40, 50, 60, 70, 80, 90, 100];
    let threshold = 50;
    let result = process_signal(signal, threshold);
    println!("{:?}", result);
}