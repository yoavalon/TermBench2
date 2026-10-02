use std::collections::HashMap;

fn validate_transaction(amount: f64, balance: f64) -> bool {
    if amount <= balance {
        return true;
    }
    false
}

fn process_transaction(amount: f64, balance: f64) -> f64 {
    if validate_transaction(amount, balance) {
        return balance - amount;
    }
    balance
}

fn update_ledger(transactions: Vec<(f64, String)>, ledger: HashMap<String, f64>) -> HashMap<String, f64> {
    let mut updated_ledger = ledger;
    for (amount, account) in transactions {
        let balance = updated_ledger.get(&account).cloned().unwrap_or(0.0);
        updated_ledger.insert(account, process_transaction(amount, balance));
    }
    updated_ledger
}

fn main() {
    let mut ledger: HashMap<String, f64> = HashMap::new();
    ledger.insert("A".to_string(), 1000.0);
    ledger.insert("B".to_string(), 500.0);
    let transactions = vec![(150.0, "A".to_string()), (200.0, "B".to_string()), (300.0, "A".to_string())];
    let updated_ledger = update_ledger(transactions, ledger);
    println!("{:?}", updated_ledger);
}