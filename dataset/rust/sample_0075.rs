fn optimize_supply_chain(data: &std::collections::HashMap<&str, std::collections::HashMap<&str, i32>>) -> Vec<&str> {
    fn calculate_cost(route: &Vec<&str>, data: &std::collections::HashMap<&str, std::collections::HashMap<&str, i32>>) -> i32 {
        (0..route.len() - 1).map(|i| data[route[i]][route[i + 1]]).sum()
    }

    fn find_best_route(routes: &Vec<Vec<&str>>, data: &std::collections::HashMap<&str, std::collections::HashMap<&str, i32>>) -> Vec<&str> {
        routes.iter().min_by_key(|&route| calculate_cost(route, data)).unwrap().clone()
    }

    let routes = &data["routes"];
    let best_route = find_best_route(routes, data);
    best_route
}

fn main() {
    let data = std::collections::HashMap::from([
        ("distances", std::collections::HashMap::from([
            ("A", std::collections::HashMap::from([("B", 10), ("C", 15)])),
            ("B", std::collections::HashMap::from([("A", 10), ("C", 35)])),
            ("C", std::collections::HashMap::from([("A", 15), ("B", 35)])),
        ])),
        ("routes", vec![vec!["A", "B", "C"], vec!["A", "C", "B"]]),
    ]);

    let best_route = optimize_supply_chain(&data);
    println!("{:?}", best_route);
}