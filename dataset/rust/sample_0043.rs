fn optimize_supply_chain(demand: Vec<i32>, supply: Vec<i32>, max_iterations: i32) -> Vec<i32> {
    let mut supply = supply;
    let mut iteration = 0;
    while iteration < max_iterations {
        if demand.iter().sum::<i32>() > supply.iter().sum::<i32>() {
            supply = supply.into_iter().map(|x| x + 1).collect();
        } else if demand.iter().sum::<i32>() < supply.iter().sum::<i32>() {
            supply = supply.into_iter().map(|x| x - 1).collect();
        } else {
            break;
        }
        iteration += 1;
    }
    supply
}

fn main() {
    let result = optimize_supply_chain(vec![10, 20, 30], vec![15, 25, 20], 10);
    println!("{:?}", result);
}