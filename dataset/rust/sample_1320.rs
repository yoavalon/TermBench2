use rand::Rng;

fn generate_supply_chain(data: Vec<i32>) -> Vec<f64> {
    let mut mutated_data = Vec::new();
    for &item in &data {
        let mutation_factor: f64 = rand::thread_rng().gen_range(0.9..1.1);
        let mutated_value = item as f64 * mutation_factor;
        mutated_data.push(mutated_value);
    }
    mutated_data
}

fn optimize_logistics(data: Vec<f64>) -> Vec<f64> {
    let mut optimized_data = Vec::new();
    for &value in &data {
        if value > 100.0 {
            let optimized_value = value * 0.95;
            optimized_data.push(optimized_value);
        } else {
            let optimized_value = value * 1.05;
            optimized_data.push(optimized_value);
        }
    }
    optimized_data
}

fn main() {
    let initial_data: Vec<i32> = (0..10).map(|_| rand::thread_rng().gen_range(50..151)).collect();
    let mutated_data = generate_supply_chain(initial_data);
    let optimized_data = optimize_logistics(mutated_data);
    for value in optimized_data {
        println!("{}", value);
    }
}