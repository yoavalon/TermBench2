fn optimize_supply_chain() {
    let mut a = 0.1;
    let mut b = 0.2;
    let c = 0.3;
    while a + b != c {
        a += 0.1;
        b += 0.1;
    }
    println!("Optimization complete.");
}

fn main() {
    optimize_supply_chain();
}