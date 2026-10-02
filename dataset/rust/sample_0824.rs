use rand::Rng;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_fitness: f64,
    max_velocity: f64,
}

impl Particle {
    fn new(dimensions: usize, max_velocity: f64) -> Self {
        let position = vec![0.0; dimensions];
        let velocity = vec![0.0; dimensions];
        let best_position = vec![0.0; dimensions];
        let best_fitness = f64::INFINITY;
        Particle {
            position,
            velocity,
            best_position,
            best_fitness,
            max_velocity,
        }
    }

    fn update_velocity(&mut self, global_best: &Vec<f64>, w: f64, c1: f64, c2: f64) {
        let mut rng = rand::thread_rng();
        for i in 0..self.position.len() {
            let r1 = rng.gen::<f64>();
            let r2 = rng.gen::<f64>();
            let cognitive = c1 * r1 * (self.best_position[i] - self.position[i]);
            let social = c2 * r2 * (global_best[i] - self.position[i]);
            self.velocity[i] = w * self.velocity[i] + cognitive + social;
            self.velocity[i] = self.velocity[i].max(-self.max_velocity).min(self.max_velocity);
        }
    }

    fn update_position(&mut self) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
        }
    }

    fn evaluate(&mut self, objective_function: &dyn Fn(&Vec<f64>) -> f64) {
        self.best_fitness = objective_function(&self.position);
        if self.best_fitness < self.best_fitness {
            self.best_fitness = self.best_fitness;
            self.best_position = self.position.clone();
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    global_best: Vec<f64>,
    global_best_fitness: f64,
}

impl Swarm {
    fn new(dimensions: usize, population_size: usize, max_velocity: f64) -> Self {
        let particles = vec![Particle::new(dimensions, max_velocity); population_size];
        let global_best = vec![0.0; dimensions];
        let global_best_fitness = f64::INFINITY;
        Swarm {
            particles,
            global_best,
            global_best_fitness,
        }
    }

    fn initialize_global_best(&mut self, objective_function: &dyn Fn(&Vec<f64>) -> f64) {
        for particle in &mut self.particles {
            particle.evaluate(objective_function);
            if particle.best_fitness < self.global_best_fitness {
                self.global_best_fitness = particle.best_fitness;
                self.global_best = particle.best_position.clone();
            }
        }
    }

    fn update_swarm(&mut self, w: f64, c1: f64, c2: f64, objective_function: &dyn Fn(&Vec<f64>) -> f64) {
        for particle in &mut self.particles {
            particle.update_velocity(&self.global_best, w, c1, c2);
            particle.update_position();
            particle.evaluate(objective_function);
            if particle.best_fitness < self.global_best_fitness {
                self.global_best_fitness = particle.best_fitness;
                self.global_best = particle.best_position.clone();
            }
        }
    }
}

fn objective_function(position: &Vec<f64>) -> f64 {
    position.iter().map(|&x| x.powi(2)).sum()
}

fn optimize(dimensions: usize, population_size: usize, max_velocity: f64, w: f64, c1: f64, c2: f64, max_iterations: usize) -> f64 {
    let mut swarm = Swarm::new(dimensions, population_size, max_velocity);
    swarm.initialize_global_best(&objective_function);
    for _ in 0..max_iterations {
        swarm.update_swarm(w, c1, c2, &objective_function);
    }
    swarm.global_best_fitness
}

fn main() {
    let dimensions = 2;
    let population_size = 30;
    let max_velocity = 0.1;
    let w = 0.729;
    let c1 = 1.494;
    let c2 = 1.494;
    let max_iterations = 100;
    let best_fitness = optimize(dimensions, population_size, max_velocity, w, c1, c2, max_iterations);
    println!("Best Fitness: {}", best_fitness);
}