extern crate rand;

use rand::Rng;

struct Swarm {
    size: usize,
    dimensions: usize,
    bounds: [f64; 2],
    particles: Vec<Particle>,
    gbest: Option<Particle>,
}

impl Swarm {
    fn new(size: usize, dimensions: usize, bounds: [f64; 2]) -> Swarm {
        let particles = (0..size).map(|_| Particle::new(dimensions, bounds)).collect();
        Swarm {
            size,
            dimensions,
            bounds,
            particles,
            gbest: None,
        }
    }

    fn update_gbest(&mut self) {
        for particle in &self.particles {
            if self.gbest.is_none() || particle.fitness < self.gbest.as_ref().unwrap().fitness {
                self.gbest = Some(particle.clone());
            }
        }
    }

    fn update_particles(&mut self) {
        for particle in &mut self.particles {
            particle.update_velocity(self.gbest.as_ref().unwrap());
            particle.update_position();
        }
    }
}

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    fitness: f64,
}

impl Particle {
    fn new(dimensions: usize, bounds: [f64; 2]) -> Particle {
        let mut rng = rand::thread_rng();
        let position = (0..dimensions).map(|_| rng.gen_range(bounds[0], bounds[1])).collect();
        let velocity = (0..dimensions).map(|_| rng.gen_range(-1.0, 1.0)).collect();
        let best_position = position.clone();
        Particle {
            position,
            velocity,
            best_position,
            fitness: f64::INFINITY,
        }
    }

    fn update_velocity(&mut self, gbest: &Particle) {
        let (w, c1, c2) = (0.5, 1.5, 1.5);
        let mut rng = rand::thread_rng();
        for i in 0..self.velocity.len() {
            let r1 = rng.gen::<f64>();
            let r2 = rng.gen::<f64>();
            let cognitive = c1 * r1 * (self.best_position[i] - self.position[i]);
            let social = c2 * r2 * (gbest.position[i] - self.position[i]);
            self.velocity[i] = w * self.velocity[i] + cognitive + social;
        }
    }

    fn update_position(&mut self) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
            if self.position[i] < self.bounds[0] {
                self.position[i] = self.bounds[0];
            }
            if self.position[i] > self.bounds[1] {
                self.position[i] = self.bounds[1];
            }
        }
    }
}

fn objective_function(x: &[f64]) -> f64 {
    x.iter().map(|&xi| xi.powi(2)).sum()
}

fn optimize(swarm: &mut Swarm, max_iterations: usize) {
    for _ in 0..max_iterations {
        swarm.update_gbest();
        for particle in &mut swarm.particles {
            particle.fitness = objective_function(&particle.position);
        }
        swarm.update_particles();
    }
}

fn main() {
    let size = 30;
    let dimensions = 2;
    let bounds = [-10.0, 10.0];
    let max_iterations = 100;
    let mut swarm = Swarm::new(size, dimensions, bounds);
    optimize(&mut swarm, max_iterations);
    println!("{:?}", swarm.gbest.as_ref().unwrap().position);
}