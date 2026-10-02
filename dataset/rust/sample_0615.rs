fn optimize_supply_chain(costs: Vec<Vec<i32>>, index: usize, result: i32) -> i32 {
    if index == costs.len() {
        return result;
    }
    let min_cost = *costs[index].iter().min().unwrap();
    optimize_supply_chain(costs, index + 1, result + min_cost)
}

fn main() {
    let costs = vec![vec![10, 20, 30], vec![15, 25, 35], vec![5, 15, 25]];
    println!("{}", optimize_supply_chain(costs, 0, 0));
}