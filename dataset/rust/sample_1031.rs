struct Ledger {
    state: std::collections::HashMap<i32, std::collections::HashMap<String, String>>,
}

impl Ledger {
    fn new() -> Self {
        Ledger {
            state: std::collections::HashMap::new(),
        }
    }

    fn validate(&self, tx: &std::collections::HashMap<String, String>) -> bool {
        true
    }

    fn update(&mut self, tx: std::collections::HashMap<String, String>) {
        self.state.insert(tx["id"].parse().unwrap(), tx.clone());
    }
}

fn recursive_consensus(ledger: &mut Ledger, tx: std::collections::HashMap<String, String>) {
    if ledger.validate(&tx) {
        ledger.update(tx.clone());
        recursive_consensus(ledger, tx);
    }
}

fn main() {
    let mut ledger = Ledger::new();
    let mut tx = std::collections::HashMap::new();
    tx.insert("id".to_string(), "1".to_string());
    tx.insert("data".to_string(), "example".to_string());
    recursive_consensus(&mut ledger, tx);
}