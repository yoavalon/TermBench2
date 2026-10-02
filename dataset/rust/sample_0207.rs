use rand::prelude::*;

fn initialize_particles(num_particles: usize, num_dimensions: usize) -> Vec<Vec<f64>> {
    let mut particles = Vec::new();
    for _ in 0..num_particles {
        let position: Vec<f64> = (0..num_dimensions).map(|_| rand::random::<f64>() * 20.0 - 10.0).collect();
        let velocity: Vec<f64> = (0..num_dimensions).map(|_| rand::random::<f64>() * 2.0 - 1.0).collect();
        let best_position = position.clone();
        particles.push(vec![position, velocity, best_position]);
    }
    particles
}

fn update_velocity(particles: &mut Vec<Vec<f64>>, global_best: &Vec<f64>, w: f64, c1: f64, c2: f64) {
    for particle in particles {
        let r1: f64 = rand::random();
        let r2: f64 = rand::random();
        for i in 0..particle[0].len() {
            let cognitive_velocity = c1 * r1 * (particle[2][i] - particle[0][i]);
            let social_velocity = c2 * r2 * (global_best[i] - particle[0][i]);
            particle[1][i] = w * particle[1][i] + cognitive_velocity + social_velocity;
        }
    }
}

fn update_position(particles: &mut Vec<Vec<f64>>) {
    for particle in particles {
        for i in 0..particle[0].len() {
            particle[0][i] += particle[1][i];
        }
    }
}

fn evaluate_fitness(particles: &Vec<Vec<f64>>, fitness_function: &dyn Fn(&[f64]) -> f64) -> Vec<f64> {
    let mut global_best = particles[0].clone();
    let mut best_fitness = fitness_function(&global_best[0]);
    for particle in particles {
        let fitness = fitness_function(&particle[0]);
        if fitness < best_fitness {
            best_fitness = fitness;
            global_best = particle.clone();
        }
    }
    global_best
}

fn main() {
    let num_particles = 20;
    let num_dimensions = 2;
    let w = 0.7;
    let c1 = 1.5;
    let c2 = 1.5;
    let max_iterations = 100;

    let fitness_function = |position: &[f64]| -> f64 {
        position.iter().map(|&x| x.powi(2)).sum()
    };

    let mut particles = initialize_particles(num_particles, num_dimensions);
    let mut global_best = evaluate_fitness(&particles, &fitness_function);
    for _ in 0..max_iterations {
        update_velocity(&mut particles, &global_best[0], w, c1, c2);
        update_position(&mut particles);
        global_best = evaluate_fitness(&particles, &fitness_function);
    }
    println!("Best position found: {:?}", global_best[0]);
    println!("Fitness value: {}", fitness_function(&global_best[0]));
}