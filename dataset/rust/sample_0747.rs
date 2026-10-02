use std::collections::HashSet;

fn optimize_route(routes: &std::collections::HashMap<&str, Vec<(&str, i32)>>, visited: &mut HashSet<&str>, current: &str, destination: &str, cost: i32) -> i32 {
    if current == destination {
        return cost;
    }
    let mut min_cost = i32::MAX;
    if let Some(next_routes) = routes.get(current) {
        for route in next_routes {
            if !visited.contains(route.0) {
                visited.insert(route.0);
                let new_cost = optimize_route(routes, visited, route.0, destination, cost + route.1);
                visited.remove(route.0);
                if new_cost < min_cost {
                    min_cost = new_cost;
                }
            }
        }
    }
    min_cost
}

fn find_optimal_path(routes: &std::collections::HashMap<&str, Vec<(&str, i32)>>, start: &str, end: &str) -> i32 {
    let mut visited = HashSet::new();
    visited.insert(start);
    optimize_route(routes, &mut visited, start, end, 0)
}

fn main() {
    let routes: std::collections::HashMap<&str, Vec<(&str, i32)>> = [
        ("A", vec![("B", 10), ("C", 15)]),
        ("B", vec![("C", 35), ("D", 25)]),
        ("C", vec![("D", 30)]),
        ("D", vec![]),
    ].iter().cloned().collect();
    let start = "A";
    let end = "D";
    println!("{}", find_optimal_path(&routes, start, end));
}