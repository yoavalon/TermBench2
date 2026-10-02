use rand::Rng;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_pos: Vec<f64>,
    best_score: f64,
}

impl Particle {
    fn new(dim: usize, bounds: &[(f64, f64)]) -> Self {
        let position = (0..dim)
            .map(|_| rand::thread_rng().gen_range(bounds[0].0..=bounds[0].1))
            .collect();
        let velocity = (0..dim)
            .map(|_| rand::thread_rng().gen_range(-1.0..=1.0))
            .collect();
        let best_pos = position.clone();
        let best_score = f64::INFINITY;
        Particle {
            position,
            velocity,
            best_pos,
            best_score,
        }
    }

    fn update_velocity(&mut self, global_best: &[f64], w: f64, c1: f64, c2: f64) {
        for i in 0..self.position.len() {
            let r1 = rand::thread_rng().gen::<f64>();
            let r2 = rand::thread_rng().gen::<f64>();
            let cognitive = c1 * r1 * (self.best_pos[i] - self.position[i]);
            let social = c2 * r2 * (global_best[i] - self.position[i]);
            self.velocity[i] = w * self.velocity[i] + cognitive + social;
        }
    }

    fn update_position(&mut self, bounds: &[(f64, f64)]) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
            self.position[i] = self.position[i].clamp(bounds[i].0, bounds[i].1);
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    global_best: Vec<f64>,
    global_best_score: f64,
}

impl Swarm {
    fn new(dim: usize, num_particles: usize, bounds: &[(f64, f64)]) -> Self {
        let particles = (0..num_particles).map(|_| Particle::new(dim, bounds)).collect();
        let global_best = vec![f64::INFINITY; dim];
        let global_best_score = f64::INFINITY;
        Swarm {
            particles,
            global_best,
            global_best_score,
        }
    }

    fn update_global_best(&mut self) {
        for particle in &mut self.particles {
            let score = self.evaluate(&particle.position);
            if score < self.global_best_score {
                self.global_best = particle.position.clone();
                self.global_best_score = score;
                particle.best_score = score;
                particle.best_pos = particle.position.clone();
            }
        }
    }

    fn evaluate(&self, position: &[f64]) -> f64 {
        position.iter().map(|&x| x * x).sum()
    }

    fn run(&mut self, iterations: usize) {
        for _ in 0..iterations {
            for particle in &mut self.particles {
                particle.update_velocity(&self.global_best, 0.7, 1.5, 1.5);
                particle.update_position(&[(-10.0, 10.0); 3]);
            }
            self.update_global_best();
        }
    }
}

fn main() {
    let dim = 3;
    let num_particles = 20;
    let bounds = &[(-10.0, 10.0); 3];
    let mut swarm = Swarm::new(dim, num_particles, bounds);
    swarm.run(100);
    println!("Global Best Position: {:?}", swarm.global_best);
    println!("Global Best Score: {}", swarm.global_best_score);
}