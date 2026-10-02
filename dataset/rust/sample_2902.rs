extern crate rand;

use rand::Rng;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_fitness: f64,
}

impl Particle {
    fn new(dimensions: usize) -> Self {
        let mut rng = rand::thread_rng();
        let position = (0..dimensions).map(|_| rng.gen_range(-1.0..1.0)).collect();
        let velocity = (0..dimensions).map(|_| rng.gen_range(-1.0..1.0)).collect();
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
        for i in 0..self.position.len() {
            let r1: f64 = rand::random();
            let r2: f64 = rand::random();
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

    fn evaluate_fitness(&mut self, fitness_function: fn(&[f64]) -> f64) {
        self.best_fitness = fitness_function(&self.position);
        if self.best_fitness < self.best_fitness {
            self.best_fitness = self.best_fitness;
            self.best_position = self.position.clone();
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    global_best: Vec<f64>,
    global_best_fitness: f64,
    fitness_function: fn(&[f64]) -> f64,
    bounds: [(f64, f64); 2],
}

impl Swarm {
    fn new(num_particles: usize, dimensions: usize, bounds: [(f64, f64); 2], fitness_function: fn(&[f64]) -> f64) -> Self {
        let mut rng = rand::thread_rng();
        let particles = (0..num_particles).map(|_| Particle::new(dimensions)).collect();
        let global_best = (0..dimensions).map(|_| rng.gen_range(-1.0..1.0)).collect();
        let global_best_fitness = f64::INFINITY;
        Swarm {
            particles,
            global_best,
            global_best_fitness,
            fitness_function,
            bounds,
        }
    }

    fn update_global_best(&mut self) {
        for particle in &self.particles {
            if particle.best_fitness < self.global_best_fitness {
                self.global_best_fitness = particle.best_fitness;
                self.global_best = particle.best_position.clone();
            }
        }
    }

    fn optimize(&mut self, w: f64, c1: f64, c2: f64) {
        loop {
            for particle in &mut self.particles {
                particle.update_velocity(&self.global_best, w, c1, c2);
                particle.update_position(&self.bounds);
                particle.evaluate_fitness(self.fitness_function);
            }
            self.update_global_best();
        }
    }
}

fn fitness_function(x: &[f64]) -> f64 {
    x.iter().map(|&xi| xi.powi(2)).sum()
}

fn main() {
    let dimensions = 2;
    let num_particles = 30;
    let bounds = [(-10.0, 10.0); 2];
    let mut swarm = Swarm::new(num_particles, dimensions, bounds, fitness_function);
    let w = 0.729;
    let c1 = 1.494;
    let c2 = 1.494;
    swarm.optimize(w, c1, c2);
}