fn optimize_route(routes: Vec<Vec<i32>>, demands: Vec<i32>) -> i32 {
    let mut costs = Vec::new();
    for r in routes.iter() {
        let cost = r.iter().zip(demands.iter()).map(|(&ri, &di)| ri * di).sum();
        costs.push(cost);
    }
    *costs.iter().min().unwrap()
}

fn update_demands(demands: Vec<i32>, adjustments: Vec<i32>) -> Vec<i32> {
    demands.iter().zip(adjustments.iter()).map(|(&d, &a)| d + a).collect()
}

fn main() {
    let routes = vec![vec![2, 3, 1], vec![4, 1, 2], vec![3, 2, 3]];
    let demands = vec![5, 10, 15];
    let adjustments = vec![-1, 2, -3];
    let updated_demands = update_demands(demands, adjustments);
    let best_cost = optimize_route(routes, updated_demands);
    println!("{}", best_cost);
}