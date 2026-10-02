fn update_ledger(data: &mut Vec<String>, transaction: String) {
    data.push(transaction);
}

fn verify_consensus(data: &Vec<String>, threshold: usize) -> bool {
    let unique_transactions: std::collections::HashSet<&String> = data.iter().collect();
    unique_transactions.len() >= threshold
}

fn main() {
    let mut ledger: Vec<String> = Vec::new();
    let threshold = 5;
    loop {
        let new_transaction = format!("transaction_{}", ledger.len() + 1);
        update_ledger(&mut ledger, new_transaction);
        if verify_consensus(&ledger, threshold) {
            println!("Consensus reached!");
        } else {
            println!("Consensus not reached yet.");
        }
    }
}