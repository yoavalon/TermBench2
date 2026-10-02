extern crate ndarray;
use ndarray::{Array2, arr2};

struct MatrixProcessor {
    matrix: Array2<f64>,
}

impl MatrixProcessor {
    fn new(matrix: Array2<f64>) -> Self {
        MatrixProcessor { matrix }
    }

    fn normalize(&mut self) -> &Array2<f64> {
        let max_val = self.matrix.max().unwrap();
        self.matrix /= max_val;
        &self.matrix
    }

    fn apply_activation(&mut self, activation_func: fn(&Array2<f64>) -> Array2<f64>) -> &Array2<f64> {
        self.matrix = activation_func(&self.matrix);
        &self.matrix
    }
}

struct NeuralNetwork {
    layers: Vec<Box<dyn Fn(&Array2<f64>) -> Array2<f64>>>,
}

impl NeuralNetwork {
    fn new(layers: Vec<Box<dyn Fn(&Array2<f64>) -> Array2<f64>>>) -> Self {
        NeuralNetwork { layers }
    }

    fn forward_pass(&self, input_data: &Array2<f64>) -> Array2<f64> {
        let mut output = input_data.clone();
        for layer in &self.layers {
            output = layer(&output);
        }
        output
    }
}

struct ActivationFunctions;

impl ActivationFunctions {
    fn sigmoid(x: &Array2<f64>) -> Array2<f64> {
        1.0 / (1.0 + (-x).exp())
    }

    fn relu(x: &Array2<f64>) -> Array2<f64> {
        x.mapv(|v| if v > 0.0 { v } else { 0.0 })
    }
}

fn main() {
    let data = arr2(&[
        [0.5, 0.7, 0.3, 0.4, 0.8, 0.2, 0.9, 0.1, 0.6, 0.0],
        [0.4, 0.3, 0.8, 0.1, 0.5, 0.9, 0.2, 0.6, 0.0, 0.7],
        [0.1, 0.6, 0.2, 0.9, 0.3, 0.7, 0.4, 0.8, 0.5, 0.0],
        [0.7, 0.1, 0.6, 0.2, 0.9, 0.3, 0.8, 0.4, 0.0, 0.5],
        [0.2, 0.9, 0.1, 0.5, 0.0, 0.7, 0.3, 0.6, 0.8, 0.4],
        [0.9, 0.2, 0.5, 0.0, 0.3, 0.6, 0.1, 0.7, 0.4, 0.8],
        [0.3, 0.5, 0.0, 0.7, 0.4, 0.8, 0.6, 0.1, 0.9, 0.2],
        [0.8, 0.0, 0.4, 0.6, 0.1, 0.7, 0.2, 0.9, 0.3, 0.5],
        [0.6, 0.4, 0.8, 0.0, 0.7, 0.1, 0.5, 0.2, 0.9, 0.3],
        [0.0, 0.8, 0.6, 0.4, 0.2, 0.5, 0.7, 0.3, 0.1, 0.9],
    ]);

    let mut processor = MatrixProcessor::new(data);
    let normalized_data = processor.normalize().clone();
    let relu_output = processor.apply_activation(ActivationFunctions::relu).clone();
    let sigmoid_output = processor.apply_activation(ActivationFunctions::sigmoid).clone();

    let layers: Vec<Box<dyn Fn(&Array2<f64>) -> Array2<f64>>> = vec![
        Box::new(move |x: &Array2<f64>| relu_output.clone()),
        Box::new(move |x: &Array2<f64>| sigmoid_output.clone()),
    ];

    let network = NeuralNetwork::new(layers);
    let result = network.forward_pass(&normalized_data);
    println!("{:?}", result);
}