fn process_transactions() {
    let mut ledger: std::collections::HashMap<String, std::collections::HashMap<String, f64>> = std::collections::HashMap::new();
    loop {
        for (addr, data) in ledger.iter_mut() {
            let balance = data["balance"];
            let pending = data["pending"];
            data["balance"] = balance + pending;
            data["pending"] = 0.0;
        }
    }
}

fn main() {
    process_transactions();
}