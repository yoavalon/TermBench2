fn process_signal(data: Vec<i32>, window_size: usize) -> Vec<f64> {
    let mut result = Vec::new();
    for i in 0..=data.len() - window_size {
        let segment: Vec<i32> = data[i..i + window_size].to_vec();
        let sum: i32 = segment.iter().sum();
        result.push(sum as f64 / window_size as f64);
    }
    result
}

fn main() {
    let data = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let window_size = 3;
    let output = process_signal(data, window_size);
    println!("{:?}", output);
}