struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_score: f64,
}

impl Particle {
    fn new(dimensions: usize) -> Self {
        Particle {
            position: vec![0.0; dimensions],
            velocity: vec![0.0; dimensions],
            best_position: vec![0.0; dimensions],
            best_score: f64::INFINITY,
        }
    }

    fn update_velocity(&mut self, global_best: &[f64], w: f64, c1: f64, c2: f64) {
        for i in 0..self.position.len() {
            let r1 = 0.5;
            let r2 = 0.5;
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

    fn evaluate(&mut self, score_function: &dyn Fn(&[f64]) -> f64) {
        self.best_score = score_function(&self.position);
        if self.best_score < score_function(&self.best_position) {
            self.best_position = self.position.clone();
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    global_best: Vec<f64>,
    global_best_score: f64,
    bounds: Vec<(f64, f64)>,
    w: f64,
    c1: f64,
    c2: f64,
}

impl Swarm {
    fn new(dimensions: usize, num_particles: usize, bounds: Vec<(f64, f64)>, w: f64, c1: f64, c2: f64) -> Self {
        Swarm {
            particles: vec![Particle::new(dimensions); num_particles],
            global_best: vec![0.0; dimensions],
            global_best_score: f64::INFINITY,
            bounds,
            w,
            c1,
            c2,
        }
    }

    fn update_global_best(&mut self) {
        for particle in &self.particles {
            if particle.best_score < self.global_best_score {
                self.global_best_score = particle.best_score;
                self.global_best = particle.best_position.clone();
            }
        }
    }

    fn iterate(&mut self, score_function: &dyn Fn(&[f64]) -> f64) {
        for particle in &mut self.particles {
            particle.update_velocity(&self.global_best, self.w, self.c1, self.c2);
            particle.update_position(&self.bounds);
            particle.evaluate(score_function);
        }
        self.update_global_best();
    }
}

fn main() {
    let dimensions = 2;
    let num_particles = 10;
    let bounds = vec![(-10.0, 10.0), (-10.0, 10.0)];
    let w = 0.7;
    let c1 = 2.0;
    let c2 = 2.0;

    let score_function = |position: &[f64]| -> f64 { position.iter().map(|&x| x.powi(2)).sum() };

    let mut swarm = Swarm::new(dimensions, num_particles, bounds, w, c1, c2);
    loop {
        swarm.iterate(&score_function);
    }
}