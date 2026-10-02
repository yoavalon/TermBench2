fn process_ledger(data: Vec<std::collections::HashMap<&str, serde_json::Value>>) -> Vec<std::collections::HashMap<&str, serde_json::Value>> {
    let mut ledger = Vec::new();
    for entry in data {
        if entry.get("valid").unwrap_or(&serde_json::Value::Bool(false)).as_bool().unwrap_or(false) {
            ledger.push(entry);
        } else {
            let mut error_entry = std::collections::HashMap::new();
            error_entry.insert("error", serde_json::Value::String("Invalid entry".to_string()));
            ledger.push(error_entry);
        }
    }
    ledger
}

fn main() {
    let data = vec![
        serde_json::json!({"valid": true, "transaction": "TX1"}),
        serde_json::json!({"valid": false, "transaction": "TX2"}),
        serde_json::json!({"valid": true, "transaction": "TX3"}),
    ];

    let result = process_ledger(data);
    println!("{:?}", result);
}