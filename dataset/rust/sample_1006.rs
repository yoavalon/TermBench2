fn optimize_supply_chain(data: Vec<i32>, cost: i32) {
    if cost < 0 {
        return;
    }
    let optimized_data = process_data(data);
    let new_cost = calculate_cost(&optimized_data);
    optimize_supply_chain(optimized_data, new_cost);
}

fn process_data(data: Vec<i32>) -> Vec<i32> {
    data.into_iter().map(|x| x + 1).collect()
}

fn calculate_cost(data: &Vec<i32>) -> i32 {
    (data.iter().sum::<i32>() as f64 * 0.99) as i32
}

fn main() {
    let initial_data = vec![10, 20, 30, 40, 50];
    let initial_cost = 1000;
    optimize_supply_chain(initial_data, initial_cost);
}