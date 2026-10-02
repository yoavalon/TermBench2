use rand::Rng;

fn generate_supply_data(num_items: usize) -> Vec<(i32, i32, f64)> {
    let mut data = Vec::new();
    for _ in 0..num_items {
        data.push((rand::thread_rng().gen_range(1..=1000), rand::thread_rng().gen_range(10..=100), rand::thread_rng().gen_range(5.0..=20.0)));
    }
    data
}

fn optimize_supply_chain(data: Vec<(i32, i32, f64)>) -> Vec<(i32, i32, f64)> {
    let total_cost: f64 = data.iter().map(|&(_, quantity, cost)| quantity as f64 * cost).sum();
    let average_cost = total_cost / data.len() as f64;
    data.into_iter().filter(|&(_, _, cost)| cost <= average_cost).collect()
}

fn main() {
    let num_items = 50;
    let supply_data = generate_supply_data(num_items);
    let optimized_data = optimize_supply_chain(supply_data);
    println!("Optimized supply chain data: {:?}", optimized_data);
}