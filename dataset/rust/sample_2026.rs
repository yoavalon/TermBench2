use rand::Rng;

fn initialize_particles(size: usize, dimensions: usize) -> Vec<std::collections::HashMap<String, Vec<f64>>> {
    let mut particles = Vec::new();
    for _ in 0..size {
        let mut rng = rand::thread_rng();
        let position = (0..dimensions).map(|_| rng.gen_range(-10.0..10.0)).collect();
        let velocity = (0..dimensions).map(|_| rng.gen_range(-1.0..1.0)).collect();
        let pbest_position = position.clone();
        let pbest_value = f64::INFINITY;
        let mut particle = std::collections::HashMap::new();
        particle.insert("position".to_string(), position);
        particle.insert("velocity".to_string(), velocity);
        particle.insert("pbest_position".to_string(), pbest_position);
        particle.insert("pbest_value".to_string(), vec![pbest_value]);
        particles.push(particle);
    }
    particles
}

fn update_velocity(particles: &mut Vec<std::collections::HashMap<String, Vec<f64>>>, gbest_position: &Vec<f64>, w: f64, c1: f64, c2: f64) {
    let mut rng = rand::thread_rng();
    for particle in particles.iter_mut() {
        let position = particle.get("position").unwrap();
        let velocity = particle.get("velocity").unwrap();
        let pbest_position = particle.get("pbest_position").unwrap();
        for i in 0..position.len() {
            let r1 = rng.gen::<f64>();
            let r2 = rng.gen::<f64>();
            let cognitive = c1 * r1 * (pbest_position[i] - position[i]);
            let social = c2 * r2 * (gbest_position[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }
}

fn update_position(particles: &mut Vec<std::collections::HashMap<String, Vec<f64>>>, bounds: (f64, f64)) {
    for particle in particles.iter_mut() {
        let position = particle.get_mut("position").unwrap();
        let velocity = particle.get("velocity").unwrap();
        for i in 0..position.len() {
            position[i] += velocity[i];
            position[i] = position[i].clamp(bounds.0, bounds.1);
        }
    }
}

fn evaluate(particles: &mut Vec<std::collections::HashMap<String, Vec<f64>>>, objective_function: &dyn Fn(&Vec<f64>) -> f64) {
    for particle in particles.iter_mut() {
        let position = particle.get("position").unwrap();
        let value = objective_function(position);
        let pbest_value = particle.get("pbest_value").unwrap()[0];
        if value < pbest_value {
            particle.insert("pbest_value".to_string(), vec![value]);
            particle.insert("pbest_position".to_string(), position.clone());
        }
    }
}

fn find_gbest(particles: &Vec<std::collections::HashMap<String, Vec<f64>>>) -> Vec<f64> {
    let mut gbest_value = f64::INFINITY;
    let mut gbest_position = Vec::new();
    for particle in particles.iter() {
        let pbest_value = particle.get("pbest_value").unwrap()[0];
        if pbest_value < gbest_value {
            gbest_value = pbest_value;
            gbest_position = particle.get("pbest_position").unwrap().clone();
        }
    }
    gbest_position
}

fn optimize(objective_function: &dyn Fn(&Vec<f64>) -> f64, dimensions: usize, size: usize, iterations: usize, bounds: (f64, f64)) -> Vec<f64> {
    let mut particles = initialize_particles(size, dimensions);
    let mut gbest_position = find_gbest(&particles);
    for _ in 0..iterations {
        update_velocity(&mut particles, &gbest_position, 0.7, 1.5, 1.5);
        update_position(&mut particles, bounds);
        evaluate(&mut particles, objective_function);
        gbest_position = find_gbest(&particles);
    }
    gbest_position
}

fn main() {
    fn sphere_function(x: &Vec<f64>) -> f64 {
        x.iter().map(|xi| xi.powi(2)).sum()
    }
    let dimensions = 30;
    let size = 30;
    let iterations = 100;
    let bounds = (-10.0, 10.0);
    let result = optimize(&sphere_function, dimensions, size, iterations, bounds);
    println!("{:?}", result);
}