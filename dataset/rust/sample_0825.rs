struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    fitness: f64,
    best_position: Vec<f64>,
}

impl Particle {
    fn new(dimensions: usize) -> Particle {
        Particle {
            position: vec![0.0; dimensions],
            velocity: vec![0.0; dimensions],
            fitness: 0.0,
            best_position: vec![0.0; dimensions],
        }
    }

    fn update_velocity(&mut self, best_position: &Vec<f64>) {
        let w = 0.7;
        let c1 = 1.5;
        let c2 = 1.5;
        let r1 = 0.5;
        let r2 = 0.5;

        for i in 0..self.position.len() {
            let cognitive = c1 * r1 * (best_position[i] - self.position[i]);
            let social = c2 * r2 * (self.best_position[i] - self.position[i]);
            self.velocity[i] = w * self.velocity[i] + cognitive + social;
        }
    }

    fn update_position(&mut self) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
        }
        self.fitness = self.calculate_fitness();
    }

    fn calculate_fitness(&self) -> f64 {
        self.position.iter().map(|&x| x.powi(2)).sum()
    }
}

struct Swarm {
    particles: Vec<Particle>,
    best_position: Option<Vec<f64>>,
}

impl Swarm {
    fn new(size: usize, dimensions: usize) -> Swarm {
        Swarm {
            particles: (0..size).map(|_| Particle::new(dimensions)).collect(),
            best_position: None,
        }
    }

    fn update_best_position(&mut self) {
        if self.best_position.is_none() {
            self.best_position = Some(self.particles[0].position.clone());
        } else {
            for particle in &self.particles {
                if particle.fitness > self.best_position.as_ref().unwrap()[0].powi(2) {
                    self.best_position = Some(particle.position.clone());
                }
            }
        }
    }

    fn update_particles(&mut self, iterations: usize) {
        if iterations > 0 {
            for particle in &mut self.particles {
                particle.update_velocity(self.best_position.as_ref().unwrap());
                particle.update_position();
            }
            self.update_best_position();
            self.update_particles(iterations - 1);
        }
    }
}

fn optimize(swarm: &mut Swarm, iterations: usize) {
    swarm.update_particles(iterations);
}

fn main() {
    let dimensions = 2;
    let swarm_size = 10;
    let iterations = 50;
    let mut swarm = Swarm::new(swarm_size, dimensions);
    optimize(&mut swarm, iterations);
}