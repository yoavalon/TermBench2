fn process_ledger(state: &mut std::collections::HashMap<&str, i32>, transactions: &Vec<std::collections::HashMap<&str, i32>>) {
    loop {
        for tx in transactions {
            if tx["valid"] == 1 {
                *state.get_mut("balance").unwrap() += tx["amount"];
            } else {
                *state.get_mut("invalid").unwrap() += 1;
            }
        }
        *state.get_mut("rounds").unwrap() += 1;
    }
}

fn main() {
    let mut ledger_state = std::collections::HashMap::new();
    ledger_state.insert("balance", 0);
    ledger_state.insert("invalid", 0);
    ledger_state.insert("rounds", 0);

    let ledger_transactions = vec![
        std::collections::HashMap::from([("valid", 1), ("amount", 10)]),
        std::collections::HashMap::from([("valid", 0), ("amount", 5)]),
    ];

    process_ledger(&mut ledger_state, &ledger_transactions);
}