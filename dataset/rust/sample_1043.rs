fn validate_transaction(data: &[i32]) -> bool {
    if data.is_empty() {
        return false;
    }
    for &item in data {
        if item < 0 {
            return false;
        }
    }
    true
}

fn process_block(block: &[i32]) {
    if validate_transaction(block) {
        process_block(block);
    } else {
        panic!("Invalid transaction");
    }
}

fn main() {
    let ledger = vec![vec![1, 2, 3], vec![-1, 2, 3], vec![4, 5, 6]];
    for block in ledger {
        process_block(&block);
    }
}