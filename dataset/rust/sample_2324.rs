use rand::Rng;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_fitness: f64,
}

impl Particle {
    fn new(dim: usize, lb: f64, ub: f64) -> Self {
        let mut rng = rand::thread_rng();
        let position = (0..dim).map(|_| rng.gen_range(lb..=ub)).collect();
        let velocity = (0..dim).map(|_| rng.gen_range(-1.0..=1.0)).collect();
        let best_position = position.clone();
        let best_fitness = f64::INFINITY;
        Particle {
            position,
            velocity,
            best_position,
            best_fitness,
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

    fn update_position(&mut self, lb: f64, ub: f64) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
            if self.position[i] < lb {
                self.position[i] = lb;
            }
            if self.position[i] > ub {
                self.position[i] = ub;
            }
        }
    }
}

fn fitness_function(x: &[f64]) -> f64 {
    x.iter().map(|&xi| xi.powi(2)).sum()
}

fn optimize(dim: usize, lb: f64, ub: f64, num_particles: usize, w: f64, c1: f64, c2: f64, max_iter: usize) -> (Vec<f64>, f64) {
    let mut particles: Vec<Particle> = (0..num_particles).map(|_| Particle::new(dim, lb, ub)).collect();
    let mut global_best = vec![f64::INFINITY; dim];
    let mut global_best_fitness = f64::INFINITY;

    for _ in 0..max_iter {
        for particle in &mut particles {
            let current_fitness = fitness_function(&particle.position);
            if current_fitness < particle.best_fitness {
                particle.best_fitness = current_fitness;
                particle.best_position = particle.position.clone();
            }
            if current_fitness < global_best_fitness {
                global_best_fitness = current_fitness;
                global_best = particle.position.clone();
            }
        }
        for particle in &mut particles {
            particle.update_velocity(&global_best, w, c1, c2);
            particle.update_position(lb, ub);
        }
    }
    (global_best, global_best_fitness)
}

fn main() {
    let dim = 30;
    let lb = -100.0;
    let ub = 100.0;
    let num_particles = 50;
    let w = 0.7;
    let c1 = 1.5;
    let c2 = 1.5;
    let max_iter = 10000;

    let (best_position, best_fitness) = optimize(dim, lb, ub, num_particles, w, c1, c2, max_iter);
    println!("Best position: {:?}", best_position);
    println!("Best fitness: {}", best_fitness);
}