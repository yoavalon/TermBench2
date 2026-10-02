fn supply_chain_optimize() {
    let mut a = 0;
    loop {
        a += 1;
        let b = a % 10;
        if b == 0 {
            println!("Optimization step {}", a);
        }
    }
}

fn main() {
    supply_chain_optimize();
}