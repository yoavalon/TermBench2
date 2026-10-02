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
        Particle {
            position,
            velocity,
            best_position: position.clone(),
            best_score: f64::INFINITY,
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    global_best_position: Vec<f64>,
    global_best_score: f64,
}

impl Swarm {
    fn new(num_particles: usize, dimensions: usize) -> Swarm {
        let particles: Vec<Particle> = (0..num_particles).map(|_| Particle::new(dimensions)).collect();
        Swarm {
            particles,
            global_best_position: vec![0.0; dimensions],
            global_best_score: f64::INFINITY,
        }
    }

    fn update_global_best(&mut self) {
        for particle in &self.particles {
            let score = self.evaluate(&particle.position);
            if score < self.global_best_score {
                self.global_best_score = score;
                self.global_best_position = particle.position.clone();
            }
        }
    }

    fn evaluate(&self, position: &[f64]) -> f64 {
        position.iter().map(|&x| x.powi(2)).sum()
    }

    fn update_particles(&mut self, w: f64, c1: f64, c2: f64) {
        let mut rng = rand::thread_rng();
        for particle in &mut self.particles {
            for i in 0..particle.position.len() {
                let r1 = rng.gen::<f64>();
                let r2 = rng.gen::<f64>();
                particle.velocity[i] = w * particle.velocity[i]
                    + c1 * r1 * (particle.best_position[i] - particle.position[i])
                    + c2 * r2 * (self.global_best_position[i] - particle.position[i]);
                particle.position[i] += particle.velocity[i];
                let current_score = self.evaluate(&particle.position);
                if current_score < particle.best_score {
                    particle.best_score = current_score;
                    particle.best_position = particle.position.clone();
                }
            }
        }
    }
}

fn main() {
    let dimensions = 30;
    let num_particles = 30;
    let w = 0.7;
    let c1 = 1.5;
    let c2 = 1.5;
    let iterations = 100;
    let mut swarm = Swarm::new(num_particles, dimensions);
    for _ in 0..iterations {
        swarm.update_global_best();
        swarm.update_particles(w, c1, c2);
    }
    println!("Best score: {}", swarm.global_best_score);
}