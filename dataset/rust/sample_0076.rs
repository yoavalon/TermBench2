fn boundary_conditions(data: Vec<f64>, threshold: f64) -> Vec<usize> {
    let mut result = Vec::new();
    for (i, &value) in data.iter().enumerate() {
        if value.abs() > threshold {
            result.push(i);
        }
        if result.len() == 3 {
            break;
        }
    }
    result
}

fn main() {
    let data = vec![0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9];
    let threshold = 0.5;
    println!("{:?}", boundary_conditions(data, threshold));
}