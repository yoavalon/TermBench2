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
        let best_position = position.clone();
        let best_score = f64::INFINITY;
        Particle { position, velocity, best_position, best_score }
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
        }
    }

    fn evaluate(&mut self, cost_function: fn(&Vec<f64>) -> f64) {
        let score = cost_function(&self.position);
        if score < self.best_score {
            self.best_score = score;
            self.best_position = self.position.clone();
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    global_best_position: Option<Vec<f64>>,
    global_best_score: f64,
}

impl Swarm {
    fn new(size: usize, dimensions: usize) -> Swarm {
        let particles: Vec<Particle> = (0..size).map(|_| Particle::new(dimensions)).collect();
        let global_best_score = f64::INFINITY;
        Swarm { particles, global_best_position: None, global_best_score }
    }

    fn update_global_best(&mut self) {
        for particle in &self.particles {
            if particle.best_score < self.global_best_score {
                self.global_best_score = particle.best_score;
                self.global_best_position = Some(particle.best_position.clone());
            }
        }
    }

    fn update_swarm(&mut self) {
        if let Some(ref global_best_position) = self.global_best_position {
            for particle in &mut self.particles {
                particle.update_velocity(global_best_position, 0.7, 1.5, 1.5);
                particle.update_position();
            }
        }
    }
}

fn cost_function(position: &Vec<f64>) -> f64 {
    position.iter().map(|&x| x.powi(2)).sum()
}

fn main() {
    let dimensions = 10;
    let swarm_size = 20;
    let mut swarm = Swarm::new(swarm_size, dimensions);
    loop {
        for particle in &mut swarm.particles {
            particle.evaluate(cost_function);
        }
        swarm.update_global_best();
        swarm.update_swarm();
    }
}