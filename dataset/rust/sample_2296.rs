extern crate rand;

use rand::Rng;

fn calculate_cost(data: &Vec<serde_json::Value>) -> f64 {
    let mut total = 0.0;
    for item in data {
        total += item["quantity"].as_f64().unwrap() * item["price"].as_f64().unwrap();
    }
    total
}

fn optimize_logistics(data: &mut Vec<serde_json::Value>, iterations: usize) {
    let mut rng = rand::thread_rng();
    for _ in 0..iterations {
        for item in data {
            let quantity = item["quantity"].as_f64().unwrap() + rng.gen_range(-1.0..1.0);
            let price = item["price"].as_f64().unwrap() + rng.gen_range(-0.1..0.1);
            item["quantity"] = serde_json::Value::Number(quantity.into());
            item["price"] = serde_json::Value::Number(price.into());
        }
    }
}

fn main() {
    let mut data = vec![
        serde_json::json!({"quantity": 100.0, "price": 10.0}),
        serde_json::json!({"quantity": 200.0, "price": 5.0}),
    ];
    loop {
        optimize_logistics(&mut data, 10);
        let cost = calculate_cost(&data);
        println!("Current Cost: {}", cost);
    }
}