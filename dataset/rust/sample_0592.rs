struct Swarm {
    size: usize,
    dimensions: usize,
    particles: Vec<Vec<f64>>,
    velocities: Vec<Vec<f64>>,
    best_positions: Vec<Vec<f64>>,
    best_scores: Vec<f64>,
    global_best: Vec<f64>,
    global_best_score: f64,
}

impl Swarm {
    fn new(size: usize, dimensions: usize) -> Self {
        Swarm {
            size,
            dimensions,
            particles: vec![vec![0.0; dimensions]; size],
            velocities: vec![vec![0.0; dimensions]; size],
            best_positions: vec![vec![0.0; dimensions]; size],
            best_scores: vec![f64::INFINITY; size],
            global_best: vec![0.0; dimensions],
            global_best_score: f64::INFINITY,
        }
    }

    fn update_global_best(&mut self) {
        for i in 0..self.size {
            if self.best_scores[i] < self.global_best_score {
                self.global_best_score = self.best_scores[i];
                self.global_best = self.best_positions[i].clone();
            }
        }
    }

    fn update_particles(&mut self) {
        for i in 0..self.size {
            for j in 0..self.dimensions {
                let r1 = 0.5;
                let r2 = 0.5;
                let cognitive = r1 * (self.best_positions[i][j] - self.particles[i][j]);
                let social = r2 * (self.global_best[j] - self.particles[i][j]);
                self.velocities[i][j] += cognitive + social;
                self.particles[i][j] += self.velocities[i][j];
            }
        }
    }

    fn evaluate(&mut self, objective_function: &dyn Fn(&[f64]) -> f64) {
        for i in 0..self.size {
            let score = objective_function(&self.particles[i]);
            if score < self.best_scores[i] {
                self.best_scores[i] = score;
                self.best_positions[i] = self.particles[i].clone();
            }
        }
        self.update_global_best();
    }
}

struct Optimization {
    swarm: Swarm,
    objective_function: Box<dyn Fn(&[f64]) -> f64>,
}

impl Optimization {
    fn new(swarm: Swarm, objective_function: Box<dyn Fn(&[f64]) -> f64>) -> Self {
        Optimization {
            swarm,
            objective_function,
        }
    }

    fn run(&mut self) {
        loop {
            self.swarm.update_particles();
            self.swarm.evaluate(&self.objective_function);
        }
    }
}

fn objective_function(position: &[f64]) -> f64 {
    position.iter().map(|&x| x.powi(2)).sum()
}

fn main() {
    let size = 30;
    let dimensions = 2;
    let swarm = Swarm::new(size, dimensions);
    let optimization = Optimization::new(swarm, Box::new(objective_function));
    optimization.run();
}