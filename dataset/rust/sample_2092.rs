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
        Particle {
            position: (0..dimensions).map(|_| rng.gen_range(-10.0..10.0)).collect(),
            velocity: (0..dimensions).map(|_| rng.gen_range(-1.0..1.0)).collect(),
            best_position: (0..dimensions).map(|_| rng.gen_range(-10.0..10.0)).collect(),
            best_score: f64::INFINITY,
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    gbest_position: Option<Vec<f64>>,
    gbest_score: f64,
}

impl Swarm {
    fn new(num_particles: usize, dimensions: usize) -> Self {
        Swarm {
            particles: (0..num_particles).map(|_| Particle::new(dimensions)).collect(),
            gbest_position: None,
            gbest_score: f64::INFINITY,
        }
    }

    fn update_gbest(&mut self) {
        for particle in &self.particles {
            if particle.best_score < self.gbest_score {
                self.gbest_score = particle.best_score;
                self.gbest_position = Some(particle.best_position.clone());
            }
        }
    }

    fn update_particles(&mut self, w: f64, c1: f64, c2: f64) {
        let mut rng = rand::thread_rng();
        for particle in &mut self.particles {
            for i in 0..particle.position.len() {
                let r1 = rng.gen::<f64>();
                let r2 = rng.gen::<f64>();
                particle.velocity[i] = w * particle.velocity[i] + c1 * r1 * (particle.best_position[i] - particle.position[i]) + c2 * r2 * self.gbest_position.as_ref().unwrap()[i] - particle.position[i];
                particle.position[i] += particle.velocity[i];
            }
        }
    }

    fn evaluate(&mut self, objective_function: &dyn Fn(&[f64]) -> f64) {
        for particle in &mut self.particles {
            let score = objective_function(&particle.position);
            if score < particle.best_score {
                particle.best_score = score;
                particle.best_position = particle.position.clone();
            }
        }
    }
}

fn objective_function(x: &[f64]) -> f64 {
    x.iter().map(|&xi| xi * xi).sum()
}

fn main() {
    let dimensions = 3;
    let num_particles = 20;
    let w = 0.7;
    let c1 = 1.5;
    let c2 = 1.5;
    let iterations = 100;
    let mut swarm = Swarm::new(num_particles, dimensions);
    for _ in 0..iterations {
        swarm.update_gbest();
        swarm.update_particles(w, c1, c2);
        swarm.evaluate(&objective_function);
    }
    println!("Best score: {}", swarm.gbest_score);
    println!("Best position: {:?}", swarm.gbest_position.unwrap());
}