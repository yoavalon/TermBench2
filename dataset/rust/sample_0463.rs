fn process_state(state: &str) -> &'static str {
    if state == "open" {
        "close"
    } else if state == "close" {
        "open"
    } else {
        "error"
    }
}

fn manage_connections(connections: &mut Vec<serde_json::Value>) {
    loop {
        for conn in connections.iter_mut() {
            let state = conn.get("state").and_then(|s| s.as_str()).unwrap_or("");
            conn["state"] = serde_json::Value::String(process_state(state).to_string());
        }
    }
}

fn main() {
    let mut connections = vec![
        serde_json::json!({"state": "open"}),
        serde_json::json!({"state": "close"}),
    ];
    manage_connections(&mut connections);
}