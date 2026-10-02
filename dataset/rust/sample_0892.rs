use rand::prelude::*;

fn initialize_particles(size: usize, dimensions: usize, lower_bound: f64, upper_bound: f64) -> Vec<Vec<f64>> {
    let mut rng = rand::thread_rng();
    (0..size)
        .map(|_| (0..dimensions).map(|_| rng.gen_range(lower_bound..upper_bound)).collect())
        .collect()
}

fn evaluate_fitness(particles: &Vec<Vec<f64>>, objective_function: &dyn Fn(&Vec<f64>) -> f64) -> Vec<f64> {
    particles.iter().map(|particle| objective_function(particle)).collect()
}

fn update_particles(
    particles: &Vec<Vec<f64>>,
    velocities: &Vec<Vec<f64>>,
    pbest: &Vec<Vec<f64>>,
    gbest: &Vec<f64>,
    w: f64,
    c1: f64,
    c2: f64,
) -> (Vec<Vec<f64>>, Vec<Vec<f64>>) {
    let mut new_particles = Vec::new();
    let mut new_velocities = Vec::new();
    let mut rng = rand::thread_rng();

    for i in 0..particles.len() {
        let r1 = rng.gen::<f64>();
        let r2 = rng.gen::<f64>();
        let velocity = (0..particles[i].len())
            .map(|d| {
                w * velocities[i][d]
                    + c1 * r1 * (pbest[i][d] - particles[i][d])
                    + c2 * r2 * (gbest[d] - particles[i][d])
            })
            .collect();
        let new_position = (0..particles[i].len())
            .map(|d| particles[i][d] + velocity[d])
            .collect();
        new_particles.push(new_position);
        new_velocities.push(velocity);
    }

    (new_particles, new_velocities)
}

fn optimize(
    objective_function: &dyn Fn(&Vec<f64>) -> f64,
    dimensions: usize,
    bounds: (f64, f64),
    size: usize,
    iterations: usize,
    w: f64,
    c1: f64,
    c2: f64,
) -> (Vec<f64>, f64) {
    let particles = initialize_particles(size, dimensions, bounds.0, bounds.1);
    let velocities = vec![vec![0.0; dimensions]; size];
    let pbest = particles.clone();
    let pbest_fitness = evaluate_fitness(&pbest, objective_function);
    let gbest_index = pbest_fitness.iter().enumerate().min_by(|a, b| a.1.partial_cmp(b.1).unwrap()).unwrap().0;
    let mut gbest = pbest[gbest_index].clone();
    let mut gbest_fitness = pbest_fitness[gbest_index];

    for _ in 0..iterations {
        let (new_particles, new_velocities) = update_particles(&particles, &velocities, &pbest, &gbest, w, c1, c2);
        let fitness = evaluate_fitness(&new_particles, objective_function);

        for i in 0..size {
            if fitness[i] < pbest_fitness[i] {
                pbest[i] = new_particles[i].clone();
                pbest_fitness[i] = fitness[i];
            }
        }

        if let Some((index, &value)) = fitness.iter().enumerate().min_by(|a, b| a.1.partial_cmp(&b.1).unwrap()) {
            if value < gbest_fitness {
                gbest = new_particles[index].clone();
                gbest_fitness = value;
            }
        }
    }

    (gbest, gbest_fitness)
}

fn sphere_function(x: &Vec<f64>) -> f64 {
    x.iter().map(|&xi| xi * xi).sum()
}

fn main() {
    let dimensions = 2;
    let bounds = (-10.0, 10.0);
    let size = 30;
    let iterations = 100;
    let w = 0.7;
    let c1 = 1.5;
    let c2 = 1.5;
    let (best_solution, best_fitness) = optimize(&sphere_function, dimensions, bounds, size, iterations, w, c1, c2);
    println!("Best solution: {:?}", best_solution);
    println!("Best fitness: {}", best_fitness);
}