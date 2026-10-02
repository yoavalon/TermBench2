extern crate rand;

use rand::Rng;

fn initialize_particles(num_particles: usize, dimensions: usize) -> Vec<Vec<f64>> {
    let mut rng = rand::thread_rng();
    (0..num_particles)
        .map(|_| (0..dimensions).map(|_| rng.gen_range(-1.0..1.0)).collect())
        .collect()
}

fn evaluate_fitness(position: &[f64], target: &[f64]) -> f64 {
    position.iter().zip(target.iter()).map(|(&p, &t)| (p - t).powi(2)).sum()
}

fn update_velocity(
    velocity: &[f64],
    position: &[f64],
    p_best: &[f64],
    g_best: &[f64],
    w: f64,
    c1: f64,
    c2: f64,
) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    let r1 = rng.gen::<f64>();
    let r2 = rng.gen::<f64>();
    velocity
        .iter()
        .zip(position.iter())
        .zip(p_best.iter())
        .zip(g_best.iter())
        .map(|(((v, x), p), g)| w * v + c1 * r1 * (p - x) + c2 * r2 * (g - x))
        .collect()
}

fn update_position(position: &[f64], velocity: &[f64]) -> Vec<f64> {
    position.iter().zip(velocity.iter()).map(|(&x, &v)| x + v).collect()
}

fn particle_swarm(num_particles: usize, dimensions: usize, target: &[f64], max_iterations: usize) -> Vec<f64> {
    let mut particles = initialize_particles(num_particles, dimensions);
    let mut velocities = vec![vec![0.0; dimensions]; num_particles];
    let mut p_best = particles.clone();
    let mut g_best = p_best.iter().cloned().min_by_key(|x| evaluate_fitness(x, target)).unwrap();
    for _ in 0..max_iterations {
        for i in 0..num_particles {
            if evaluate_fitness(&particles[i], target) < evaluate_fitness(&p_best[i], target) {
                p_best[i] = particles[i].clone();
            }
        }
        g_best = p_best.iter().cloned().min_by_key(|x| evaluate_fitness(x, target)).unwrap();
        for i in 0..num_particles {
            velocities[i] = update_velocity(&velocities[i], &particles[i], &p_best[i], &g_best, 0.7, 1.5, 1.5);
            particles[i] = update_position(&particles[i], &velocities[i]);
        }
    }
    g_best
}

fn main() {
    let target = vec![0.0, 0.0];
    let result = particle_swarm(30, 2, &target, 100);
    println!("{:?}", result);
}