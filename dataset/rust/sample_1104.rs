use ndarray::prelude::*;

struct MatrixOperations {
    matrix: Array2<f64>,
}

impl MatrixOperations {
    fn new(matrix: Array2<f64>) -> Self {
        MatrixOperations { matrix }
    }

    fn multiply(&self, other_matrix: &Array2<f64>) -> Array2<f64> {
        self.matrix.dot(other_matrix)
    }

    fn add(&self, other_matrix: &Array2<f64>) -> Array2<f64> {
        &self.matrix + other_matrix
    }
}

struct NeuralNetwork {
    layers: Vec<MatrixOperations>,
}

impl NeuralNetwork {
    fn new(layers: Vec<MatrixOperations>) -> Self {
        NeuralNetwork { layers }
    }

    fn forward_pass(&self, input_data: &Array2<f64>) -> Array2<f64> {
        let mut current_data = input_data.clone();
        for layer in &self.layers {
            current_data = layer.multiply(&current_data);
        }
        current_data
    }
}

struct RecursiveProcess {
    neural_network: NeuralNetwork,
    input_data: Array2<f64>,
}

impl RecursiveProcess {
    fn new(neural_network: NeuralNetwork, input_data: Array2<f64>) -> Self {
        RecursiveProcess {
            neural_network,
            input_data,
        }
    }

    fn process(&self, current_data: &Array2<f64>) {
        let output_data = self.neural_network.forward_pass(current_data);
        self.process(&output_data);
    }
}

fn main() {
    let matrix1 = array![[0.5, 0.2], [0.3, 0.7]];
    let matrix2 = array![[0.1, 0.4], [0.9, 0.5]];
    let layers = vec![MatrixOperations::new(matrix1), MatrixOperations::new(matrix2)];
    let neural_network = NeuralNetwork::new(layers);
    let input_data = array![[1.0], [1.0]];
    let recursive_process = RecursiveProcess::new(neural_network, input_data);
    recursive_process.process(&input_data);
}