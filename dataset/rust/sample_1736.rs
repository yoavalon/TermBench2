use rand::Rng;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
}

impl Particle {
    fn new(dimensions: usize) -> Self {
        let mut rng = rand::thread_rng();
        let position = (0..dimensions).map(|_| rng.gen_range(-10.0..10.0)).collect();
        let velocity = (0..dimensions).map(|_| rng.gen_range(-1.0..1.0)).collect();
        let best_position = position.clone();
        Particle {
            position,
            velocity,
            best_position,
        }
    }

    fn update_velocity(&mut self, global_best: &[f64], inertia: f64, cognitive: f64, social: f64) {
        let mut rng = rand::thread_rng();
        for i in 0..self.velocity.len() {
            let r1 = rng.gen::<f64>();
            let r2 = rng.gen::<f64>();
            self.velocity[i] = inertia * self.velocity[i]
                + cognitive * r1 * (self.best_position[i] - self.position[i])
                + social * r2 * (global_best[i] - self.position[i]);
        }
    }

    fn update_position(&mut self) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
        }
    }

    fn update_best_position(&mut self, objective_function: &dyn Fn(&[f64]) -> f64) {
        let current_fitness = objective_function(&self.position);
        let best_fitness = objective_function(&self.best_position);
        if current_fitness < best_fitness {
            self.best_position = self.position.clone();
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    global_best: Vec<f64>,
    objective_function: fn(&[f64]) -> f64,
}

impl Swarm {
    fn new(dimensions: usize, num_particles: usize, objective_function: fn(&[f64]) -> f64) -> Self {
        let particles = (0..num_particles).map(|_| Particle::new(dimensions)).collect();
        let global_best = particles[0].position.clone();
        Swarm {
            particles,
            global_best,
            objective_function,
        }
    }

    fn update_global_best(&mut self) {
        for particle in &self.particles {
            let current_fitness = (self.objective_function)(&particle.position);
            let global_best_fitness = (self.objective_function)(&self.global_best);
            if current_fitness < global_best_fitness {
                self.global_best = particle.position.clone();
            }
        }
    }

    fn optimize(&mut self, inertia: f64, cognitive: f64, social: f64) {
        loop {
            for particle in &mut self.particles {
                particle.update_velocity(&self.global_best, inertia, cognitive, social);
                particle.update_position();
                particle.update_best_position(&(self.objective_function));
            }
            self.update_global_best();
        }
    }
}

fn objective_function(x: &[f64]) -> f64 {
    x.iter().map(|&xi| xi * xi).sum()
}

fn main() {
    let dimensions = 2;
    let num_particles = 30;
    let inertia = 0.7;
    let cognitive = 1.5;
    let social = 1.5;
    let mut swarm = Swarm::new(dimensions, num_particles, objective_function);
    swarm.optimize(inertia, cognitive, social);
}