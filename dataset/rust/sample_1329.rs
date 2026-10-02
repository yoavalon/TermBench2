fn calculate_route_costs(routes: Vec<Vec<i32>>) -> Vec<i32> {
    let mut costs = Vec::new();
    for route in routes {
        let cost = route.iter().sum();
        costs.push(cost);
    }
    costs
}

fn optimize_routes(routes: Vec<Vec<i32>>, budgets: Vec<i32>) -> Vec<Vec<i32>> {
    let mut optimized_routes = Vec::new();
    for (route, budget) in routes.iter().zip(budgets.iter()) {
        if route.iter().sum::<i32>() <= *budget {
            optimized_routes.push(route.clone());
        }
    }
    optimized_routes
}

fn main() {
    let routes = vec![vec![10, 20, 30], vec![40, 50, 60], vec![70, 80, 90]];
    let budgets = vec![150, 200, 250];
    let costs = calculate_route_costs(routes.clone());
    let optimized_routes = optimize_routes(routes, budgets);
    println!("{:?}", optimized_routes);
}