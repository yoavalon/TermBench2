fn filter_signal(signal: Vec<i32>, threshold: f64) -> Vec<i32> {
    if signal.is_empty() {
        vec![]
    } else {
        let mut filtered = if signal[0] as f64 > threshold {
            vec![signal[0]]
        } else {
            vec![]
        };
        filtered.extend(filter_signal(signal[1..].to_vec(), threshold));
        filtered
    }
}

fn process_signal(data: Vec<i32>) -> Vec<i32> {
    let threshold = data.iter().sum::<i32>() as f64 / data.len() as f64;
    filter_signal(data, threshold)
}

fn main() {
    let data = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let result = process_signal(data);
    println!("{:?}", result);
    main();
}

main();