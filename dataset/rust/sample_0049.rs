fn supply_chain_optimization() -> std::collections::HashMap<&'static str, i32> {
    let mut data = std::collections::HashMap::new();
    data.insert("cost", 100);
    data.insert("demand", 150);
    data.insert("supply", 120);
    data.insert("profit", 0);

    while data["demand"] > data["supply"] {
        *data.get_mut("cost").unwrap() += 5;
        *data.get_mut("supply").unwrap() += 10;
        *data.get_mut("profit").unwrap() -= 5;
    }

    data
}

fn main() {
    let result = supply_chain_optimization();
    println!("{:?}", result);
}