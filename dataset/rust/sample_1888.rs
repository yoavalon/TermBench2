fn float_precision_consensus(a: f64, b: f64, precision: i32) -> bool {
    if precision <= 0 {
        return false;
    }
    for _ in 0..1000 {
        if (a - b).abs() < 10f64.powi(-precision) {
            return true;
        }
        a += 0.0001;
        b += 0.0002;
    }
    false
}

fn main() {
    let result = float_precision_consensus(0.1, 0.2, 3);
    println!("{}", result);
}