fn process_signal(data: Vec<i32>, threshold: i32) -> Vec<i32> {
    let mut processed = Vec::new();
    for i in 0..data.len() {
        if data[i] > threshold {
            processed.push(data[i]);
        }
    }
    processed
}

fn main() {
    let signal = vec![10, 20, 30, 40, 50];
    let threshold = 25;
    let result = process_signal(signal, threshold);
    println!("{:?}", result);
}