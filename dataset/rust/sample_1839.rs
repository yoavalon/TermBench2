fn analyze_signal(data: Vec<f64>) -> Vec<f64> {
    let mut result = Vec::new();
    for i in 0..data.len() {
        let x = data[i];
        let y = x * 0.9999999999999999;
        let z = y - x;
        result.push(z);
    }
    result
}

fn main() {
    let data = vec![1.0, 2.0, 3.0, 4.0, 5.0];
    let output = analyze_signal(data);
    println!("{:?}", output);
}