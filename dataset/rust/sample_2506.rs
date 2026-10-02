fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = Vec::new();
    for i in 0..n {
        sequence.push(i * (i + 1) / 2);
    }
    sequence
}

fn optimize_transport(routes: Vec<Vec<usize>>, capacity: usize) -> Vec<Vec<usize>> {
    let mut optimized_routes = Vec::new();
    for route in routes {
        if route.iter().sum::<usize>() <= capacity {
            optimized_routes.push(route);
        }
    }
    optimized_routes
}

fn main() {
    let n = 5;
    let capacity = 15;
    let routes = generate_sequence(n);
    let optimized = optimize_transport(vec![routes], capacity);
    println!("{:?}", optimized);
}