use rand::Rng;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_score: f64,
}

impl Particle {
    fn new(dimensions: usize) -> Particle {
        let mut rng = rand::thread_rng();
        let position: Vec<f64> = (0..dimensions).map(|_| rng.gen_range(-10.0..10.0)).collect();
        let velocity: Vec<f64> = (0..dimensions).map(|_| rng.gen_range(-1.0..1.0)).collect();
        Particle {
            position,
            velocity,
            best_position: position.clone(),
            best_score: f64::INFINITY,
        }
    }

    fn update_velocity(&mut self, global_best_position: &Vec<f64>, w: f64, c1: f64, c2: f64) {
        let mut rng = rand::thread_rng();
        for i in 0..self.velocity.len() {
            let r1 = rng.gen::<f64>();
            let r2 = rng.gen::<f64>();
            let cognitive = c1 * r1 * (self.best_position[i] - self.position[i]);
            let social = c2 * r2 * (global_best_position[i] - self.position[i]);
            self.velocity[i] = w * self.velocity[i] + cognitive + social;
        }
    }

    fn update_position(&mut self) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
            if self.position[i] < -10.0 {
                self.position[i] = -10.0;
            } else if self.position[i] > 10.0 {
                self.position[i] = 10.0;
            }
        }
    }

    fn evaluate(&mut self, objective_function: &dyn Fn(&Vec<f64>) -> f64) {
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
    fn new(num_particles: usize, dimensions: usize) -> Swarm {
        let mut rng = rand::thread_rng();
        let global_best_position: Vec<f64> = (0..dimensions).map(|_| rng.gen_range(-10.0..10.0)).collect();
        Swarm {
            particles: (0..num_particles).map(|_| Particle::new(dimensions)).collect(),
            global_best_position,
            global_best_score: f64::INFINITY,
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

    fn optimize(&mut self, objective_function: &dyn Fn(&Vec<f64>) -> f64, w: f64, c1: f64, c2: f64, iterations: usize) {
        for _ in 0..iterations {
            for particle in &mut self.particles {
                particle.update_velocity(&self.global_best_position, w, c1, c2);
                particle.update_position();
                particle.evaluate(objective_function);
            }
            self.update_global_best();
        }
    }
}

fn objective_function(x: &Vec<f64>) -> f64 {
    x.iter().map(|&xi| xi.powi(2)).sum()
}

fn main() {
    let dimensions = 3;
    let num_particles = 10;
    let w = 0.7;
    let c1 = 1.5;
    let c2 = 1.5;
    let iterations = 50;
    let mut swarm = Swarm::new(num_particles, dimensions);
    swarm.optimize(&objective_function, w, c1, c2, iterations);
    println!("Best position: {:?}", swarm.global_best_position);
    println!("Best score: {}", swarm.global_best_score);
}