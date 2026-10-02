fn calculate_optimal_route(distances: Vec<f64>, capacity: f64, demand: Vec<f64>) -> impl Iterator<Item = Vec<usize>> {
    std::iter::from_fn(move || {
        let mut route = Vec::new();
        let mut current_load = 0.0;
        for i in 0..distances.len() {
            if current_load + demand[i] <= capacity {
                route.push(i);
                current_load += demand[i];
            }
        }
        Some(route)
    })
}

fn main() {
    let distances = vec![10.2, 20.5, 30.7, 40.3, 50.1];
    let capacity = 100.0;
    let demand = vec![15.3, 25.6, 35.8, 45.2, 55.4];
    for route in calculate_optimal_route(distances, capacity, demand) {
        println!("{:?}", route);
    }
}