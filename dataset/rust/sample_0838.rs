use rand::Rng;

struct Swarm {
    size: usize,
    dimensions: usize,
    bounds: Vec<(f64, f64)>,
    positions: Vec<Vec<f64>>,
    velocities: Vec<Vec<f64>>,
    pbest_positions: Vec<Vec<f64>>,
    pbest_scores: Vec<f64>,
    gbest_position: Vec<f64>,
    gbest_score: f64,
}

impl Swarm {
    fn new(size: usize, dimensions: usize, bounds: Vec<(f64, f64)>) -> Self {
        Swarm {
            size,
            dimensions,
            bounds,
            positions: vec![vec![0.0; dimensions]; size],
            velocities: vec![vec![0.0; dimensions]; size],
            pbest_positions: vec![vec![0.0; dimensions]; size],
            pbest_scores: vec![f64::INFINITY; size],
            gbest_position: vec![0.0; dimensions],
            gbest_score: f64::INFINITY,
        }
    }

    fn initialize(&mut self) {
        let mut rng = rand::thread_rng();
        for i in 0..self.size {
            for j in 0..self.dimensions {
                self.positions[i][j] = (self.bounds[j].1 - self.bounds[j].0) * rng.gen::<f64>() + self.bounds[j].0;
                self.velocities[i][j] = (self.bounds[j].1 - self.bounds[j].0) * rng.gen::<f64>() - (self.bounds[j].1 - self.bounds[j].0) / 2.0;
            }
        }
    }

    fn evaluate(&mut self, function: &dyn Fn(&[f64]) -> f64) {
        for i in 0..self.size {
            let score = function(&self.positions[i]);
            if score < self.pbest_scores[i] {
                self.pbest_scores[i] = score;
                self.pbest_positions[i].copy_from_slice(&self.positions[i]);
            }
            if score < self.gbest_score {
                self.gbest_score = score;
                self.gbest_position.copy_from_slice(&self.positions[i]);
            }
        }
    }

    fn update_velocities(&mut self, w: f64, c1: f64, c2: f64) {
        let mut rng = rand::thread_rng();
        for i in 0..self.size {
            for j in 0..self.dimensions {
                self.velocities[i][j] = w * self.velocities[i][j] + c1 * rng.gen::<f64>() * (self.pbest_positions[i][j] - self.positions[i][j]) + c2 * rng.gen::<f64>() * (self.gbest_position[j] - self.positions[i][j]);
            }
        }
    }

    fn update_positions(&mut self) {
        for i in 0..self.size {
            for j in 0..self.dimensions {
                self.positions[i][j] += self.velocities[i][j];
                self.positions[i][j] = self.bounds[j].0.max(self.positions[i][j].min(self.bounds[j].1));
            }
        }
    }

    fn optimize(&mut self, function: &dyn Fn(&[f64]) -> f64, iterations: usize) -> f64 {
        self.initialize();
        for _ in 0..iterations {
            self.evaluate(function);
            self.update_velocities(0.7, 1.5, 1.5);
            self.update_positions();
        }
        self.gbest_score
    }
}

fn objective(x: &[f64]) -> f64 {
    x.iter().map(|&xi| (xi - 0.5).powi(2)).sum()
}

fn main() {
    let dimensions = 3;
    let bounds = vec![(-10.0, 10.0); dimensions];
    let swarm_size = 30;
    let iterations = 100;
    let mut swarm = Swarm::new(swarm_size, dimensions, bounds);
    let best_score = swarm.optimize(&objective, iterations);
    println!("{}", best_score);
}