use rand::Rng;

struct Swarm {
    size: usize,
    dimensions: usize,
    particles: Vec<Particle>,
    best_position: Option<Vec<f64>>,
    best_value: f64,
}

impl Swarm {
    fn new(size: usize, dimensions: usize) -> Swarm {
        Swarm {
            size,
            dimensions,
            particles: (0..size).map(|_| Particle::new(dimensions)).collect(),
            best_position: None,
            best_value: f64::INFINITY,
        }
    }

    fn update_best(&mut self) {
        for particle in &self.particles {
            if particle.value < self.best_value {
                self.best_value = particle.value;
                self.best_position = Some(particle.position.clone());
            }
        }
    }

    fn optimize(&mut self, iterations: usize) {
        for _ in 0..iterations {
            for particle in &mut self.particles {
                if let Some(ref best_position) = self.best_position {
                    particle.update(best_position);
                }
            }
            self.update_best();
        }
    }
}

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_value: f64,
}

impl Particle {
    fn new(dimensions: usize) -> Particle {
        let mut rng = rand::thread_rng();
        let position: Vec<f64> = (0..dimensions).map(|_| rng.gen_range(-10.0..10.0)).collect();
        let velocity: Vec<f64> = (0..dimensions).map(|_| rng.gen_range(-1.0..1.0)).collect();
        let best_position = position.clone();
        let best_value = Particle::calculate_value(&position);
        Particle {
            position,
            velocity,
            best_position,
            best_value,
        }
    }

    fn calculate_value(position: &[f64]) -> f64 {
        position.iter().map(|&x| x * x).sum()
    }

    fn update(&mut self, global_best: &[f64]) {
        let w = 0.7;
        let c1 = 1.5;
        let c2 = 1.5;
        let mut rng = rand::thread_rng();
        for i in 0..self.position.len() {
            let r1 = rng.gen();
            let r2 = rng.gen();
            self.velocity[i] = w * self.velocity[i] + c1 * r1 * (self.best_position[i] - self.position[i]) + c2 * r2 * (global_best[i] - self.position[i]);
            self.position[i] += self.velocity[i];
        }
        self.best_value = Particle::calculate_value(&self.position);
        if self.best_value < self.best_value {
            self.best_value = self.best_value;
            self.best_position = self.position.clone();
        }
    }
}

fn main() {
    let dimensions = 2;
    let swarm_size = 30;
    let iterations = 100;
    let mut swarm = Swarm::new(swarm_size, dimensions);
    swarm.optimize(iterations);
    if let Some(ref best_position) = swarm.best_position {
        println!("Best position: {:?}", best_position);
    }
    println!("Best value: {}", swarm.best_value);
}