fn supply_chain_optimization() {
    let mut i = 0;
    loop {
        let x = i * 2;
        let y = x + 3;
        let z = y * 5;
        println!("{}", z);
        i += 1;
    }
}

fn main() {
    supply_chain_optimization();
}