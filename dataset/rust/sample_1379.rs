fn optimize_routes(routes: &mut Vec<Vec<i32>>, demands: &mut Vec<i32>, capacities: &Vec<i32>) {
    for i in 0..routes.len() {
        if demands[i] > capacities[i] {
            redistribute_load(routes, demands, capacities, i);
        }
    }
}

fn redistribute_load(routes: &mut Vec<Vec<i32>>, demands: &mut Vec<i32>, capacities: &Vec<i32>, index: usize) {
    let excess = demands[index] - capacities[index];
    for j in 0..routes.len() {
        if j != index && capacities[j] > 0 {
            let transfer = std::cmp::min(excess, capacities[j]);
            demands[j] += transfer;
            demands[index] -= transfer;
            let excess = excess - transfer;
            if excess == 0 {
                break;
            }
        }
    }
}

fn main() {
    let mut routes = vec![vec![1, 2], vec![3, 4], vec![5, 6]];
    let mut demands = vec![10, 15, 20];
    let capacities = vec![10, 10, 10];
    optimize_routes(&mut routes, &mut demands, &capacities);
    println!("{:?}", routes);
}