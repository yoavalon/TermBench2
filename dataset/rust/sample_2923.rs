use rand::prelude::*;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_fitness: f64,
}

impl Particle {
    fn new(dimensions: usize) -> Self {
        let position = (0..dimensions).map(|_| rand::random::<f64>() * 2.0 - 1.0).collect();
        let velocity = (0..dimensions).map(|_| rand::random::<f64>() * 2.0 - 1.0).collect();
        Particle {
            position,
            velocity,
            best_position: position.clone(),
            best_fitness: f64::INFINITY,
        }
    }
}

struct PSO {
    dimensions: usize,
    population: Vec<Particle>,
    gbest_position: Vec<f64>,
    gbest_fitness: f64,
    omega: f64,
    phi_p: f64,
    phi_g: f64,
}

impl PSO {
    fn new(dimensions: usize, population_size: usize, omega: f64, phi_p: f64, phi_g: f64) -> Self {
        let population = (0..population_size).map(|_| Particle::new(dimensions)).collect();
        let gbest_position = vec![0.0; dimensions];
        PSO {
            dimensions,
            population,
            gbest_position,
            gbest_fitness: f64::INFINITY,
            omega,
            phi_p,
            phi_g,
        }
    }

    fn update_global_best(&mut self) {
        for particle in &mut self.population {
            let fitness = self.fitness(&particle.position);
            if fitness < particle.best_fitness {
                particle.best_fitness = fitness;
                particle.best_position = particle.position.clone();
            }
            if fitness < self.gbest_fitness {
                self.gbest_fitness = fitness;
                self.gbest_position = particle.position.clone();
            }
        }
    }

    fn update_velocity(&mut self, particle: &mut Particle) {
        for i in 0..self.dimensions {
            let r_p = rand::random::<f64>();
            let r_g = rand::random::<f64>();
            let cognitive = self.phi_p * r_p * (particle.best_position[i] - particle.position[i]);
            let social = self.phi_g * r_g * (self.gbest_position[i] - particle.position[i]);
            particle.velocity[i] = self.omega * particle.velocity[i] + cognitive + social;
        }
    }

    fn update_position(&mut self, particle: &mut Particle) {
        for i in 0..self.dimensions {
            particle.position[i] += particle.velocity[i];
        }
    }

    fn fitness(&self, position: &[f64]) -> f64 {
        position.iter().map(|&x| x.powi(2)).sum()
    }

    fn run(&mut self) {
        loop {
            self.update_global_best();
            for particle in &mut self.population {
                self.update_velocity(particle);
                self.update_position(particle);
            }
        }
    }
}

fn main() {
    let dimensions = 2;
    let population_size = 10;
    let omega = 0.7;
    let phi_p = 1.5;
    let phi_g = 1.5;
    let mut pso = PSO::new(dimensions, population_size, omega, phi_p, phi_g);
    pso.run();
}