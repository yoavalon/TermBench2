use rand::Rng;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_fitness: f64,
}

impl Particle {
    fn new(dimensions: usize, lower_bound: f64, upper_bound: f64) -> Self {
        let mut rng = rand::thread_rng();
        let position = (0..dimensions)
            .map(|_| rng.gen_range(lower_bound..upper_bound))
            .collect();
        let velocity = (0..dimensions)
            .map(|_| rng.gen_range(-1.0..1.0))
            .collect();
        let best_position = position.clone();
        let best_fitness = f64::INFINITY;
        Particle {
            position,
            velocity,
            best_position,
            best_fitness,
        }
    }

    fn update_velocity(&mut self, global_best_position: &[f64], w: f64, c1: f64, c2: f64) {
        let mut rng = rand::thread_rng();
        for i in 0..self.position.len() {
            let r1 = rng.gen::<f64>();
            let r2 = rng.gen::<f64>();
            let cognitive_velocity = c1 * r1 * (self.best_position[i] - self.position[i]);
            let social_velocity = c2 * r2 * (global_best_position[i] - self.position[i]);
            self.velocity[i] = w * self.velocity[i] + cognitive_velocity + social_velocity;
        }
    }

    fn update_position(&mut self, lower_bound: f64, upper_bound: f64) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
            self.position[i] = self.position[i].max(lower_bound).min(upper_bound);
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    global_best_position: Vec<f64>,
    global_best_fitness: f64,
}

impl Swarm {
    fn new(num_particles: usize, dimensions: usize, lower_bound: f64, upper_bound: f64) -> Self {
        let particles = (0..num_particles)
            .map(|_| Particle::new(dimensions, lower_bound, upper_bound))
            .collect();
        let global_best_position = (0..dimensions)
            .map(|_| rand::thread_rng().gen_range(lower_bound..upper_bound))
            .collect();
        let global_best_fitness = f64::INFINITY;
        Swarm {
            particles,
            global_best_position,
            global_best_fitness,
        }
    }

    fn evaluate_fitness(&mut self, objective_function: &dyn Fn(&[f64]) -> f64) {
        for particle in &mut self.particles {
            let fitness = objective_function(&particle.position);
            if fitness < particle.best_fitness {
                particle.best_fitness = fitness;
                particle.best_position = particle.position.clone();
            }
            if fitness < self.global_best_fitness {
                self.global_best_fitness = fitness;
                self.global_best_position = particle.position.clone();
            }
        }
    }

    fn update_particles(&mut self, w: f64, c1: f64, c2: f64) {
        for particle in &mut self.particles {
            particle.update_velocity(&self.global_best_position, w, c1, c2);
            particle.update_position(-10.0, 10.0);
        }
    }
}

fn objective_function(x: &[f64]) -> f64 {
    x.iter()
        .enumerate()
        .map(|(i, &xi)| (xi.sin() * (xi + (i as f64 + 1.0) * std::f64::consts::PI / x.len() as f64).sin()))
        .sum()
}

fn main() {
    let num_particles = 30;
    let dimensions = 30;
    let lower_bound = -10.0;
    let upper_bound = 10.0;
    let w = 0.729;
    let c1 = 1.494;
    let c2 = 1.494;
    let mut swarm = Swarm::new(num_particles, dimensions, lower_bound, upper_bound);
    loop {
        swarm.evaluate_fitness(&objective_function);
        swarm.update_particles(w, c1, c2);
    }
}