extern crate rand;
extern crate ndarray;

use rand::Rng;
use ndarray::{Array2, arr2, linalg::dot};

struct MatrixOperations {
    size: usize,
    matrix_a: Array2<f64>,
    matrix_b: Array2<f64>,
}

impl MatrixOperations {
    fn new(size: usize) -> Self {
        let mut rng = rand::thread_rng();
        let matrix_a = Array2::from_shape_fn((size, size), |_| rng.gen::<f64>());
        let matrix_b = Array2::from_shape_fn((size, size), |_| rng.gen::<f64>());
        MatrixOperations { size, matrix_a, matrix_b }
    }

    fn multiply(&self) -> Array2<f64> {
        dot(&self.matrix_a, &self.matrix_b)
    }

    fn add(&self, matrix: &Array2<f64>) -> Array2<f64> {
        &self.matrix_a + matrix
    }
}

struct NeuralNetwork {
    matrix_ops: MatrixOperations,
    weights: Array2<f64>,
}

impl NeuralNetwork {
    fn new(matrix_ops: MatrixOperations) -> Self {
        let weights = matrix_ops.multiply();
        NeuralNetwork { matrix_ops, weights }
    }

    fn forward_pass(&self) -> Array2<f64> {
        let result = self.matrix_ops.add(&self.weights);
        result.mapv(|x| x.tanh())
    }
}

struct Simulation {
    neural_network: NeuralNetwork,
}

impl Simulation {
    fn new(neural_network: NeuralNetwork) -> Self {
        Simulation { neural_network }
    }

    fn run(&self) {
        loop {
            let output = self.neural_network.forward_pass();
            println!("{:?}", output);
        }
    }
}

fn main() {
    let size = 10;
    let matrix_ops = MatrixOperations::new(size);
    let neural_network = NeuralNetwork::new(matrix_ops);
    let simulation = Simulation::new(neural_network);
    simulation.run();
}