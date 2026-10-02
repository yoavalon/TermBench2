extern crate rand;

use rand::Rng;

struct Swarm {
    size: usize,
    dimensions: usize,
    search_space: (f64, f64),
    particles: Vec<Particle>,
}

impl Swarm {
    fn new(size: usize, dimensions: usize, search_space: (f64, f64)) -> Swarm {
        Swarm {
            size,
            dimensions,
            search_space,
            particles: (0..size).map(|_| Particle::new(dimensions, search_space)).collect(),
        }
    }

    fn update(&mut self) {
        for particle in &mut self.particles {
            particle.update_velocity();
            particle.update_position();
        }
    }
}

struct Particle {
    dimensions: usize,
    search_space: (f64, f64),
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_fitness: f64,
}

impl Particle {
    fn new(dimensions: usize, search_space: (f64, f64)) -> Particle {
        let mut rng = rand::thread_rng();
        let position = (0..dimensions)
            .map(|_| rng.gen_range(search_space.0..search_space.1))
            .collect();
        let velocity = (0..dimensions)
            .map(|_| rng.gen_range(-1.0..1.0))
            .collect();
        let best_position = position.clone();
        let best_fitness = f64::INFINITY;
        Particle {
            dimensions,
            search_space,
            position,
            velocity,
            best_position,
            best_fitness,
        }
    }

    fn update_velocity(&mut self) {
        let w = 0.7;
        let c1 = 1.5;
        let c2 = 1.5;
        let mut rng = rand::thread_rng();
        for i in 0..self.dimensions {
            let r1 = rng.gen::<f64>();
            let r2 = rng.gen::<f64>();
            let cognitive = c1 * r1 * (self.best_position[i] - self.position[i]);
            let social = c2 * r2 * (self.best_position[i] - self.position[i]);
            self.velocity[i] = w * self.velocity[i] + cognitive + social;
        }
    }

    fn update_position(&mut self) {
        for i in 0..self.dimensions {
            self.position[i] += self.velocity[i];
            self.position[i] = self.position[i].clamp(self.search_space.0, self.search_space.1);
        }
    }
}

fn fitness_function(position: &[f64]) -> f64 {
    position.iter().map(|&x| x.powi(2)).sum()
}

fn optimize(swarm: &mut Swarm, max_iterations: usize) {
    for _ in 0..max_iterations {
        for particle in &mut swarm.particles {
            let current_fitness = fitness_function(&particle.position);
            if current_fitness < particle.best_fitness {
                particle.best_fitness = current_fitness;
                particle.best_position = particle.position.clone();
            }
        }
        swarm.update();
    }
}

fn main() {
    let size = 30;
    let dimensions = 2;
    let search_space = (-10.0, 10.0);
    let max_iterations = 100;
    let mut swarm = Swarm::new(size, dimensions, search_space);
    optimize(&mut swarm, max_iterations);
}