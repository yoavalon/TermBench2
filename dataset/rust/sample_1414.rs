use rand::Rng;

struct Swarm {
    size: usize,
    dimensions: usize,
    positions: Vec<Vec<f64>>,
    velocities: Vec<Vec<f64>>,
    best_positions: Vec<Vec<f64>>,
    best_score: f64,
}

impl Swarm {
    fn new(size: usize, dimensions: usize) -> Self {
        let mut rng = rand::thread_rng();
        let positions = (0..size)
            .map(|_| (0..dimensions).map(|_| rng.gen::<f64>()).collect())
            .collect();
        let velocities = (0..size)
            .map(|_| (0..dimensions).map(|_| rng.gen::<f64>()).collect())
            .collect();
        let best_positions = positions.clone();
        let best_score = f64::INFINITY;
        Swarm {
            size,
            dimensions,
            positions,
            velocities,
            best_positions,
            best_score,
        }
    }

    fn update_personal_best(&mut self, score: f64) {
        if score < self.best_score {
            self.best_score = score;
            self.best_positions = self.positions.clone();
        }
    }

    fn update_velocity(&mut self, global_best: &[f64]) {
        let inertia = 0.5;
        let cognitive = 1.5;
        let social = 1.5;
        let mut rng = rand::thread_rng();
        for i in 0..self.size {
            for j in 0..self.dimensions {
                let r1 = rng.gen::<f64>();
                let r2 = rng.gen::<f64>();
                self.velocities[i][j] = inertia * self.velocities[i][j]
                    + cognitive * r1 * (self.best_positions[i][j] - self.positions[i][j])
                    + social * r2 * (global_best[j] - self.positions[i][j]);
            }
        }
    }

    fn update_position(&mut self) {
        for i in 0..self.size {
            for j in 0..self.dimensions {
                self.positions[i][j] += self.velocities[i][j];
            }
        }
    }
}

struct Environment {
    swarm: Swarm,
}

impl Environment {
    fn new(swarm: Swarm) -> Self {
        Environment { swarm }
    }

    fn evaluate(&self) -> Vec<f64> {
        self.swarm
            .positions
            .iter()
            .map(|position| position.iter().map(|&x| x.powi(2)).sum())
            .collect()
    }

    fn find_global_best(&self, scores: &[f64]) -> &[f64] {
        let global_best_index = scores.iter().enumerate().min_by(|a, b| a.1.partial_cmp(b.1).unwrap()).unwrap().0;
        &self.swarm.positions[global_best_index]
    }
}

fn main() {
    let swarm = Swarm::new(size: 10, dimensions: 3);
    let environment = Environment::new(swarm);
    let iterations = 50;
    for _ in 0..iterations {
        let scores = environment.evaluate();
        let global_best = environment.find_global_best(&scores);
        environment.swarm.update_personal_best(*scores.iter().min_by(|a, b| a.partial_cmp(b).unwrap()).unwrap());
        environment.swarm.update_velocity(global_best);
        environment.swarm.update_position();
    }
    println!("Best score: {}", environment.swarm.best_score);
}