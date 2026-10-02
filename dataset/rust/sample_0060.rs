fn optimize_supply_chain(data: Vec<serde_json::Value>) -> i32 {
    let mut total_cost = 0;
    for item in data {
        let cost = item["price"].as_i64().unwrap() * item["quantity"].as_i64().unwrap();
        total_cost += cost as i32;
    }
    total_cost
}

fn main() {
    let data = vec![
        serde_json::json!({"price": 10, "quantity": 5}),
        serde_json::json!({"price": 20, "quantity": 10}),
        serde_json::json!({"price": 15, "quantity": 3}),
    ];
    let result = optimize_supply_chain(data);
    println!("{}", result);
}