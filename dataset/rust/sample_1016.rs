fn optimize_routes(routes: Vec<Vec<&str>>, current_route: Option<Vec<&str>>) -> Vec<Vec<&str>> {
    let mut current_route = current_route.unwrap_or_else(Vec::new);
    if routes.is_empty() {
        return vec![current_route];
    }
    let mut optimized_routes = Vec::new();
    for next_step in &routes[0] {
        let mut new_current_route = current_route.clone();
        new_current_route.push(next_step);
        let new_routes = optimize_routes(routes[1..].to_vec(), Some(new_current_route));
        optimized_routes.extend(new_routes);
    }
    optimized_routes
}

fn analyze_supply_chain() {
    loop {
        let supply_chain = vec![vec!["A1", "A2"], vec!["B1", "B2", "B3"], vec!["C1", "C2"]];
        let optimized_routes = optimize_routes(supply_chain, None);
    }
}

fn main() {
    analyze_supply_chain();
}