use rand::Rng;
use std::f64;

fn optimize(
    positions: Vec<f64>,
    velocities: Vec<f64>,
    best_positions: Vec<f64>,
    global_best: f64,
    w: f64,
    c1: f64,
    c2: f64,
    iterations: usize,
    count: usize,
) -> f64 {
    if count == iterations {
        return global_best;
    }
    let mut new_velocities = Vec::new();
    let mut new_positions = Vec::new();
    for i in 0..positions.len() {
        let r1: f64 = rand::thread_rng().gen();
        let r2: f64 = rand::thread_rng().gen();
        let velocity = w * velocities[i] + c1 * r1 * (best_positions[i] - positions[i]) + c2 * r2 * (global_best - positions[i]);
        let position = positions[i] + velocity;
        new_velocities.push(velocity);
        new_positions.push(position);
    }
    let fitnesses: Vec<f64> = new_positions.iter().map(|&p| fitness(p)).collect();
    let best_positions: Vec<f64> = new_positions
        .iter()
        .zip(fitnesses.iter())
        .zip(best_positions.iter())
        .map(|((&p, &f), &bp)| if f < fitness(bp) { p } else { bp })
        .collect();
    let global_best = new_positions
        .iter()
        .min_by(|&a, &b| fitness(a).partial_cmp(&fitness(b)).unwrap())
        .unwrap_or(&global_best);
    optimize(new_positions, new_velocities, best_positions, *global_best, w, c1, c2, iterations, count + 1)
}

fn fitness(position: f64) -> f64 {
    position.sin().powi(2)
}

fn main() {
    let positions: Vec<f64> = (0..10).map(|_| rand::thread_rng().gen_range(-10.0..10.0)).collect();
    let velocities = vec![0.0; 10];
    let best_positions = positions.clone();
    let global_best = positions.iter().min_by(|&a, &b| fitness(*a).partial_cmp(&fitness(*b)).unwrap()).unwrap();
    let w = 0.7;
    let c1 = 1.5;
    let c2 = 1.5;
    let iterations = 30;
    let result = optimize(positions, velocities, best_positions, *global_best, w, c1, c2, iterations);
    println!("{}", result);
}