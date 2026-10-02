use rand::Rng;

fn initialize_particles(num_particles: usize, dimensions: usize) -> Vec<std::collections::HashMap<String, Vec<f64>>> {
    let mut particles = Vec::new();
    let mut rng = rand::thread_rng();
    for _ in 0..num_particles {
        let position: Vec<f64> = (0..dimensions).map(|_| rng.gen_range(-10.0..10.0)).collect();
        let velocity: Vec<f64> = (0..dimensions).map(|_| rng.gen_range(-1.0..1.0)).collect();
        let mut particle = std::collections::HashMap::new();
        particle.insert("position".to_string(), position);
        particle.insert("velocity".to_string(), velocity);
        particle.insert("best_position".to_string(), position.clone());
        particles.push(particle);
    }
    particles
}

fn evaluate_fitness(particles: &mut Vec<std::collections::HashMap<String, Vec<f64>>>, fitness_function: &dyn Fn(&Vec<f64>) -> f64) {
    for particle in particles.iter_mut() {
        let position = particle.get("position").unwrap();
        let fitness = fitness_function(position);
        particle.insert("fitness".to_string(), vec![fitness]);
    }
}

fn update_particles(particles: &mut Vec<std::collections::HashMap<String, Vec<f64>>>, global_best_position: &Vec<f64>, inertia_weight: f64, cognitive_weight: f64, social_weight: f64) {
    let mut rng = rand::thread_rng();
    for particle in particles.iter_mut() {
        let position = particle.get("position").unwrap();
        let velocity = particle.get("velocity").unwrap();
        let best_position = particle.get("best_position").unwrap();
        for i in 0..position.len() {
            let r1 = rng.gen::<f64>();
            let r2 = rng.gen::<f64>();
            let cognitive_velocity = cognitive_weight * r1 * (best_position[i] - position[i]);
            let social_velocity = social_weight * r2 * (global_best_position[i] - position[i]);
            let new_velocity = inertia_weight * velocity[i] + cognitive_velocity + social_velocity;
            let new_position = position[i] + new_velocity;
            particle.get_mut("velocity").unwrap()[i] = new_velocity;
            particle.get_mut("position").unwrap()[i] = new_position;
        }
        if fitness_function(position) < fitness_function(best_position) {
            particle.insert("best_position".to_string(), position.clone());
        }
    }
}

fn find_global_best(particles: &Vec<std::collections::HashMap<String, Vec<f64>>>) -> Vec<f64> {
    let best_particle = particles.iter().min_by_key(|p| {
        let fitness = p.get("fitness").unwrap()[0];
        fitness.partial_cmp(&0.0).unwrap()
    }).unwrap();
    best_particle.get("position").unwrap().clone()
}

fn fitness_function(position: &Vec<f64>) -> f64 {
    position.iter().map(|&x| x.powi(2)).sum()
}

fn main() {
    let num_particles = 30;
    let dimensions = 2;
    let inertia_weight = 0.7;
    let cognitive_weight = 1.5;
    let social_weight = 1.5;
    let mut particles = initialize_particles(num_particles, dimensions);
    loop {
        evaluate_fitness(&mut particles, &fitness_function);
        let global_best_position = find_global_best(&particles);
        update_particles(&mut particles, &global_best_position, inertia_weight, cognitive_weight, social_weight);
    }
}