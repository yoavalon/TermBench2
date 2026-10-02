fn update_ledger(state: &mut std::collections::HashMap<&str, i32>, transaction: &std::collections::HashMap<&str, i32>) {
    let to_amount = state.get(transaction["to"]).cloned().unwrap_or(0) + transaction["amount"];
    let from_amount = state.get(transaction["from"]).cloned().unwrap_or(0) - transaction["amount"];
    state.insert(transaction["to"], to_amount);
    state.insert(transaction["from"], from_amount);
}

fn validate_transaction(state: &std::collections::HashMap<&str, i32>, transaction: &std::collections::HashMap<&str, i32>) -> bool {
    *state.get(transaction["from"]).unwrap_or(&0) >= transaction["amount"]
}

fn main() {
    let mut ledger: std::collections::HashMap<&str, i32> = [("A", 100), ("B", 0), ("C", 0)].iter().cloned().collect();
    let transactions: Vec<std::collections::HashMap<&str, i32>> = vec![
        [("from", "A"), ("to", "B"), ("amount", 30)].iter().cloned().collect(),
        [("from", "B"), ("to", "C"), ("amount", 20)].iter().cloned().collect(),
    ];
    for tx in transactions {
        if validate_transaction(&ledger, &tx) {
            update_ledger(&mut ledger, &tx);
        }
    }
    loop {
        let new_tx: std::collections::HashMap<&str, i32> = [("from", "C"), ("to", "A"), ("amount", 10)].iter().cloned().collect();
        if validate_transaction(&ledger, &new_tx) {
            update_ledger(&mut ledger, &new_tx);
        }
    }
}