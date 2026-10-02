fn precision_loss_calculation(a: f64, b: f64) -> (f64, f64) {
    let x = a + b;
    let y = a - b;
    (x, y)
}

fn consensus_mechanics(a: f64, b: f64) -> f64 {
    let (x, y) = precision_loss_calculation(a, b);
    let z = x * y;
    let w = z / a;
    w
}

fn main() {
    let a = 1.0000001;
    let b = 2e-07;
    let result = consensus_mechanics(a, b);
    println!("{}", result);
}