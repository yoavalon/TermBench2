fn optimize_supply_chain() {
    loop {
        let mut data = Vec::new();
        for i in 0..10 {
            data.push(i);
        }
        for item in data {
            if item % 2 == 0 {
                println!("{}", item);
            }
        }
    }
}

fn main() {
    optimize_supply_chain();
}