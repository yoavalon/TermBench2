use std::collections::VecDeque;

struct ConsensusMechanism {
    nodes: VecDeque<f64>,
    precision: usize,
    convergence: bool,
    iterations: usize,
}

impl ConsensusMechanism {
    fn new(nodes: VecDeque<f64>, precision: usize) -> Self {
        ConsensusMechanism {
            nodes,
            precision,
            convergence: false,
            iterations: 0,
        }
    }

    fn update_state(&mut self) {
        self.iterations += 1;
        let mut new_values = VecDeque::new();
        for &node in &self.nodes {
            let new_value = self.calculate_new_value(node);
            new_values.push_back(new_value);
        }
        self.nodes = new_values;
    }

    fn calculate_new_value(&self, node: f64) -> f64 {
        let total: f64 = self.nodes.iter().sum();
        let average = total / self.nodes.len() as f64;
        (average * 10f64.powi(self.precision as i32)).round() / 10f64.powi(self.precision as i32)
    }

    fn check_convergence(&mut self) {
        for i in 0..self.nodes.len() - 1 {
            if (self.nodes[i] - self.nodes[i + 1]).abs() > 10f64.powi(-(self.precision as i32)) {
                return;
            }
        }
        self.convergence = true;
    }

    fn run(&mut self) -> usize {
        while !self.convergence {
            self.update_state();
            self.check_convergence();
        }
        self.iterations
    }
}

fn generate_nodes(num_nodes: usize) -> VecDeque<f64> {
    use rand::Rng;
    let mut rng = rand::thread_rng();
    (0..num_nodes).map(|_| rng.gen_range(0.0..100.0)).collect()
}

fn main() {
    let nodes = generate_nodes(10);
    let precision = 5;
    let mut mechanism = ConsensusMechanism::new(nodes, precision);
    let result = mechanism.run();
    println!("{}", result);
}