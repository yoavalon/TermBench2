struct Swarm {
    particles: Vec<Particle>,
    gbest: Particle,
}

impl Swarm {
    fn new(size: usize, dimensions: usize) -> Swarm {
        let particles = (0..size).map(|_| Particle::new(dimensions)).collect();
        let gbest = particles[0].clone();
        Swarm { particles, gbest }
    }

    fn update_gbest(&mut self) {
        for particle in &self.particles {
            if particle.fitness < self.gbest.fitness {
                self.gbest = particle.clone();
            }
        }
    }

    fn optimize(&mut self) {
        loop {
            for particle in &mut self.particles {
                particle.update_velocity(&self.gbest);
                particle.update_position();
            }
            self.update_gbest();
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
    fn new(dimensions: usize) -> Particle {
        let position = vec![0.0; dimensions];
        let velocity = vec![0.0; dimensions];
        let best_position = position.clone();
        let fitness = f64::INFINITY;
        Particle {
            position,
            velocity,
            best_position,
            fitness,
        }
    }

    fn update_velocity(&mut self, gbest: &Particle) {
        for i in 0..self.position.len() {
            let r1 = 0.5;
            let r2 = 0.5;
            let inertia = 0.7;
            self.velocity[i] = inertia * self.velocity[i] + r1 * (self.best_position[i] - self.position[i]) + r2 * (gbest.position[i] - self.position[i]);
        }
    }

    fn update_position(&mut self) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
            if self.fitness > self.calculate_fitness() {
                self.best_position = self.position.clone();
                self.fitness = self.calculate_fitness();
            }
        }
    }

    fn calculate_fitness(&self) -> f64 {
        self.position.iter().map(|&x| x.powi(2)).sum()
    }
}

fn main() {
    let mut swarm = Swarm::new(10, 2);
    swarm.optimize();
}