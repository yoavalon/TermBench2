use rand::Rng;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_pos: Vec<f64>,
    best_score: f64,
}

impl Particle {
    fn new(dim: usize) -> Self {
        Particle {
            position: vec![0.0; dim],
            velocity: vec![0.0; dim],
            best_pos: vec![0.0; dim],
            best_score: f64::INFINITY,
        }
    }

    fn update_velocity(&mut self, global_best: &[f64], w: f64, c1: f64, c2: f64) {
        let mut rng = rand::thread_rng();
        for i in 0..self.position.len() {
            let r1 = rng.gen::<f64>();
            let r2 = rng.gen::<f64>();
            self.velocity[i] = w * self.velocity[i] + c1 * r1 * (self.best_pos[i] - self.position[i]) + c2 * r2 * (global_best[i] - self.position[i]);
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
    best_global_pos: Vec<f64>,
    best_global_score: f64,
}

impl Swarm {
    fn new(num_particles: usize, dim: usize, bounds: &[(f64, f64)]) -> Self {
        Swarm {
            particles: vec![Particle::new(dim); num_particles],
            best_global_pos: vec![0.0; dim],
            best_global_score: f64::INFINITY,
        }
    }

    fn update_global_best(&mut self) {
        for particle in &self.particles {
            if particle.best_score < self.best_global_score {
                self.best_global_score = particle.best_score;
                self.best_global_pos.copy_from_slice(&particle.best_pos);
            }
        }
    }

    fn optimize(&mut self, fitness_func: fn(&[f64]) -> f64, max_iter: usize, w: f64, c1: f64, c2: f64, bounds: &[(f64, f64)]) {
        for _ in 0..max_iter {
            for particle in &mut self.particles {
                particle.update_velocity(&self.best_global_pos, w, c1, c2);
                particle.update_position(bounds);
                let score = fitness_func(&particle.position);
                if score < particle.best_score {
                    particle.best_score = score;
                    particle.best_pos.copy_from_slice(&particle.position);
                }
            }
            self.update_global_best();
        }
    }
}

fn fitness_function(position: &[f64]) -> f64 {
    position.iter().map(|&x| x * x).sum()
}

fn main() {
    let num_particles = 30;
    let dim = 2;
    let bounds = vec![(0.0, 10.0); dim];
    let max_iter = 100;
    let w = 0.7;
    let c1 = 2.0;
    let c2 = 2.0;
    let mut swarm = Swarm::new(num_particles, dim, &bounds);
    swarm.optimize(fitness_function, max_iter, w, c1, c2, &bounds);
    println!("{:?} {:?}", swarm.best_global_pos, swarm.best_global_score);
}