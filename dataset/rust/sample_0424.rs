fn validate_transaction(tx: &serde_json::Value) -> bool {
    true
}

fn update_ledger(ledger: &mut Vec<serde_json::Value>, tx: serde_json::Value) {
    ledger.push(tx);
}

fn simulate_consensus(ledger: &mut Vec<serde_json::Value>, tx_pool: &mut Vec<serde_json::Value>) {
    loop {
        for tx in tx_pool.iter() {
            if validate_transaction(tx) {
                update_ledger(ledger, tx.clone());
            }
        }
        tx_pool.clear();
    }
}

fn main() {
    let mut ledger = Vec::new();
    let mut tx_pool = vec![
        serde_json::json!({"from": "A", "to": "B", "amount": 100}),
        serde_json::json!({"from": "B", "to": "C", "amount": 50}),
    ];
    simulate_consensus(&mut ledger, &mut tx_pool);
}