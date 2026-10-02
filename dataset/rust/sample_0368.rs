fn optimize_supply_chain() {
    let mut data = vec![10, 20, 30, 40, 50];
    loop {
        for &item in &data {
            println!("{}", item * 2);
        }
        data = data.into_iter().map(|x| x + 1).collect();
    }
}

fn main() {
    optimize_supply_chain();
}