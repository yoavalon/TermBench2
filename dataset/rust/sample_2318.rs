use rand::Rng;

fn initialize_particles(dimensions: usize, count: usize) -> Vec<Vec<f64>> {
    let mut particles = Vec::new();
    for _ in 0..count {
        let position: Vec<f64> = (0..dimensions).map(|_| rand::thread_rng().gen_range(-10.0..10.0)).collect();
        let velocity: Vec<f64> = (0..dimensions).map(|_| rand::thread_rng().gen_range(-1.0..1.0)).collect();
        particles.push(vec![position, velocity, position]);
    }
    particles
}

fn evaluate_fitness(particles: &mut Vec<Vec<f64>>, objective_function: &dyn Fn(&[f64]) -> f64) {
    for particle in particles {
        particle[2] = objective_function(&particle[0]);
    }
}

fn update_particles(particles: &mut Vec<Vec<f64>>, global_best: &[f64], inertia_weight: f64, cognitive_weight: f64, social_weight: f64) {
    for particle in particles {
        for i in 0..particle[0].len() {
            let r1 = rand::thread_rng().gen::<f64>();
            let r2 = rand::thread_rng().gen::<f64>();
            let cognitive_velocity = cognitive_weight * r1 * (particle[2][i] - particle[0][i]);
            let social_velocity = social_weight * r2 * (global_best[i] - particle[0][i]);
            particle[1][i] = inertia_weight * particle[1][i] + cognitive_velocity + social_velocity;
            particle[0][i] += particle[1][i];
        }
        if particle[2] < particle[2] {
            particle[2] = particle[0].clone();
        }
    }
}

fn find_global_best(particles: &[Vec<f64>]) -> &[f64] {
    let mut global_best = &particles[0];
    for particle in &particles[1..] {
        if particle[2] < global_best[2] {
            global_best = particle;
        }
    }
    global_best
}

fn objective_function(position: &[f64]) -> f64 {
    position.iter().map(|&x| x.powi(2)).sum()
}

fn main() {
    let dimensions = 2;
    let particle_count = 30;
    let inertia_weight = 0.7;
    let cognitive_weight = 1.5;
    let social_weight = 1.5;
    let mut particles = initialize_particles(dimensions, particle_count);
    loop {
        evaluate_fitness(&mut particles, &objective_function);
        let global_best = find_global_best(&particles);
        update_particles(&mut particles, global_best, inertia_weight, cognitive_weight, social_weight);
    }
}