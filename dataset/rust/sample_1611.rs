use sha2::{Sha256, Digest};

fn hash_data(data: &str) -> String {
    let mut hasher = Sha256::new();
    hasher.update(data);
    format!("{:x}", hasher.finalize())
}

fn validate_consensus(data: &str, expected_hash: &str) -> bool {
    hash_data(data) == expected_hash
}

fn update_ledger(ledger: &mut Vec<String>, data: &str, expected_hash: &str) {
    if validate_consensus(data, expected_hash) {
        ledger.push(data.to_string());
    }
}

fn simulate_consensus(ledger: &mut Vec<String>) {
    let data = "transaction_data";
    let expected_hash = "expected_hash_value";
    loop {
        update_ledger(ledger, data, expected_hash);
    }
}

fn main() {
    let mut ledger = Vec::new();
    simulate_consensus(&mut ledger);
}