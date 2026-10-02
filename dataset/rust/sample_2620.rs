struct Swarm {
    size: usize,
    dimensions: usize,
    positions: Vec<Vec<f64>>,
    velocities: Vec<Vec<f64>>,
    best_positions: Vec<Vec<f64>>,
    best_scores: Vec<f64>,
}

impl Swarm {
    fn new(size: usize, dimensions: usize) -> Swarm {
        Swarm {
            size,
            dimensions,
            positions: vec![vec![0.0; dimensions]; size],
            velocities: vec![vec![0.0; dimensions]; size],
            best_positions: vec![vec![0.0; dimensions]; size],
            best_scores: vec![f64::INFINITY; size],
        }
    }

    fn update_best_positions(&mut self, scores: &[f64]) {
        for i in 0..self.size {
            if scores[i] < self.best_scores[i] {
                self.best_scores[i] = scores[i];
                self.best_positions[i] = self.positions[i].clone();
            }
        }
    }

    fn update_velocities(&mut self, global_best_position: &[f64], w: f64, c1: f64, c2: f64) {
        for i in 0..self.size {
            for j in 0..self.dimensions {
                let r1 = 0.5;
                let r2 = 0.5;
                self.velocities[i][j] = w * self.velocities[i][j] + c1 * r1 * (self.best_positions[i][j] - self.positions[i][j]) + c2 * r2 * (global_best_position[j] - self.positions[i][j]);
            }
        }
    }

    fn update_positions(&mut self) {
        for i in 0..self.size {
            for j in 0..self.dimensions {
                self.positions[i][j] += self.velocities[i][j];
            }
        }
    }
}

fn fitness_function(position: &[f64]) -> f64 {
    position.iter().map(|&x| x.powi(2)).sum()
}

fn main() {
    let swarm_size = 30;
    let dimensions = 2;
    let max_iterations = 100;
    let mut swarm = Swarm::new(swarm_size, dimensions);
    for iteration in 0..max_iterations {
        let scores: Vec<f64> = swarm.positions.iter().map(|position| fitness_function(position)).collect();
        let global_best_index = scores.iter().enumerate().min_by(|a, b| a.1.partial_cmp(b.1).unwrap()).unwrap().0;
        let global_best_position = &swarm.positions[global_best_index];
        swarm.update_best_positions(&scores);
        swarm.update_velocities(global_best_position);
        swarm.update_positions();
    }
    let best_score = *scores.iter().min_by(|a, b| a.partial_cmp(b).unwrap()).unwrap();
    let best_position = &swarm.positions[scores.iter().enumerate().min_by(|a, b| a.1.partial_cmp(b.1).unwrap()).unwrap().0];
    println!("Best score: {}", best_score);
    println!("Best position: {:?}", best_position);
}