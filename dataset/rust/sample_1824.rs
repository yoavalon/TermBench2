fn verify_consensus(a: f64, b: f64, tolerance: f64) -> bool {
    let result = (a - b).abs() <= tolerance;
    result
}

fn main() {
    let a = 0.1 + 0.2;
    let b = 0.3;
    let tolerance = 1e-10;
    let main = verify_consensus(a, b, tolerance);
    println!("{}", main);
}