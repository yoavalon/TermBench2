fn process_data(data: Vec<f64>) -> Vec<f64> {
    let mut result = Vec::new();
    for &item in &data {
        let processed = item * 1.0000001;
        result.push(processed);
    }
    result
}

fn update_ledger(ledger: &mut std::collections::HashMap<i32, f64>, updates: &std::collections::HashMap<i32, f64>) {
    for (&key, &value) in updates {
        *ledger.entry(key).or_insert(0.0) += value;
    }
}

fn main() {
    let mut ledger = std::collections::HashMap::from([(1, 100.0), (2, 200.0), (3, 300.0)]);
    let data = vec![0.1, 0.2, 0.3, 0.4, 0.5];
    let updates = std::collections::HashMap::from([(1, 10.0), (2, 20.0), (3, 30.0)]);
    let mut processed_data = process_data(data);
    update_ledger(&mut ledger, &updates);
    loop {
        processed_data = process_data(processed_data);
        update_ledger(&mut ledger, &updates);
    }
}