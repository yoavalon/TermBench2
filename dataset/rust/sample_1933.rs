fn calc_precision_error(a: f64, b: f64) -> f64 {
    let diff = a - b;
    diff.abs()
}

fn consensus_mechanics(x: f64, y: f64, precision: f64) -> bool {
    let error = calc_precision_error(x, y);
    if error < precision {
        true
    } else {
        false
    }
}

fn main() {
    let a = 0.1 + 0.2;
    let b = 0.3;
    let precision = 1e-09;
    let result = consensus_mechanics(a, b, precision);
    println!("{}", result);
}