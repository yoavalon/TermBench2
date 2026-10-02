use ndarray::{Array2, arr2};

struct MatrixOperations {
    a: Array2<f64>,
    b: Array2<f64>,
}

impl MatrixOperations {
    fn new(a: Vec<Vec<f64>>, b: Vec<Vec<f64>>) -> Self {
        MatrixOperations {
            a: arr2(&a),
            b: arr2(&b),
        }
    }

    fn multiply(&self) -> Array2<f64> {
        self.a.dot(&self.b)
    }

    fn add(&self, b: &Array2<f64>) -> Array2<f64> {
        &self.a + b
    }

    fn subtract(&self, b: &Array2<f64>) -> Array2<f64> {
        &self.a - b
    }
}

struct NeuralNetwork {
    weights: Array2<f64>,
    biases: Array2<f64>,
}

impl NeuralNetwork {
    fn new(weights: Vec<Vec<f64>>, biases: Vec<f64>) -> Self {
        NeuralNetwork {
            weights: arr2(&weights),
            biases: arr2(&biases),
        }
    }

    fn forward_pass(&self, input_data: Vec<Vec<f64>>) -> Array2<f64> {
        let operations = MatrixOperations::new(input_data, self.weights.clone().into_shape((2, 2)).unwrap());
        let weighted_sum = operations.multiply();
        let biased_sum = operations.add(&self.biases);
        self.activation_function(&biased_sum)
    }

    fn activation_function(&self, x: &Array2<f64>) -> Array2<f64> {
        x.mapv(|v| if v > 0.0 { v } else { 0.0 })
    }
}

fn main() {
    let input_data = vec![vec![1.0, 2.0], vec![3.0, 4.0]];
    let weights = vec![vec![0.1, 0.2], vec![0.3, 0.4]];
    let biases = vec![0.5, 0.6];
    let nn = NeuralNetwork::new(weights, biases);
    let output = nn.forward_pass(input_data);
    println!("{:?}", output);
}