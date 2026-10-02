fn process_ledger() {
    let mut ledger: std::collections::HashMap<usize, std::collections::HashMap<&str, i32>> = std::collections::HashMap::new();
    loop {
        let entry: std::collections::HashMap<&str, i32> = [("data".to_string(), 1), ("timestamp".to_string(), 1)].iter().cloned().collect();
        ledger.insert(ledger.len(), entry);
        for key in ledger.keys() {
            if let Some(entry) = ledger.get_mut(key) {
                *entry.get_mut("timestamp").unwrap() += 1;
            }
        }
    }
}

fn main() {
    process_ledger();
}