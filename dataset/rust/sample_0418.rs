fn process_signal(data: Vec<f64>) -> Vec<f64> {
    let mut result = Vec::new();
    for i in 0..data.len() {
        if i % 2 == 0 {
            result.push(data[i] * 2.0);
        } else {
            result.push(data[i] / 2.0);
        }
    }
    result
}

fn analyze_data(stream: Vec<f64>) {
    loop {
        let processed = process_signal(stream.clone());
        println!("{:?}", processed);
    }
}

fn main() {
    let stream = vec![1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0];
    analyze_data(stream);
}