use rand::Rng;

struct Swarm {
    size: usize,
    dimensions: usize,
    search_space: (f64, f64),
    particles: Vec<Particle>,
    best_position: Vec<f64>,
    best_score: f64,
}

impl Swarm {
    fn new(size: usize, dimensions: usize, search_space: (f64, f64)) -> Self {
        let particles = (0..size).map(|_| Particle::new(dimensions, search_space)).collect();
        let best_position = particles.choose(&mut rand::thread_rng()).unwrap().position.clone();
        Swarm {
            size,
            dimensions,
            search_space,
            particles,
            best_position,
            best_score: f64::INFINITY,
        }
    }

    fn update_best_position(&mut self) {
        for particle in &self.particles {
            if particle.score < self.best_score {
                self.best_score = particle.score;
                self.best_position = particle.position.clone();
            }
        }
    }

    fn iterate(&mut self) {
        for particle in &mut self.particles {
            particle.update_velocity(&self.best_position);
            particle.move_();
            particle.evaluate();
        }
    }

    fn run(&mut self, iterations: usize) {
        for _ in 0..iterations {
            self.iterate();
            self.update_best_position();
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
    fn new(dimensions: usize, search_space: (f64, f64)) -> Self {
        let position = (0..dimensions).map(|_| rand::thread_rng().gen_range(search_space)).collect();
        let velocity = vec![0.0; dimensions];
        let best_position = position.clone();
        Particle {
            position,
            velocity,
            best_position,
            best_score: f64::INFINITY,
        }
    }

    fn update_velocity(&mut self, global_best: &[f64]) {
        let inertia = 0.5;
        let cognitive_factor = 1.5;
        let social_factor = 1.5;
        for i in 0..self.position.len() {
            let r1 = rand::thread_rng().gen::<f64>();
            let r2 = rand::thread_rng().gen::<f64>();
            let cognitive = cognitive_factor * r1 * (self.best_position[i] - self.position[i]);
            let social = social_factor * r2 * (global_best[i] - self.position[i]);
            self.velocity[i] = inertia * self.velocity[i] + cognitive + social;
        }
    }

    fn move_(&mut self) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
        }
    }

    fn evaluate(&mut self) {
        self.score = self.objective_function();
        if self.score < self.best_score {
            self.best_score = self.score;
            self.best_position = self.position.clone();
        }
    }

    fn objective_function(&self) -> f64 {
        self.position.iter().map(|&x| x.powi(2)).sum()
    }
}

fn main() {
    let swarm_size = 30;
    let dimensions = 2;
    let search_space = (-10.0, 10.0);
    let iterations = 100;
    let mut swarm = Swarm::new(swarm_size, dimensions, search_space);
    swarm.run(iterations);
    println!("Best position: {:?}", swarm.best_position);
    println!("Best score: {}", swarm.best_score);
}