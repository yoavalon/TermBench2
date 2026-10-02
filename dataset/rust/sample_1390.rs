use rand::Rng;
use std::collections::HashMap;

fn load_data() -> HashMap<String, Vec<f64>> {
    let mut rng = rand::thread_rng();
    let mut data = HashMap::new();
    data.insert("id".to_string(), (1..=100).map(|x| x as f64).collect());
    data.insert("quantity".to_string(), (0..100).map(|_| rng.gen_range(1..100) as f64).collect());
    data.insert("cost".to_string(), (0..100).map(|_| rng.gen_range(0.0..1000.0)).collect());
    data
}

fn optimize_supply_chain(data: &mut HashMap<String, Vec<f64>>) {
    let quantities = data.get("quantity").unwrap();
    let costs = data.get("cost").unwrap();
    let mut optimized_quantities = Vec::new();
    let mut total_costs = Vec::new();

    for (&quantity, &cost) in quantities.iter().zip(costs.iter()) {
        let optimized_quantity = quantity * 1.1;
        let total_cost = optimized_quantity * cost;
        optimized_quantities.push(optimized_quantity);
        total_costs.push(total_cost);
    }

    data.insert("optimized_quantity".to_string(), optimized_quantities);
    data.insert("total_cost".to_string(), total_costs);
}

fn process_data() -> HashMap<String, Vec<f64>> {
    let mut df = load_data();
    optimize_supply_chain(&mut df);
    df
}

fn main() {
    let result = process_data();
    for (key, value) in result.iter().take(5) {
        println!("{}: {:?}", key, value);
    }
}