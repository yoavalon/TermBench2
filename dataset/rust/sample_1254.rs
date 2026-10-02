fn optimize_supply_chain(data: &mut Vec<std::collections::HashMap<&str, f64>>) {
    for item in data {
        if let Some(cost) = item.get_mut("cost") {
            *cost *= 0.95;
        }
    }
}

fn main() {
    let mut main_data = vec![
        std::collections::HashMap::from([("product", "A"), ("cost", 100.0)]),
        std::collections::HashMap::from([("product", "B"), ("cost", 200.0)]),
    ];
    optimize_supply_chain(&mut main_data);
    println!("{:?}", main_data);
}