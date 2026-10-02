struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    pbest: Vec<f64>,
    pbest_value: f64,
}

impl Particle {
    fn new(dim: usize) -> Particle {
        Particle {
            position: vec![0.0; dim],
            velocity: vec![0.0; dim],
            pbest: vec![0.0; dim],
            pbest_value: f64::INFINITY,
        }
    }

    fn update_velocity(&mut self, gbest: &Vec<f64>, w: f64, c1: f64, c2: f64) {
        for i in 0..self.position.len() {
            let r1 = 0.5;
            let r2 = 0.5;
            self.velocity[i] = w * self.velocity[i] + c1 * r1 * (self.pbest[i] - self.position[i]) + c2 * r2 * (gbest[i] - self.position[i]);
        }
    }

    fn update_position(&mut self, bounds: &Vec<(f64, f64)>) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
            self.position[i] = bounds[i].0.max(self.position[i].min(bounds[i].1));
        }
    }

    fn update_pbest(&mut self, value: f64) {
        if value < self.pbest_value {
            self.pbest = self.position.clone();
            self.pbest_value = value;
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    gbest: Vec<f64>,
    gbest_value: f64,
    bounds: Vec<(f64, f64)>,
}

impl Swarm {
    fn new(num_particles: usize, dim: usize, bounds: Vec<(f64, f64)>) -> Swarm {
        Swarm {
            particles: vec![Particle::new(dim); num_particles],
            gbest: vec![0.0; dim],
            gbest_value: f64::INFINITY,
            bounds,
        }
    }

    fn update_gbest(&mut self) {
        for particle in &self.particles {
            if particle.pbest_value < self.gbest_value {
                self.gbest = particle.pbest.clone();
                self.gbest_value = particle.pbest_value;
            }
        }
    }

    fn iterate(&mut self) {
        for particle in &mut self.particles {
            particle.update_velocity(&self.gbest, 0.7, 1.5, 1.5);
            particle.update_position(&self.bounds);
            particle.update_pbest(objective_function(&particle.position));
        }
    }
}

fn objective_function(x: &Vec<f64>) -> f64 {
    x.iter().map(|&xi| xi.powi(2)).sum()
}

fn optimize(num_particles: usize, dim: usize, max_iterations: usize, bounds: Vec<(f64, f64)>) -> (Vec<f64>, f64) {
    let mut swarm = Swarm::new(num_particles, dim, bounds);
    for _ in 0..max_iterations {
        swarm.iterate();
        swarm.update_gbest();
    }
    (swarm.gbest, swarm.gbest_value)
}

fn main() {
    let num_particles = 30;
    let dim = 2;
    let max_iterations = 100;
    let bounds = vec![(-10.0, 10.0); dim];
    let (best_position, best_value) = optimize(num_particles, dim, max_iterations, bounds);
    println!("Best position: {:?}", best_position);
    println!("Best value: {}", best_value);
}