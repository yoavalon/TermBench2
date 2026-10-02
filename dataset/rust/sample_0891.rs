use rand::Rng;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_fitness: f64,
}

impl Particle {
    fn new(dimensions: usize) -> Self {
        let mut rng = rand::thread_rng();
        let position = (0..dimensions).map(|_| rng.gen_range(-10.0..10.0)).collect();
        let velocity = (0..dimensions).map(|_| rng.gen_range(-1.0..1.0)).collect();
        let best_position = position.clone();
        let best_fitness = f64::INFINITY;
        Particle {
            position,
            velocity,
            best_position,
            best_fitness,
        }
    }

    fn update_velocity(&mut self, global_best: &Vec<f64>, w: f64, c1: f64, c2: f64) {
        let mut rng = rand::thread_rng();
        for i in 0..self.velocity.len() {
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

    fn evaluate_fitness(&mut self, fitness_function: fn(&Vec<f64>) -> f64) {
        self.best_fitness = fitness_function(&self.position);
        if self.best_fitness < fitness_function(&self.best_position) {
            self.best_position = self.position.clone();
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    global_best_position: Option<Vec<f64>>,
    global_best_fitness: f64,
}

impl Swarm {
    fn new(dimensions: usize, num_particles: usize) -> Self {
        let particles = (0..num_particles).map(|_| Particle::new(dimensions)).collect();
        let global_best_fitness = f64::INFINITY;
        Swarm {
            particles,
            global_best_position: None,
            global_best_fitness,
        }
    }

    fn update_global_best(&mut self, fitness_function: fn(&Vec<f64>) -> f64) {
        for particle in &mut self.particles {
            particle.evaluate_fitness(fitness_function);
            if particle.best_fitness < self.global_best_fitness {
                self.global_best_fitness = particle.best_fitness;
                self.global_best_position = Some(particle.best_position.clone());
            }
        }
    }

    fn optimize(&mut self, fitness_function: fn(&Vec<f64>) -> f64, w: f64, c1: f64, c2: f64, iterations: usize) {
        for _ in 0..iterations {
            self.update_global_best(fitness_function);
            for particle in &mut self.particles {
                particle.update_velocity(self.global_best_position.as_ref().unwrap(), w, c1, c2);
                particle.update_position();
            }
        }
    }
}

fn sphere_function(x: &Vec<f64>) -> f64 {
    x.iter().map(|&xi| xi.powi(2)).sum()
}

fn main() {
    let dimensions = 3;
    let num_particles = 10;
    let w = 0.7;
    let c1 = 1.5;
    let c2 = 1.5;
    let iterations = 100;
    let mut swarm = Swarm::new(dimensions, num_particles);
    swarm.optimize(sphere_function, w, c1, c2, iterations);
    println!("Global Best Position: {:?}", swarm.global_best_position.unwrap());
    println!("Global Best Fitness: {}", swarm.global_best_fitness);
}