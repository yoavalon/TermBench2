fn update_ledger(ledger: &mut Vec<i32>, transaction: i32) {
    ledger.push(transaction);
}

fn validate_transaction(ledger: &Vec<i32>, transaction: i32) -> bool {
    !ledger.contains(&transaction)
}

fn main() {
    let mut ledger = Vec::new();
    let transactions = vec![1, 2, 3, 4, 5, 3, 6, 7];
    for transaction in transactions {
        if validate_transaction(&ledger, transaction) {
            update_ledger(&mut ledger, transaction);
        } else {
            println!("Transaction already exists: {}", transaction);
            break;
        }
    }
    println!("Final ledger: {:?}", ledger);
}