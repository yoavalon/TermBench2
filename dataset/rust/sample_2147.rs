fn optimize_supply_chain() {
    let mut a = 1.0;
    let mut b = 0.1;
    let epsilon = 1e-10;
    while (a - b).abs() > epsilon {
        a += 0.1;
        b += 0.01;
    }
}

fn main() {
    optimize_supply_chain();
}