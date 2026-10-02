use rand::Rng;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_score: f64,
}

impl Particle {
    fn new(dimensions: usize, bounds: (f64, f64)) -> Self {
        let mut rng = rand::thread_rng();
        let position = (0..dimensions)
            .map(|_| rng.gen_range(bounds.0..=bounds.1))
            .collect();
        let velocity = (0..dimensions)
            .map(|_| rng.gen_range(-1.0..=1.0))
            .collect();
        let best_position = position.clone();
        let best_score = f64::INFINITY;
        Particle {
            position,
            velocity,
            best_position,
            best_score,
        }
    }

    fn update_velocity(&mut self, global_best: &[f64], w: f64, c1: f64, c2: f64) {
        let mut rng = rand::thread_rng();
        for i in 0..self.velocity.len() {
            let r1 = rng.gen::<f64>();
            let r2 = rng.gen::<f64>();
            self.velocity[i] = w * self.velocity[i]
                + c1 * r1 * (self.best_position[i] - self.position[i])
                + c2 * r2 * (global_best[i] - self.position[i]);
        }
    }

    fn update_position(&mut self, bounds: (f64, f64)) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
            self.position[i] = self.position[i].clamp(bounds.0, bounds.1);
        }
    }

    fn evaluate(&mut self, objective_function: &ObjectiveFunction) {
        let score = objective_function(&self.position);
        if score < self.best_score {
            self.best_score = score;
            self.best_position = self.position.clone();
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    global_best_position: Vec<f64>,
    global_best_score: f64,
}

impl Swarm {
    fn new(num_particles: usize, dimensions: usize, bounds: (f64, f64)) -> Self {
        let particles = (0..num_particles)
            .map(|_| Particle::new(dimensions, bounds))
            .collect();
        let global_best_position = particles[0].position.clone();
        let global_best_score = particles[0].best_score;
        Swarm {
            particles,
            global_best_position,
            global_best_score,
        }
    }

    fn update_global_best(&mut self) {
        for particle in &self.particles {
            if particle.best_score < self.global_best_score {
                self.global_best_score = particle.best_score;
                self.global_best_position = particle.best_position.clone();
            }
        }
    }

    fn iterate(&mut self, objective_function: &ObjectiveFunction) {
        for particle in &mut self.particles {
            particle.update_velocity(&self.global_best_position, 0.7, 1.5, 1.5);
            particle.update_position(objective_function.bounds);
            particle.evaluate(objective_function);
        }
        self.update_global_best();
    }
}

struct ObjectiveFunction {
    bounds: (f64, f64),
}

impl ObjectiveFunction {
    fn new(bounds: (f64, f64)) -> Self {
        ObjectiveFunction { bounds }
    }

    fn __call__(&self, position: &[f64]) -> f64 {
        let x = position[0];
        let y = position[1];
        (x.powi(2) + y - 11.0).powi(2) + (x + y.powi(2) - 7.0).powi(2)
    }
}

fn main() {
    let dimensions = 2;
    let num_particles = 30;
    let bounds = (-5.0, 5.0);
    let objective_function = ObjectiveFunction::new(bounds);
    let mut swarm = Swarm::new(num_particles, dimensions, bounds);
    for _ in 0..100 {
        swarm.iterate(&objective_function);
        if swarm.global_best_score < 1e-06 {
            break;
        }
    }
    println!("Best position: {:?}", swarm.global_best_position);
    println!("Best score: {}", swarm.global_best_score);
}