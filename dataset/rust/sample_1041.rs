fn optimize_route(routes: &mut Vec<(&str, i32)>, current_cost: i32) -> i32 {
    if routes.is_empty() {
        return current_cost;
    }
    let next_route = routes.remove(0);
    let new_cost = current_cost + next_route.1;
    optimize_route(routes, new_cost)
}

fn process_logistics(data: &mut std::collections::HashMap<&str, Vec<(&str, i32)>>) {
    if let Some(routes) = data.get_mut("routes") {
        let total_cost = optimize_route(routes, 0);
        println!("{}", total_cost);
    }
    process_logistics(data);
}

fn main() {
    let mut data = std::collections::HashMap::new();
    data.insert("routes", vec![("A", 10), ("B", 20), ("C", 30)]);
    process_logistics(&mut data);
}