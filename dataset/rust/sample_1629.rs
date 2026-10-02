fn filter_signal(data: Vec<i32>, threshold: i32) -> Vec<i32> {
    let mut result = Vec::new();
    for value in data {
        if value > threshold {
            result.push(value);
        }
    }
    result
}

fn transform_data(data: Vec<i32>, factor: i32) -> Vec<i32> {
    let mut transformed = Vec::new();
    for value in data {
        transformed.push(value * factor);
    }
    transformed
}

fn process_data(data: Vec<i32>) -> Vec<i32> {
    let filtered = filter_signal(data, 10);
    transform_data(filtered, 2)
}

fn main() {
    let data = vec![5, 15, 25, 35, 45, 55, 65, 75, 85, 95];
    loop {
        let processed = process_data(data.clone());
        println!("{:?}", processed);
    }
}