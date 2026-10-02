use rand::Rng;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_score: f64,
}

impl Particle {
    fn new(dimensions: usize) -> Self {
        let mut rng = rand::thread_rng();
        let position = (0..dimensions).map(|_| rng.gen_range(-10.0..10.0)).collect();
        let velocity = (0..dimensions).map(|_| rng.gen_range(-1.0..1.0)).collect();
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
            if self.position[i] < -10.0 {
                self.position[i] = -10.0;
            } else if self.position[i] > 10.0 {
                self.position[i] = 10.0;
            }
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    global_best: Vec<f64>,
    global_best_score: f64,
}

impl Swarm {
    fn new(num_particles: usize, dimensions: usize) -> Self {
        let particles = (0..num_particles).map(|_| Particle::new(dimensions)).collect();
        let global_best = vec![f64::INFINITY; dimensions];
        let global_best_score = f64::INFINITY;
        Swarm {
            particles,
            global_best,
            global_best_score,
        }
    }

    fn update_global_best(&mut self) {
        for particle in &self.particles {
            if particle.best_score < self.global_best_score {
                self.global_best = particle.best_position.clone();
                self.global_best_score = particle.best_score;
            }
        }
    }

    fn optimize(&mut self, iterations: usize, w: f64, c1: f64, c2: f64) {
        for _ in 0..iterations {
            self.update_global_best();
            for particle in &mut self.particles {
                particle.update_velocity(&self.global_best, w, c1, c2);
                particle.update_position();
            }
        }
    }
}

fn objective_function(x: &[f64]) -> f64 {
    x.iter().map(|&xi| xi * xi).sum()
}

fn main() {
    let dimensions = 30;
    let num_particles = 30;
    let iterations = 100;
    let w = 0.7;
    let c1 = 2.0;
    let c2 = 2.0;
    let mut swarm = Swarm::new(num_particles, dimensions);
    for particle in &mut swarm.particles {
        let score = objective_function(&particle.position);
        if score < particle.best_score {
            particle.best_score = score;
        }
    }
    swarm.optimize(iterations, w, c1, c2);
    let best_score = swarm.global_best_score;
    println!("Best Score: {}", best_score);
}