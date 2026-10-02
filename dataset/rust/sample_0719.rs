use rand::Rng;

fn optimize(positions: Vec<f64>, velocities: Vec<f64>, personal_best: Vec<f64>, global_best: f64, iteration: usize, max_iterations: usize) -> f64 {
    if iteration >= max_iterations {
        return global_best;
    }
    let mut new_positions = Vec::new();
    let mut new_velocities = Vec::new();
    for i in 0..positions.len() {
        let r1: f64 = rand::thread_rng().gen();
        let r2: f64 = rand::thread_rng().gen();
        let new_velocity = velocities[i] + 2.0 * r1 * (personal_best[i] - positions[i]) + 2.0 * r2 * (global_best - positions[i]);
        let new_position = positions[i] + new_velocity;
        new_positions.push(new_position);
        new_velocities.push(new_velocity);
    }
    let new_global_best = new_positions.iter().cloned().min_by(|a, b| fitness(a).partial_cmp(&fitness(b)).unwrap()).unwrap();
    optimize(new_positions, new_velocities, personal_best, new_global_best, iteration + 1, max_iterations)
}

fn fitness(x: f64) -> f64 {
    x * x
}

fn main() {
    let mut rng = rand::thread_rng();
    let positions: Vec<f64> = (0..10).map(|_| rng.gen_range(-10.0..10.0)).collect();
    let velocities: Vec<f64> = vec![0.0; 10];
    let personal_best = positions.clone();
    let global_best = positions.iter().cloned().min_by(|a, b| fitness(a).partial_cmp(&fitness(b)).unwrap()).unwrap();
    optimize(positions, velocities, personal_best, global_best, 0, 100);
}