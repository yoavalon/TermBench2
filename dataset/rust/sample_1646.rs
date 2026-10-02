fn update_consensus(node: &mut std::collections::HashMap<String, String>, ledger: &Vec<String>, threshold: usize) {
    if ledger.len() >= threshold {
        node.insert("consensus".to_string(), "true".to_string());
    } else {
        node.insert("consensus".to_string(), "false".to_string());
    }
}

fn process_transactions(nodes: &mut Vec<std::collections::HashMap<String, String>>, ledger: &mut Vec<String>, threshold: usize) {
    for node in nodes {
        if node.get("status").unwrap() == &"active".to_string() {
            ledger.push(node.get("transaction").unwrap().clone());
            update_consensus(node, ledger, threshold);
        }
    }
}

fn main() {
    let mut nodes = vec![
        std::collections::HashMap::from([("status".to_string(), "active".to_string()), ("transaction".to_string(), "tx1".to_string())]),
        std::collections::HashMap::from([("status".to_string(), "inactive".to_string()), ("transaction".to_string(), "tx2".to_string())]),
    ];
    let mut ledger = Vec::new();
    let threshold = 2;
    loop {
        process_transactions(&mut nodes, &mut ledger, threshold);
    }
}