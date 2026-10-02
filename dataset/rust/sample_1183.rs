struct Swarm {
    size: usize,
    dimensions: usize,
    positions: Vec<Vec<f64>>,
    velocities: Vec<Vec<f64>>,
    best_positions: Vec<Vec<f64>>,
    best_scores: Vec<f64>,
    global_best_position: Vec<f64>,
    global_best_score: f64,
}

impl Swarm {
    fn new(size: usize, dimensions: usize) -> Self {
        Swarm {
            size,
            dimensions,
            positions: vec![vec![0.0; dimensions]; size],
            velocities: vec![vec![0.0; dimensions]; size],
            best_positions: vec![vec![0.0; dimensions]; size],
            best_scores: vec![f64::INFINITY; size],
            global_best_position: vec![0.0; dimensions],
            global_best_score: f64::INFINITY,
        }
    }

    fn update_global_best(&mut self) {
        for i in 0..self.size {
            let score = self.evaluate(&self.best_positions[i]);
            if score < self.global_best_score {
                self.global_best_score = score;
                self.global_best_position = self.best_positions[i].clone();
            }
        }
    }

    fn evaluate(&self, position: &[f64]) -> f64 {
        position.iter().map(|&x| x.powi(2)).sum()
    }

    fn update_particles(&mut self) {
        for i in 0..self.size {
            for j in 0..self.dimensions {
                let r1 = 0.5;
                let r2 = 0.5;
                let c1 = 2.0;
                let c2 = 2.0;
                self.velocities[i][j] = 0.7 * self.velocities[i][j] + c1 * r1 * (self.best_positions[i][j] - self.positions[i][j]) + c2 * r2 * (self.global_best_position[j] - self.positions[i][j]);
                self.positions[i][j] += self.velocities[i][j];
            }
            self.best_scores[i] = self.evaluate(&self.positions[i]);
            if self.best_scores[i] < self.global_best_score {
                self.best_positions[i] = self.positions[i].clone();
            }
        }
    }

    fn iterate(&mut self) {
        self.update_global_best();
        self.update_particles();
        self.iterate();
    }
}

fn main() {
    let mut swarm = Swarm::new(30, 2);
    swarm.iterate();
}