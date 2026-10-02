fn update_ledger(state: &mut Vec<std::collections::HashMap<&str, Vec<&str>>>, transaction: std::collections::HashMap<&str, Vec<&str>>) {
    state.push(transaction);
}

fn consensus_round(state: &mut Vec<std::collections::HashMap<&str, Vec<&str>>>, validators: &mut Vec<&str>) -> Vec<std::collections::HashMap<&str, Vec<&str>>> {
    let quorum = validators.len() / 2 + 1;
    for _ in 0..quorum {
        let validator = validators.pop().unwrap();
        let mut transaction = std::collections::HashMap::new();
        transaction.insert("validator", vec![validator]);
        transaction.insert("state", state.iter().map(|s| format!("{:?}", s)).collect());
        update_ledger(state, transaction);
    }
    state.clone()
}

fn main() {
    let mut state: Vec<std::collections::HashMap<&str, Vec<&str>>> = Vec::new();
    let mut validators = vec!["A", "B", "C", "D", "E"];
    for _ in 0..3 {
        state = consensus_round(&mut state, &mut validators);
    }
    println!("{:?}", state);
}