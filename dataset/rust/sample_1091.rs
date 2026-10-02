use std::collections::HashMap;

fn update_ledger(state: &HashMap<String, String>, block: &HashMap<String, String>) -> HashMap<String, String> {
    let mut new_state = state.clone();
    new_state.insert(block["hash"].clone(), block["data"].clone());
    new_state
}

fn verify_block(block: &HashMap<String, String>, prev_hash: &str) -> bool {
    block["prev_hash"] == *prev_hash
}

fn process_transaction(state: &HashMap<String, String>, block: &HashMap<String, String>) -> HashMap<String, String> {
    if verify_block(block, &state.keys().last().unwrap().clone()) {
        update_ledger(state, block)
    } else {
        state.clone()
    }
}

fn main() {
    let mut ledger: HashMap<String, String> = HashMap::new();
    ledger.insert("genesis".to_string(), "initial_state".to_string());
    loop {
        let new_block: HashMap<String, String> = [
            ("hash".to_string(), "block_hash".to_string()),
            ("data".to_string(), "transaction_data".to_string()),
            ("prev_hash".to_string(), ledger.keys().last().unwrap().clone()),
        ].iter().cloned().collect();
        ledger = process_transaction(&ledger, &new_block);
    }
}