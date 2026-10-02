use rand::Rng;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_score: f64,
}

impl Particle {
    fn new(dimensions: usize, lower_bound: f64, upper_bound: f64) -> Self {
        let mut rng = rand::thread_rng();
        let position = (0..dimensions)
            .map(|_| rng.gen_range(lower_bound..=upper_bound))
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

    fn update_velocity(&mut self, global_best_position: &Vec<f64>, w: f64, c1: f64, c2: f64) {
        let mut rng = rand::thread_rng();
        for i in 0..self.position.len() {
            let r1 = rng.gen::<f64>();
            let r2 = rng.gen::<f64>();
            self.velocity[i] =
                w * self.velocity[i] + c1 * r1 * (self.best_position[i] - self.position[i]) + c2 * r2 * (global_best_position[i] - self.position[i]);
        }
    }

    fn update_position(&mut self) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
        }
    }

    fn evaluate(&mut self, fitness_function: &dyn Fn(&Vec<f64>) -> f64) {
        let score = fitness_function(&self.position);
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
    fn new(size: usize, dimensions: usize, lower_bound: f64, upper_bound: f64) -> Self {
        let particles = (0..size)
            .map(|_| Particle::new(dimensions, lower_bound, upper_bound))
            .collect();
        let mut rng = rand::thread_rng();
        let global_best_position = (0..dimensions)
            .map(|_| rng.gen_range(lower_bound..=upper_bound))
            .collect();
        let global_best_score = f64::INFINITY;
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

    fn iterate(&mut self, fitness_function: &dyn Fn(&Vec<f64>) -> f64, w: f64, c1: f64, c2: f64) {
        for particle in &mut self.particles {
            particle.update_velocity(&self.global_best_position, w, c1, c2);
            particle.update_position();
            particle.evaluate(fitness_function);
        }
        self.update_global_best();
    }
}

fn fitness_function(position: &Vec<f64>) -> f64 {
    position.iter().map(|&x| x.powi(2)).sum()
}

fn main() {
    let dimensions = 2;
    let lower_bound = -10.0;
    let upper_bound = 10.0;
    let swarm_size = 30;
    let w = 0.7;
    let c1 = 1.5;
    let c2 = 1.5;
    let iterations = 100;
    let mut swarm = Swarm::new(swarm_size, dimensions, lower_bound, upper_bound);
    for _ in 0..iterations {
        swarm.iterate(&fitness_function, w, c1, c2);
    }
    println!("Global best score: {}", swarm.global_best_score);
    println!("Global best position: {:?}", swarm.global_best_position);
}