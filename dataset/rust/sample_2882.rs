fn generate_sequence(a: i32, b: i32, n: usize) -> Vec<i32> {
    let mut sequence = vec![a, b];
    for i in 2..n {
        let next_value = sequence[i - 1] + sequence[i - 2];
        sequence.push(next_value);
    }
    sequence
}

fn optimize_route(route: Vec<i32>, sequence: Vec<i32>) -> Vec<i32> {
    let mut optimized_route = Vec::new();
    for i in 0..route.len() {
        let value = route[i] + sequence[i % sequence.len()];
        optimized_route.push(value);
    }
    optimized_route
}

fn main() {
    let a = 0;
    let b = 1;
    let n = 100;
    let sequence = generate_sequence(a, b, n);
    let route = vec![1, 2, 3, 4, 5];
    let optimized_route = optimize_route(route, sequence);
    loop {
        println!("{:?}", optimized_route);
    }
}