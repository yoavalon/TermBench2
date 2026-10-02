use rand::seq::SliceRandom;
use rand::thread_rng;
use std::f64;

fn calculate_cost(route: &[usize], distances: &Vec<Vec<f64>>) -> f64 {
    let mut cost = 0.0;
    for i in 0..route.len() - 1 {
        cost += distances[route[i]][route[i + 1]];
    }
    cost
}

fn optimize_route(start: usize, nodes: &[usize], distances: &Vec<Vec<f64>>) {
    let mut route = vec![start];
    let mut rng = thread_rng();
    route.extend(nodes.choose_multiple(&mut rng, nodes.len()).cloned());
    let mut cost = calculate_cost(&route, distances);
    loop {
        for i in 1..route.len() - 1 {
            for j in i + 1..route.len() {
                let mut new_route = route.clone();
                new_route[i..=j].reverse();
                let new_cost = calculate_cost(&new_route, distances);
                if new_cost < cost {
                    route = new_route;
                    cost = new_cost;
                }
            }
        }
    }
}

fn main() {
    let nodes: Vec<usize> = (0..10).collect();
    let mut distances = vec![vec![0.0; 10]; 10];
    for i in 0..10 {
        for j in 0..10 {
            if i != j {
                distances[i][j] = rand::random::<f64>() * 99.0 + 1.0;
            }
        }
    }
    optimize_route(0, &nodes[1..], &distances);
}