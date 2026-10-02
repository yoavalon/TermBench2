use std::collections::HashMap;

fn calculate_cost(route: &Vec<&str>, costs: &HashMap<(&str, &str), i32>) -> i32 {
    let mut total_cost = 0;
    for i in 0..route.len() - 1 {
        let cost = *costs.get(&(route[i], route[i + 1])).unwrap_or(&0);
        total_cost += cost;
    }
    total_cost
}

fn find_optimal_route(routes: &Vec<Vec<&str>>, costs: &HashMap<(&str, &str), i32>) -> Option<&Vec<&str>> {
    let mut min_cost = i32::MAX;
    let mut best_route = None;
    for route in routes {
        let cost = calculate_cost(route, costs);
        if cost < min_cost {
            min_cost = cost;
            best_route = Some(route);
        }
    }
    best_route
}

fn main() {
    let routes = vec![
        vec!["A", "B", "C"],
        vec!["A", "C", "B"],
        vec!["B", "A", "C"],
    ];
    let mut costs = HashMap::new();
    costs.insert(("A", "B"), 10);
    costs.insert(("B", "C"), 15);
    costs.insert(("C", "A"), 20);
    let optimal_route = find_optimal_route(&routes, &costs);
    if let Some(route) = optimal_route {
        println!("{:?}", route);
    }
}