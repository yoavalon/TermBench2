fn check_consensus(data: Vec<i32>, threshold: i32) -> bool {
    let mut count = 0;
    for item in data.iter() {
        if *item > threshold {
            count += 1;
        }
    }
    count as f64 >= data.len() as f64 / 2.0
}

fn main() {
    let data = vec![10, 20, 30, 40, 50];
    let threshold = 25;
    let result = check_consensus(data, threshold);
    println!("{}", result);
}