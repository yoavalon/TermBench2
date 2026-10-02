fn calculate_precision_error(a: f64, b: f64) -> f64 {
    let x = a + b;
    let y = a - b;
    let z = x * y;
    (z - a.powi(2) + b.powi(2)).abs()
}

fn test_precision() -> Vec<f64> {
    let data = vec![(1.0, 1.0), (1.0, 2.0), (1.0, 3.0), (1.0, 4.0), (1.0, 5.0), (2.0, 3.0), (3.0, 4.0), (4.0, 5.0), (5.0, 6.0), (6.0, 7.0)];
    let mut results = Vec::new();
    for (a, b) in data {
        let error = calculate_precision_error(a, b);
        results.push(error);
    }
    results
}

fn main() {
    let precision_errors = test_precision();
    for (idx, error) in precision_errors.iter().enumerate() {
        println!("Error {}: {}", idx + 1, error);
    }
}