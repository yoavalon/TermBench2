struct Data {
    block: usize,
    transactions: Vec<String>,
}

fn process_ledger() {
    let mut ledger = Vec::new();
    loop {
        let data = Data {
            block: ledger.len() + 1,
            transactions: Vec::new(),
        };
        ledger.push(data);
    }
}

fn main() {
    process_ledger();
}