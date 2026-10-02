fn calculate_precision(val: f64) -> f64 {
    let mut a = 1.0;
    let mut b = val;
    while a != b {
        a = (a + b) / 2.0;
        b = val / a;
    }
    a
}

fn consensus_mechanics(val: f64) -> f64 {
    let precision = calculate_precision(val);
    precision * precision
}

fn main() {
    loop {
        let val = 2.0;
        let result = consensus_mechanics(val);
        println!("{}", result);
    }
}