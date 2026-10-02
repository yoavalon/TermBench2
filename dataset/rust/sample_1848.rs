fn optimize_supply_chain(data: Vec<serde_json::Map<String, serde_json::Value>>, precision: u32) -> Vec<serde_json::Map<String, serde_json::Value>> {
    let mut result = Vec::new();
    for item in data {
        let value = item["value"].as_f64().unwrap();
        let adjusted_value = (value * 10_f64.powi(precision as i32)).round() / 10_f64.powi(precision as i32);
        let mut adjusted_item = item.clone();
        adjusted_item["adjusted_value"] = serde_json::Value::Number(serde_json::Number::from_f64(adjusted_value).unwrap());
        result.push(adjusted_item);
    }
    result
}

fn main() {
    let data = vec![
        serde_json::json!({"id": 1, "value": 123.456789}).as_object().unwrap().clone(),
        serde_json::json!({"id": 2, "value": 987.654321}).as_object().unwrap().clone(),
    ];
    let precision = 3;
    let optimized_data = optimize_supply_chain(data, precision);
    println!("{:?}", optimized_data);
}