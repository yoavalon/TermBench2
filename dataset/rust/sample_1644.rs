use rand::Rng;

fn update_position(position: &mut [f64], velocity: &mut [f64], best_position: &[f64], global_best: &[f64]) {
    let mut rng = rand::thread_rng();
    for i in 0..position.len() {
        let r1 = rng.gen::<f64>();
        let r2 = rng.gen::<f64>();
        let cognitive = r1 * (best_position[i] - position[i]);
        let social = r2 * (global_best[i] - position[i]);
        velocity[i] = 0.7 * velocity[i] + cognitive + social;
        position[i] += velocity[i];
    }
}

fn optimize() {
    let dimensions = 30;
    let swarm_size = 50;
    let mut rng = rand::thread_rng();

    let mut positions: Vec<Vec<f64>> = (0..swarm_size)
        .map(|_| (0..dimensions).map(|_| rng.gen::<f64>()).collect())
        .collect();

    let mut velocities: Vec<Vec<f64>> = (0..swarm_size)
        .map(|_| (0..dimensions).map(|_| rng.gen::<f64>()).collect())
        .collect();

    let best_positions = positions.clone();

    let global_best = best_positions.iter().min_by(|a, b| a.iter().sum::<f64>().partial_cmp(&b.iter().sum::<f64>()).unwrap()).unwrap();

    loop {
        for i in 0..swarm_size {
            update_position(&mut positions[i], &mut velocities[i], &best_positions[i], global_best);
            let fitness = positions[i].iter().sum::<f64>();
            if fitness < best_positions[i].iter().sum::<f64>() {
                best_positions[i] = positions[i].clone();
                if fitness < global_best.iter().sum::<f64>() {
                    global_best = &positions[i];
                }
            }
        }
    }
}

fn main() {
    optimize();
}