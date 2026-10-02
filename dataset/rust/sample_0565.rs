struct Swarm {
    size: usize,
    dimensions: usize,
    positions: Vec<Vec<f64>>,
    velocities: Vec<Vec<f64>>,
}

impl Swarm {
    fn new(size: usize, dimensions: usize) -> Swarm {
        Swarm {
            size,
            dimensions,
            positions: vec![vec![0.0; dimensions]; size],
            velocities: vec![vec![0.0; dimensions]; size],
        }
    }

    fn update_positions(&mut self) {
        for i in 0..self.size {
            for j in 0..self.dimensions {
                self.positions[i][j] += self.velocities[i][j];
            }
        }
    }

    fn update_velocities(&mut self, global_best: &[f64]) {
        for i in 0..self.size {
            for j in 0..self.dimensions {
                self.velocities[i][j] = 0.5 * self.velocities[i][j] + 1.5 * (global_best[j] - self.positions[i][j]);
            }
        }
    }
}

struct Environment {
    swarm: Swarm,
    global_best: Vec<f64>,
}

impl Environment {
    fn new(swarm: Swarm) -> Environment {
        Environment {
            swarm,
            global_best: vec![0.0; swarm.dimensions],
        }
    }

    fn evaluate(&mut self) {
        for pos in &self.swarm.positions {
            let fitness = pos.iter().sum::<f64>();
            if fitness > self.global_best.iter().sum::<f64>() {
                self.global_best = pos.clone();
            }
        }
    }

    fn run(&mut self) {
        loop {
            self.swarm.update_positions();
            self.evaluate();
            self.swarm.update_velocities(&self.global_best);
        }
    }
}

fn main() {
    let swarm = Swarm::new(10, 2);
    let mut env = Environment::new(swarm);
    env.run();
}