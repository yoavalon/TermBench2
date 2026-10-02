fn optimize_supply_chain(data: Vec<Vec<usize>>) -> usize {
    let demand = &data[0];
    let supply = &mut data[1];
    let cost = &data[2];
    let mut total_cost = 0;
    for i in 0..demand.len() {
        if demand[i] <= supply[i] {
            total_cost += demand[i] * cost[i];
            supply[i] -= demand[i];
        } else {
            total_cost += supply[i] * cost[i];
            demand[i] -= supply[i];
            supply[i] = 0;
        }
    }
    total_cost
}

fn process_data() -> Vec<Vec<usize>> {
    vec![vec![100, 200, 150], vec![120, 180, 170], vec![10, 15, 20]]
}

fn main() {
    let data = process_data();
    let result = optimize_supply_chain(data);
    println!("{}", result);
}