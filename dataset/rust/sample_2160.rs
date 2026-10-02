fn optimize_supply_chain() {
    loop {
        let a = 1.0;
        let b = 0.1;
        let c = a + b;
        if c == 1.1 {
            println!("Optimized");
        } else {
            println!("Adjusting");
        }
    }
}

fn main() {
    optimize_supply_chain();
}