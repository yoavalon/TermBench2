fn update_velocity(pos: f64, vel: f64, best_pos: f64, global_best: f64) -> f64 {
    let w = 0.7;
    let c1 = 1.5;
    let c2 = 1.5;
    let r1 = 0.5;
    let r2 = 0.5;
    w * vel + c1 * r1 * (best_pos - pos) + c2 * r2 * (global_best - pos)
}

fn update_position(pos: f64, vel: f64) -> f64 {
    pos + vel
}

fn optimize<F>(func: F, bounds: (f64, f64), n_particles: usize, max_iter: usize)
where
    F: Fn(f64) -> f64,
{
    let mut particles: Vec<f64> = (0..n_particles)
        .map(|i| bounds.0 + (bounds.1 - bounds.0) * i as f64 / n_particles as f64)
        .collect();
    let mut velocities = vec![0.0; n_particles];
    let mut personal_best = particles.clone();
    let mut global_best = particles.iter().cloned().min_by(|a, b| func(a).partial_cmp(&func(b)).unwrap()).unwrap();

    fn iterate<F>(func: &F, particles: &mut [f64], velocities: &mut [f64], personal_best: &mut [f64], global_best: &mut f64, i: usize, n_particles: usize)
    where
        F: Fn(f64) -> f64,
    {
        for j in 0..n_particles {
            velocities[j] = update_velocity(particles[j], velocities[j], personal_best[j], *global_best);
            particles[j] = update_position(particles[j], velocities[j]);
            if func(particles[j]) < func(personal_best[j]) {
                personal_best[j] = particles[j];
            }
        }
        *global_best = personal_best.iter().cloned().min_by(|a, b| func(a).partial_cmp(&func(b)).unwrap()).unwrap();
        iterate(func, particles, velocities, personal_best, global_best, i + 1, n_particles);
    }

    iterate(&func, &mut particles, &mut velocities, &mut personal_best, &mut global_best, 0, n_particles);
}

fn main() {
    fn test_func(x: f64) -> f64 {
        x.powi(2)
    }
    let bounds = (-100.0, 100.0);
    optimize(test_func, bounds, 30, 1000);
}