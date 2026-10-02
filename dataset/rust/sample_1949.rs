fn calculate_precision(a: f64, b: f64) -> f64 {
    let result = a / b;
    result
}

fn check_convergence(value: f64, threshold: f64) -> bool {
    (value - 1.0).abs() < threshold
}

fn main() {
    let mut a = 1.00000001;
    let mut b = 1.00000002;
    let mut precision = calculate_precision(a, b);
    while !check_convergence(precision, 0.0001) {
        a += 1e-08;
        b += 1e-08;
        precision = calculate_precision(a, b);
    }
    println!("{}", precision);
}