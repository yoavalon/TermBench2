use rand::Rng;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_value: f64,
}

impl Particle {
    fn new(dimensions: usize) -> Self {
        let mut rng = rand::thread_rng();
        let position = (0..dimensions).map(|_| rng.gen_range(-1.0..1.0)).collect();
        let velocity = (0..dimensions).map(|_| rng.gen_range(-1.0..1.0)).collect();
        let best_position = position.clone();
        let best_value = f64::INFINITY;
        Particle {
            position,
            velocity,
            best_position,
            best_value,
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

    fn evaluate(&mut self, objective_function: &dyn Fn(&[f64]) -> f64) {
        self.best_value = objective_function(&self.position);
        if self.best_value < self.best_value {
            self.best_position = self.position.clone();
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    global_best: Vec<f64>,
    global_best_value: f64,
}

impl Swarm {
    fn new(dimensions: usize, num_particles: usize) -> Self {
        let particles = (0..num_particles).map(|_| Particle::new(dimensions)).collect();
        let global_best = vec![f64::INFINITY; dimensions];
        let global_best_value = f64::INFINITY;
        Swarm {
            particles,
            global_best,
            global_best_value,
        }
    }

    fn update_global_best(&mut self) {
        for particle in &self.particles {
            if particle.best_value < self.global_best_value {
                self.global_best_value = particle.best_value;
                self.global_best = particle.best_position.clone();
            }
        }
    }

    fn iterate(&mut self, objective_function: &dyn Fn(&[f64]) -> f64) {
        for particle in &mut self.particles {
            particle.update_velocity(&self.global_best, 0.7, 1.5, 1.5);
            particle.update_position();
            particle.evaluate(objective_function);
        }
        self.update_global_best();
    }
}

fn objective_function(x: &[f64]) -> f64 {
    x.iter().map(|&xi| xi.powi(2)).sum()
}

fn optimize(dimensions: usize, num_particles: usize, max_iterations: usize) -> Vec<f64> {
    let mut swarm = Swarm::new(dimensions, num_particles);
    for _ in 0..max_iterations {
        swarm.iterate(&objective_function);
    }
    swarm.global_best
}

fn main() {
    let dimensions = 10;
    let num_particles = 20;
    let max_iterations = 100;
    let best_solution = optimize(dimensions, num_particles, max_iterations);
    println!("Best solution: {:?}", best_solution);
}