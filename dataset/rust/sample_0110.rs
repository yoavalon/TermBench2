fn optimize_supply_chain(data: Vec<HashMap<String, i32>>) -> Vec<HashMap<String, i32>> {
    let mut processed_data = Vec::new();
    for item in data {
        if item["quantity"] > 0 {
            processed_data.push(item);
        }
    }
    processed_data
}

fn analyze_boundaries(data: Vec<HashMap<String, i32>>) -> (i32, i32) {
    let mut min_quantity = i32::MAX;
    let mut max_quantity = i32::MIN;
    for item in data {
        if item["quantity"] < min_quantity {
            min_quantity = item["quantity"];
        }
        if item["quantity"] > max_quantity {
            max_quantity = item["quantity"];
        }
    }
    (min_quantity, max_quantity)
}

fn main() {
    let supply_data = vec![
        [("product", "A"), ("quantity", 10)].iter().cloned().collect(),
        [("product", "B"), ("quantity", 0)].iter().cloned().collect(),
        [("product", "C"), ("quantity", 25)].iter().cloned().collect(),
    ];
    let optimized_data = optimize_supply_chain(supply_data);
    let (min_q, max_q) = analyze_boundaries(optimized_data);
    println!("Minimum Quantity: {}, Maximum Quantity: {}", min_q, max_q);
}