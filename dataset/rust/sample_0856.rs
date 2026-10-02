use rand::Rng;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_score: f64,
}

impl Particle {
    fn new(dimensions: usize, bounds: &[(f64, f64)]) -> Self {
        let mut rng = rand::thread_rng();
        let position = (0..dimensions)
            .map(|_| rng.gen_range(bounds[0].0..bounds[0].1))
            .collect();
        let velocity = (0..dimensions)
            .map(|_| rng.gen_range(-1.0..1.0))
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

    fn update_velocity(&mut self, global_best: &[f64], w: f64, c1: f64, c2: f64) {
        let mut rng = rand::thread_rng();
        for i in 0..self.velocity.len() {
            let r1 = rng.gen::<f64>();
            let r2 = rng.gen::<f64>();
            let cognitive = c1 * r1 * (self.best_position[i] - self.position[i]);
            let social = c2 * r2 * (global_best[i] - self.position[i]);
            self.velocity[i] = w * self.velocity[i] + cognitive + social;
        }
    }

    fn update_position(&mut self, bounds: &[(f64, f64)]) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
            self.position[i] = self.position[i].max(bounds[i].0).min(bounds[i].1);
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    best_position: Option<Vec<f64>>,
    best_score: f64,
    function: fn(&[f64]) -> f64,
}

impl Swarm {
    fn new(num_particles: usize, dimensions: usize, bounds: &[(f64, f64)], function: fn(&[f64]) -> f64) -> Self {
        let particles = (0..num_particles).map(|_| Particle::new(dimensions, bounds)).collect();
        let best_position = None;
        let best_score = f64::INFINITY;
        Swarm {
            particles,
            best_position,
            best_score,
            function,
        }
    }

    fn optimize(&mut self, max_iterations: usize, w: f64, c1: f64, c2: f64) {
        for _ in 0..max_iterations {
            for particle in &mut self.particles {
                let score = (self.function)(&particle.position);
                if score < particle.best_score {
                    particle.best_score = score;
                    particle.best_position = particle.position.clone();
                }
                if score < self.best_score {
                    self.best_score = score;
                    self.best_position = Some(particle.position.clone());
                }
            }
            for particle in &mut self.particles {
                if let Some(ref best_position) = self.best_position {
                    particle.update_velocity(best_position, w, c1, c2);
                    particle.update_position(&bounds);
                }
            }
        }
    }
}

fn objective_function(x: &[f64]) -> f64 {
    x.iter().map(|&xi| (xi - 2.0).powi(2)).sum()
}

fn main() {
    let dimensions = 3;
    let bounds = [(-10.0, 10.0); 3];
    let num_particles = 20;
    let max_iterations = 100;
    let w = 0.7;
    let c1 = 1.5;
    let c2 = 1.5;
    let mut swarm = Swarm::new(num_particles, dimensions, &bounds, objective_function);
    swarm.optimize(max_iterations, w, c1, c2);
    if let Some(ref best_position) = swarm.best_position {
        println!("{:?} {}", best_position, swarm.best_score);
    }
}