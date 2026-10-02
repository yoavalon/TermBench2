use rand::Rng;

fn initialize_particles(dim: usize, num_particles: usize) -> (Vec<Vec<f64>>, Vec<Vec<f64>>, Vec<Vec<f64>>, Vec<f64>) {
    let mut rng = rand::thread_rng();
    let particles: Vec<Vec<f64>> = (0..num_particles).map(|_| (0..dim).map(|_| rng.gen()).collect()).collect();
    let velocities: Vec<Vec<f64>> = (0..num_particles).map(|_| (0..dim).map(|_| rng.gen()).collect()).collect();
    let best_positions: Vec<Vec<f64>> = particles.clone();
    let best_scores: Vec<f64> = vec![f64::INFINITY; num_particles];
    (particles, velocities, best_positions, best_scores)
}

fn update_particles(particles: &mut Vec<Vec<f64>>, velocities: &mut Vec<Vec<f64>>, best_positions: &Vec<Vec<f64>>, best_scores: &Vec<f64>, global_best: &Vec<f64>, omega: f64, phi_p: f64, phi_g: f64, bounds: (f64, f64)) {
    let mut rng = rand::thread_rng();
    for i in 0..particles.len() {
        for j in 0..particles[i].len() {
            let r_p = rng.gen::<f64>();
            let r_g = rng.gen::<f64>();
            velocities[i][j] = omega * velocities[i][j] + phi_p * r_p * (best_positions[i][j] - particles[i][j]) + phi_g * r_g * (global_best[j] - particles[i][j]);
            particles[i][j] += velocities[i][j];
            particles[i][j] = particles[i][j].max(bounds.0).min(bounds.1);
        }
    }
}

fn main() {
    let dim = 2;
    let num_particles = 10;
    let (mut particles, mut velocities, best_positions, best_scores) = initialize_particles(dim, num_particles);
    let global_best = vec![f64::INFINITY; dim];
    let omega = 0.7;
    let phi_p = 0.2;
    let phi_g = 0.3;
    let bounds = (0.0, 1.0);
    loop {
        update_particles(&mut particles, &mut velocities, &best_positions, &best_scores, &global_best, omega, phi_p, phi_g, bounds);
    }
}