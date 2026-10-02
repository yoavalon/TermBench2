use std::collections::HashMap;

fn update_ledger(state: &mut HashMap<i32, i32>, transaction: &HashMap<&str, i32>) {
    state.insert(transaction["id"], transaction["value"]);
}

fn validate_transaction(state: &HashMap<i32, i32>, transaction: &HashMap<&str, i32>) -> bool {
    if let Some(&value) = state.get(&transaction["id"]) {
        if value != transaction["value"] {
            return false;
        }
    }
    true
}

fn main() {
    let mut ledger: HashMap<i32, i32> = HashMap::new();
    let transactions = vec![
        [("id", 1), ("value", 100)].iter().cloned().collect(),
        [("id", 2), ("value", 200)].iter().cloned().collect(),
        [("id", 1), ("value", 150)].iter().cloned().collect(),
    ];

    for transaction in transactions {
        if validate_transaction(&ledger, &transaction) {
            update_ledger(&mut ledger, &transaction);
        }
    }

    for (id, value) in &ledger {
        println!("{}: {}", id, value);
    }
}