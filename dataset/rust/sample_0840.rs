use ndarray::{Array2, arr2, random::RandomExt};
use std::f64;

struct MatrixOp {
    data: Array2<f64>,
}

impl MatrixOp {
    fn new(data: Array2<f64>) -> Self {
        MatrixOp { data }
    }

    fn multiply(&self, other: &MatrixOp) -> MatrixOp {
        MatrixOp {
            data: self.data.dot(&other.data),
        }
    }

    fn add(&self, other: &MatrixOp) -> MatrixOp {
        MatrixOp {
            data: &self.data + &other.data,
        }
    }

    fn sigmoid(&self) -> MatrixOp {
        MatrixOp {
            data: self.data.mapv(|x| 1.0 / (1.0 + (-x).exp())),
        }
    }

    fn relu(&self) -> MatrixOp {
        MatrixOp {
            data: self.data.mapv(|x| if x > 0.0 { x } else { 0.0 }),
        }
    }
}

struct NeuralNetwork {
    layers: Vec<Layer>,
}

impl NeuralNetwork {
    fn new(layers: Vec<Layer>) -> Self {
        NeuralNetwork { layers }
    }

    fn forward_pass(&self, input_data: &MatrixOp) -> MatrixOp {
        let mut result = input_data.clone();
        for layer in &self.layers {
            result = layer.forward(&result);
        }
        result
    }
}

struct Layer {
    weights: MatrixOp,
    activation: Box<dyn Fn(&MatrixOp) -> MatrixOp>,
}

impl Layer {
    fn new(weights: Array2<f64>, activation: Box<dyn Fn(&MatrixOp) -> MatrixOp>) -> Self {
        Layer {
            weights: MatrixOp::new(weights),
            activation,
        }
    }

    fn forward(&self, input_data: &MatrixOp) -> MatrixOp {
        let weighted_input = self.weights.multiply(input_data);
        (self.activation)(&weighted_input)
    }
}

fn main() {
    let input_data = MatrixOp::new(arr2(&[
        [0.50688147],
        [0.89460183],
        [0.00011864],
    ]));
    let weights1 = arr2(&[
        [0.16893422, 0.76377462, 0.24236267],
        [0.45563673, 0.95873792, 0.07528034],
    ]);
    let weights2 = arr2(&[[0.54907353, 0.86540764]]);
    let layer1 = Layer::new(weights1, Box::new(MatrixOp::sigmoid));
    let layer2 = Layer::new(weights2, Box::new(MatrixOp::relu));
    let network = NeuralNetwork::new(vec![layer1, layer2]);
    let output = network.forward_pass(&input_data);
    println!("{:?}", output.data);
}