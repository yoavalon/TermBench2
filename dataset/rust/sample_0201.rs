use rand::Rng;
use ndarray::{Array1, Array2, arr2, arr1, linalg::dot};

struct NeuralNetwork {
    weights_input_hidden: Array2<f64>,
    weights_hidden_output: Array2<f64>,
    bias_hidden: Array1<f64>,
    bias_output: Array1<f64>,
}

impl NeuralNetwork {
    fn new(input_size: usize, hidden_size: usize, output_size: usize) -> Self {
        let weights_input_hidden = Array2::<f64>::random((input_size, hidden_size), rand::thread_rng);
        let weights_hidden_output = Array2::<f64>::random((hidden_size, output_size), rand::thread_rng);
        let bias_hidden = Array1::<f64>::random(hidden_size, rand::thread_rng);
        let bias_output = Array1::<f64>::random(output_size, rand::thread_rng);
        NeuralNetwork {
            weights_input_hidden,
            weights_hidden_output,
            bias_hidden,
            bias_output,
        }
    }

    fn sigmoid(&self, x: &Array1<f64>) -> Array1<f64> {
        x.mapv(|v| 1.0 / (1.0 + (-v).exp()))
    }

    fn forward_pass(&self, inputs: &Array2<f64>) -> Array1<f64> {
        let hidden_layer_input = dot(inputs, &self.weights_input_hidden) + &self.bias_hidden;
        let hidden_layer_output = self.sigmoid(&hidden_layer_input);
        let output_layer_input = dot(&hidden_layer_output, &self.weights_hidden_output) + &self.bias_output;
        self.sigmoid(&output_layer_input)
    }
}

struct MatrixOperations {
    data: Array2<f64>,
}

impl MatrixOperations {
    fn new(data: Array2<f64>) -> Self {
        MatrixOperations { data }
    }

    fn add_identity(&self) -> Array2<f64> {
        let identity = Array2::<f64>::eye(self.data.nrows());
        &self.data + &identity
    }

    fn multiply_scalar(&self, scalar: f64) -> Array2<f64> {
        &self.data * scalar
    }

    fn transpose(&self) -> Array2<f64> {
        self.data.t().to_owned()
    }
}

fn main() {
    rand::thread_rng().seed([0; 32]);
    let input_size = 4;
    let hidden_size = 5;
    let output_size = 3;
    let mut neural_net = NeuralNetwork::new(input_size, hidden_size, output_size);
    let matrix_ops = MatrixOperations::new(Array2::<f64>::random((input_size, input_size), rand::thread_rng));
    let modified_weights = matrix_ops.add_identity().transpose().multiply_scalar(0.5);
    neural_net.weights_input_hidden = modified_weights;
    let input_data = Array2::<f64>::random((1, input_size), rand::thread_rng);
    let output = neural_net.forward_pass(&input_data);
    println!("{:?}", output);
}