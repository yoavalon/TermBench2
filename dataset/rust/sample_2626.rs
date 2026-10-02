use rand::prelude::*;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_score: f64,
}

impl Particle {
    fn new(dimensions: usize, position: Option<Vec<f64>>) -> Particle {
        let position = position.unwrap_or_else(|| (0..dimensions).map(|_| rand::random::<f64>() * 2.0 - 1.0).collect());
        Particle {
            position,
            velocity: (0..dimensions).map(|_| rand::random::<f64>() * 2.0 - 1.0).collect(),
            best_position: position.clone(),
            best_score: f64::INFINITY,
        }
    }

    fn update_velocity(&mut self, global_best: &[f64], w: f64, c1: f64, c2: f64) {
        for i in 0..self.position.len() {
            let r1 = random::<f64>();
            let r2 = random::<f64>();
            let cognitive = c1 * r1 * (self.best_position[i] - self.position[i]);
            let social = c2 * r2 * (global_best[i] - self.position[i]);
            self.velocity[i] = w * self.velocity[i] + cognitive + social;
        }
    }

    fn update_position(&mut self, bounds: Option<(f64, f64)>) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
            if let Some((low, high)) = bounds {
                self.position[i] = self.position[i].clamp(low, high);
            }
        }
    }

    fn evaluate(&mut self, function: &dyn Fn(&[f64]) -> f64) {
        let current_score = function(&self.position);
        if current_score < self.best_score {
            self.best_score = current_score;
            self.best_position = self.position.clone();
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    global_best: Option<Vec<f64>>,
    global_best_score: f64,
    bounds: Option<(f64, f64)>,
}

impl Swarm {
    fn new(dimensions: usize, num_particles: usize, bounds: Option<(f64, f64)>) -> Swarm {
        Swarm {
            particles: (0..num_particles).map(|_| Particle::new(dimensions, None)).collect(),
            global_best: None,
            global_best_score: f64::INFINITY,
            bounds,
        }
    }

    fn update_global_best(&mut self) {
        for particle in &self.particles {
            if particle.best_score < self.global_best_score {
                self.global_best_score = particle.best_score;
                self.global_best = Some(particle.best_position.clone());
            }
        }
    }

    fn optimize(&mut self, function: &dyn Fn(&[f64]) -> f64, iterations: usize) {
        for _ in 0..iterations {
            self.update_global_best();
            for particle in &mut self.particles {
                if let Some(ref global_best) = self.global_best {
                    particle.update_velocity(global_best, 0.7, 1.5, 1.5);
                }
                particle.update_position(self.bounds);
                particle.evaluate(function);
            }
        }
    }
}

fn objective_function(x: &[f64]) -> f64 {
    x.iter().map(|&xi| xi * xi).sum()
}

fn main() {
    let dimensions = 2;
    let num_particles = 30;
    let bounds = Some((-10.0, 10.0));
    let iterations = 100;
    let mut swarm = Swarm::new(dimensions, num_particles, bounds);
    swarm.optimize(&objective_function, iterations);
    if let Some(global_best) = swarm.global_best {
        println!("Global Best Position: {:?}", global_best);
    }
    println!("Global Best Score: {}", swarm.global_best_score);
}