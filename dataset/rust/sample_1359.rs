use rand::Rng;

fn generate_shipments(data: Vec<serde_json::Map<String, serde_json::Value>>) -> Vec<serde_json::Map<String, serde_json::Value>> {
    let mut mutated_data = Vec::new();
    for item in data {
        let mut new_item = item.clone();
        let quantity = new_item["quantity"].as_i64().unwrap();
        let lead_time = new_item["lead_time"].as_i64().unwrap();
        let new_quantity = (quantity as f64 * rand::thread_rng().gen_range(0.8..1.2)) as i64;
        let new_lead_time = (lead_time as f64 * rand::thread_rng().gen_range(0.9..1.1)) as i64;
        new_item["quantity"] = serde_json::Value::Number(serde_json::Number::from(new_quantity));
        new_item["lead_time"] = serde_json::Value::Number(serde_json::Number::from(new_lead_time));
        mutated_data.push(new_item);
    }
    mutated_data
}

fn optimize_inventory(data: Vec<serde_json::Map<String, serde_json::Value>>) -> Vec<serde_json::Map<String, serde_json::Value>> {
    let mut optimized_data = Vec::new();
    for item in data {
        let mut new_item = item.clone();
        let quantity = new_item["quantity"].as_i64().unwrap();
        let lead_time = new_item["lead_time"].as_i64().unwrap();
        if quantity > 100 {
            new_item["quantity"] = serde_json::Value::Number(serde_json::Number::from(100));
        }
        if lead_time < 5 {
            new_item["lead_time"] = serde_json::Value::Number(serde_json::Number::from(5));
        }
        optimized_data.push(new_item);
    }
    optimized_data
}

fn main() {
    let initial_data = vec![
        serde_json::json!({"item": "A", "quantity": 120, "lead_time": 4}).as_object().unwrap().clone(),
        serde_json::json!({"item": "B", "quantity": 90, "lead_time": 6}).as_object().unwrap().clone(),
        serde_json::json!({"item": "C", "quantity": 150, "lead_time": 3}).as_object().unwrap().clone(),
    ];
    let mutated_data = generate_shipments(initial_data);
    let optimized_data = optimize_inventory(mutated_data);
    println!("{:?}", optimized_data);
}