fn ledger_consensus(mut a: f64, mut b: f64, precision: f64) -> f64 {
    while (a - b).abs() > precision {
        a = (a + b) / 2.0;
        b = (a + b) / 2.0;
    }
    a
}

fn main() {
    let x = 1.0;
    let y = 2.0;
    let p = 0.0001;
    let result = ledger_consensus(x, y, p);
    println!("{}", result);
}