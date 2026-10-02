use rand::prelude::*;

struct Swarm {
    size: usize,
    dimensions: usize,
    particles: Vec<Particle>,
    global_best: Option<Particle>,
}

impl Swarm {
    fn new(size: usize, dimensions: usize) -> Self {
        let particles = (0..size).map(|_| Particle::new(dimensions)).collect();
        Swarm {
            size,
            dimensions,
            particles,
            global_best: None,
        }
    }

    fn update_global_best(&mut self) {
        for particle in &self.particles {
            if self.global_best.is_none() || particle.best_score < self.global_best.as_ref().unwrap().best_score {
                self.global_best = Some(particle.clone());
            }
        }
    }

    fn update_particles(&mut self) {
        for particle in &mut self.particles {
            particle.update_velocity(self.global_best.as_ref().unwrap());
            particle.update_position();
        }
    }
}

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_score: f64,
}

impl Particle {
    fn new(dimensions: usize) -> Self {
        let position = (0..dimensions).map(|_| rand::thread_rng().gen_range(-10.0..10.0)).collect();
        let velocity = (0..dimensions).map(|_| rand::thread_rng().gen_range(-1.0..1.0)).collect();
        let best_position = position.clone();
        let best_score = f64::INFINITY;
        Particle {
            position,
            velocity,
            best_position,
            best_score,
        }
    }

    fn update_velocity(&mut self, global_best: &Particle) {
        let w = 0.729;
        let c1 = 1.494;
        let c2 = 1.494;
        for i in 0..self.velocity.len() {
            let r1: f64 = random();
            let r2: f64 = random();
            let cognitive = c1 * r1 * (self.best_position[i] - self.position[i]);
            let social = c2 * r2 * (global_best.best_position[i] - self.position[i]);
            self.velocity[i] = w * self.velocity[i] + cognitive + social;
        }
    }

    fn update_position(&mut self) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
            self.position[i] = self.position[i].max(-10.0).min(10.0);
        }
    }

    fn evaluate(&mut self, objective_function: &dyn Fn(&[f64]) -> f64) {
        self.best_score = objective_function(&self.position);
        if self.best_score < self.best_score {
            self.best_position = self.position.clone();
        }
    }
}

fn objective_function(x: &[f64]) -> f64 {
    x.iter().map(|&xi| xi * xi).sum()
}

fn main() {
    let swarm_size = 30;
    let dimensions = 2;
    let mut swarm = Swarm::new(swarm_size, dimensions);
    for _ in 0..100 {
        swarm.update_global_best();
        for particle in &mut swarm.particles {
            particle.evaluate(&objective_function);
        }
        swarm.update_particles();
    }
    if let Some(global_best) = &swarm.global_best {
        println!("{} {:?}", global_best.best_score, global_best.best_position);
    }
}