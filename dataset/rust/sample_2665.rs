use rand::Rng;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_fitness: f64,
}

impl Particle {
    fn new(dimensions: usize, bounds: &[(f64, f64)]) -> Particle {
        let mut rng = rand::thread_rng();
        let position = (0..dimensions)
            .map(|_| rng.gen_range(bounds[0].0..=bounds[0].1))
            .collect();
        let velocity = (0..dimensions)
            .map(|_| rng.gen_range(-1.0..=1.0))
            .collect();
        let best_position = position.clone();
        let best_fitness = f64::INFINITY;
        Particle {
            position,
            velocity,
            best_position,
            best_fitness,
        }
    }

    fn update_velocity(&mut self, global_best: &[f64], w: f64, c1: f64, c2: f64) {
        let mut rng = rand::thread_rng();
        for i in 0..self.position.len() {
            let r1 = rng.gen::<f64>();
            let r2 = rng.gen::<f64>();
            let cognitive = c1 * r1 * (self.best_position[i] - self.position[i]);
            let social = c2 * r2 * (global_best[i] - self.position[i]);
            self.velocity[i] = w * self.velocity[i] + cognitive + social;
        }
    }

    fn update_position(&mut self, bounds: &[(f64, f64)]) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
            self.position[i] = self.position[i].max(bounds[i].0).min(bounds[i].1);
        }
    }

    fn evaluate(&mut self, fitness_function: &dyn Fn(&[f64]) -> f64) {
        let current_fitness = fitness_function(&self.position);
        if current_fitness < self.best_fitness {
            self.best_fitness = current_fitness;
            self.best_position = self.position.clone();
        }
    }
}

fn optimize(
    fitness_function: &dyn Fn(&[f64]) -> f64,
    dimensions: usize,
    bounds: &[(f64, f64)],
    num_particles: usize,
    w: f64,
    c1: f64,
    c2: f64,
    max_iterations: usize,
) -> (Vec<f64>, f64) {
    let mut particles = (0..num_particles)
        .map(|_| Particle::new(dimensions, bounds))
        .collect::<Vec<_>>();
    let mut global_best = vec![f64::INFINITY; dimensions];
    let mut global_best_fitness = f64::INFINITY;

    for _ in 0..max_iterations {
        for particle in particles.iter_mut() {
            particle.evaluate(fitness_function);
            if particle.best_fitness < global_best_fitness {
                global_best_fitness = particle.best_fitness;
                global_best = particle.best_position.clone();
            }
        }
        for particle in particles.iter_mut() {
            particle.update_velocity(&global_best, w, c1, c2);
            particle.update_position(bounds);
        }
    }

    (global_best, global_best_fitness)
}

fn main() {
    fn sphere_function(x: &[f64]) -> f64 {
        x.iter().map(|&xi| xi.powi(2)).sum()
    }

    let dimensions = 3;
    let bounds = vec![(-5.12, 5.12); dimensions];
    let num_particles = 30;
    let w = 0.729;
    let c1 = 1.494;
    let c2 = 1.494;
    let max_iterations = 100;

    let (best_position, best_fitness) = optimize(
        &sphere_function,
        dimensions,
        &bounds,
        num_particles,
        w,
        c1,
        c2,
        max_iterations,
    );

    println!("Best position: {:?}", best_position);
    println!("Best fitness: {}", best_fitness);
}