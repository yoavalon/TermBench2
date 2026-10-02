use std::collections::HashMap;

fn evaluate_supply_chain(data: &Vec<HashMap<String, i32>>, threshold: i32) -> i32 {
    let mut total_cost = 0;
    for item in data {
        if item["demand"] > threshold {
            total_cost += item["cost"];
        }
    }
    total_cost
}

fn optimize_inventory(data: &mut Vec<HashMap<String, i32>>, max_budget: i32) {
    for item in data {
        if item["cost"] > max_budget {
            item.insert("quantity".to_string(), 0);
        } else {
            item.insert("quantity".to_string(), max_budget / item["cost"]);
        }
    }
}

fn main() {
    let mut supply_data = vec![
        HashMap::from([("product".to_string(), 1), ("cost".to_string(), 10), ("demand".to_string(), 100), ("quantity".to_string(), 0)]),
        HashMap::from([("product".to_string(), 2), ("cost".to_string(), 20), ("demand".to_string(), 200), ("quantity".to_string(), 0)]),
        HashMap::from([("product".to_string(), 3), ("cost".to_string(), 15), ("demand".to_string(), 150), ("quantity".to_string(), 0)]),
    ];
    let budget = 500;
    let threshold = 150;
    optimize_inventory(&mut supply_data, budget);
    let total_cost = evaluate_supply_chain(&supply_data, threshold);
    println!("{}", total_cost);
}