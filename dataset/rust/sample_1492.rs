use rand::Rng;
use ndarray::{Array, Array2, arr2, arr1};

struct MatrixLayer {
    weights: Array2<f64>,
    bias: Array1<f64>,
}

impl MatrixLayer {
    fn forward(&self, x: &Array2<f64>) -> Array2<f64> {
        x.dot(&self.weights) + &self.bias
    }
}

struct NeuralNetwork {
    layers: Vec<MatrixLayer>,
}

impl NeuralNetwork {
    fn predict(&self, mut x: Array2<f64>) -> Array2<f64> {
        for layer in &self.layers {
            x = layer.forward(&x);
        }
        x
    }
}

fn initialize_weights(input_size: usize, hidden_size: usize, output_size: usize) -> (MatrixLayer, MatrixLayer) {
    let mut rng = rand::thread_rng();
    let weights1: Array2<f64> = Array::from_shape_fn((input_size, hidden_size), |_| rng.gen::<f64>());
    let bias1: Array1<f64> = Array::from_shape_fn(hidden_size, |_| rng.gen::<f64>());
    let weights2: Array2<f64> = Array::from_shape_fn((hidden_size, output_size), |_| rng.gen::<f64>());
    let bias2: Array1<f64> = Array::from_shape_fn(output_size, |_| rng.gen::<f64>());
    (MatrixLayer { weights: weights1, bias: bias1 }, MatrixLayer { weights: weights2, bias: bias2 })
}

fn main() {
    let input_size = 784;
    let hidden_size = 128;
    let output_size = 10;
    let (layer1, layer2) = initialize_weights(input_size, hidden_size, output_size);
    let model = NeuralNetwork { layers: vec![layer1, layer2] };
    let input_data: Array2<f64> = Array::from_shape_fn((1, input_size), |_| rand::thread_rng().gen::<f64>());
    let output = model.predict(input_data);
    println!("{:?}", output);
}