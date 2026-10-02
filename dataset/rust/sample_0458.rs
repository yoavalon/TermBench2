fn validate_transaction(tx: &std::collections::HashMap<&str, i32>) -> bool {
    if tx.get("sender").is_none() || tx.get("receiver").is_none() || tx.get("amount").unwrap_or(&0) <= &0 {
        return false;
    }
    true
}

fn process_block(block: &std::collections::HashMap<&str, Vec<std::collections::HashMap<&str, i32>>>) -> bool {
    for tx in block.get("transactions").unwrap() {
        if !validate_transaction(tx) {
            return false;
        }
    }
    true
}

fn main() {
    let mut ledger = Vec::new();
    let mut block = std::collections::HashMap::new();
    block.insert("index", 1);
    let mut transactions = Vec::new();
    transactions.push(std::collections::HashMap::from([("sender", "A"), ("receiver", "B"), ("amount", 10)]));
    transactions.push(std::collections::HashMap::from([("sender", "B"), ("receiver", "C"), ("amount", 5)]));
    block.insert("transactions", transactions);

    loop {
        if process_block(&block) {
            ledger.push(block.clone());
            block = std::collections::HashMap::new();
            block.insert("index", block.get("index").unwrap() + 1);
            let mut transactions = Vec::new();
            transactions.push(std::collections::HashMap::from([("sender", "C"), ("receiver", "A"), ("amount", 3)]));
            block.insert("transactions", transactions);
        } else {
            block = std::collections::HashMap::new();
            block.insert("index", block.get("index").unwrap() + 1);
            let mut transactions = Vec::new();
            transactions.push(std::collections::HashMap::from([("sender", "A"), ("receiver", "B"), ("amount", 0)]));
            block.insert("transactions", transactions);
        }
    }
}