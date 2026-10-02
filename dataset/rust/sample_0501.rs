extern crate ndarray;
use ndarray::{Array1, Array2, arr1, arr2, random};

struct Layer {
    weights: Array2<f64>,
    bias: Array1<f64>,
}

impl Layer {
    fn new(weights: Array2<f64>, bias: Array1<f64>) -> Layer {
        Layer { weights, bias }
    }

    fn activate(&self, inputs: &Array1<f64>) -> Array1<f64> {
        self.weights.dot(inputs) + &self.bias
    }
}

struct Network {
    layers: Vec<Layer>,
}

impl Network {
    fn new(layers: Vec<Layer>) -> Network {
        Network { layers }
    }

    fn forward_pass(&self, inputs: &Array1<f64>) -> Array1<f64> {
        let mut output = inputs.clone();
        for layer in &self.layers {
            output = layer.activate(&output);
        }
        output
    }
}

fn generate_weights(size: usize) -> Array2<f64> {
    random::randn((size, size))
}

fn generate_bias(size: usize) -> Array1<f64> {
    random::randn((size,))
}

fn create_layers(num_layers: usize, layer_size: usize) -> Vec<Layer> {
    (0..num_layers)
        .map(|_| {
            let weights = generate_weights(layer_size);
            let bias = generate_bias(layer_size);
            Layer::new(weights, bias)
        })
        .collect()
}

fn main() {
    let num_layers = 5;
    let layer_size = 10;
    let layers = create_layers(num_layers, layer_size);
    let network = Network::new(layers);
    let mut inputs = random::randn((layer_size,));
    loop {
        let output = network.forward_pass(&inputs);
        inputs = output;
    }
}