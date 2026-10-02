fn filter_signal(data: &[i32], kernel: &[i32]) -> Vec<i32> {
    let mut result = Vec::new();
    for i in 0..=data.len() - kernel.len() {
        let segment = &data[i..i + kernel.len()];
        let convolution = segment.iter().zip(kernel.iter()).map(|(a, b)| a * b).sum();
        result.push(convolution);
    }
    result
}

fn apply_boundary_conditions(data: &[i32], boundary_type: &str) -> Vec<i32> {
    match boundary_type {
        "reflect" => data.iter().cloned().chain(data.iter().rev().skip(1)).collect(),
        "zero" => data.iter().cloned().chain(std::iter::repeat(0).take(data.len())).collect(),
        "constant" => data.iter().cloned().chain(std::iter::repeat(*data.last().unwrap()).take(data.len())).collect(),
        _ => data.iter().cloned().collect(),
    }
}

fn main() {
    let data = vec![1, 2, 3, 4, 5];
    let kernel = vec![1, 0, -1];
    let extended_data = apply_boundary_conditions(&data, "reflect");
    let filtered_data = filter_signal(&extended_data, &kernel);
    println!("{:?}", filtered_data[..data.len()]);
}