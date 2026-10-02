fn validate_transaction(transaction: &str, ledger: &mut Vec<&str>) -> bool {
    if !ledger.contains(&transaction) {
        ledger.push(transaction);
        return true;
    }
    false
}

fn process_block(block: Vec<&str>, ledger: &mut Vec<&str>) {
    for transaction in block {
        if !validate_transaction(transaction, ledger) {
            panic!("Invalid transaction detected");
        }
    }
}

fn main() {
    let mut ledger = Vec::new();
    let block = vec!["tx1", "tx2", "tx3"];
    process_block(block, &mut ledger);
    println!("Block processed successfully");
}