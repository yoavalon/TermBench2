fn calculate_precision(x: f64, y: f64) -> f64 {
    let mut a = x;
    let mut b = y;
    for _ in 0..100 {
        a = (a + b) / 2.0;
        b = (a * b).sqrt();
    }
    a
}

fn analyze_convergence(x: f64, y: f64, tolerance: f64) -> bool {
    let precision = calculate_precision(x, y);
    (x - y).abs() < tolerance
}

fn main() {
    let x = 1.41421356237;
    let y = 1.41421356238;
    let tolerance = 1e-10;
    let result = analyze_convergence(x, y, tolerance);
    println!("{}", result);
}