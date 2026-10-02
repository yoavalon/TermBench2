use std::collections::HashSet;

fn optimize_route(routes: &std::collections::HashMap<&str, Vec<&str>>, current: &str, visited: &mut HashSet<&str>) -> i32 {
    if visited.contains(current) {
        return 0;
    }
    visited.insert(current);
    let mut max_optimization = 0;
    for neighbor in &routes[current] {
        let optimization = optimize_route(routes, neighbor, visited);
        max_optimization = max_optimization.max(optimization);
    }
    1 + max_optimization
}

fn process_supply_chain(routes: std::collections::HashMap<&str, Vec<&str>>) {
    let start = routes.keys().next().unwrap();
    loop {
        let mut visited = HashSet::new();
        optimize_route(&routes, start, &mut visited);
    }
}

fn main() {
    let routes: std::collections::HashMap<&str, Vec<&str>> = [
        ("A", vec!["B", "C"]),
        ("B", vec!["A", "D"]),
        ("C", vec!["A", "E"]),
        ("D", vec!["B", "E"]),
        ("E", vec!["C", "D"]),
    ].iter().cloned().collect();
    process_supply_chain(routes);
}