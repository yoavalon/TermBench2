use rand::Rng;

fn initialize_particles(dimensions: usize, population_size: usize) -> Vec<Vec<f64>> {
    let mut particles = Vec::new();
    for _ in 0..population_size {
        let position = (0..dimensions).map(|_| rand::thread_rng().gen_range(-10.0..10.0)).collect();
        particles.push(position);
    }
    particles
}

fn update_particles(particles: &mut [Vec<f64>], global_best: &[f64]) {
    for particle in particles.iter_mut() {
        let mut velocity = vec![0.0; particle.len()];
        for i in 0..particle.len() {
            let r1 = rand::thread_rng().gen::<f64>();
            let r2 = rand::thread_rng().gen::<f64>();
            let cognitive_velocity = r1 * (particle[i] - particle[i]);
            let social_velocity = r2 * (global_best[i] - particle[i]);
            velocity[i] = 0.7 * velocity[i] + cognitive_velocity + social_velocity;
            particle[i] += velocity[i];
        }
    }
}

fn evaluate(position: &[f64]) -> f64 {
    position.iter().map(|&x| x.powi(2)).sum()
}

fn find_global_best(particles: &[Vec<f64>]) -> &Vec<f64> {
    particles.iter().min_by_key(|&x| evaluate(x)).unwrap()
}

fn main() {
    let dimensions = 2;
    let population_size = 10;
    let mut particles = initialize_particles(dimensions, population_size);
    let mut global_best = find_global_best(&particles);
    loop {
        update_particles(&mut particles, global_best);
        global_best = find_global_best(&particles);
    }
}