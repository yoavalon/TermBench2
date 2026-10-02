extern crate rand;

use rand::Rng;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_fitness: f64,
}

impl Particle {
    fn new(dim: usize) -> Particle {
        let mut rng = rand::thread_rng();
        let position = (0..dim).map(|_| rng.gen_range(-10.0..10.0)).collect();
        let velocity = (0..dim).map(|_| rng.gen_range(-1.0..1.0)).collect();
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

    fn update_position(&mut self) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    global_best_position: Vec<f64>,
    global_best_fitness: f64,
}

impl Swarm {
    fn new(dim: usize, num_particles: usize) -> Swarm {
        let particles = (0..num_particles).map(|_| Particle::new(dim)).collect();
        let global_best_position = vec![f64::INFINITY; dim];
        let global_best_fitness = f64::INFINITY;
        Swarm {
            particles,
            global_best_position,
            global_best_fitness,
        }
    }

    fn update_global_best(&mut self) {
        for particle in &mut self.particles {
            let fitness = self.evaluate(&particle.position);
            if fitness < particle.best_fitness {
                particle.best_fitness = fitness;
                particle.best_position = particle.position.clone();
            }
            if fitness < self.global_best_fitness {
                self.global_best_fitness = fitness;
                self.global_best_position = particle.position.clone();
            }
        }
    }

    fn evaluate(&self, position: &[f64]) -> f64 {
        position.iter().map(|&x| x * x).sum()
    }

    fn iterate(&mut self) {
        self.update_global_best();
        for particle in &mut self.particles {
            particle.update_velocity(&self.global_best_position, 0.5, 1.5, 1.5);
            particle.update_position();
        }
    }
}

fn main() {
    let dim = 2;
    let num_particles = 10;
    let mut swarm = Swarm::new(dim, num_particles);
    loop {
        swarm.iterate();
    }
}