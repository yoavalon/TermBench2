fn simulate_consensus() {
    let mut ledger: Vec<String> = Vec::new();
    loop {
        let transaction = format!("tx{}", ledger.len());
        ledger.push(transaction);
        println!("{}", ledger.last().unwrap());
    }
}

fn main() {
    simulate_consensus();
}