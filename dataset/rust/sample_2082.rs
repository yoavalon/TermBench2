extern crate ndarray;
extern crate rand;

use ndarray::{Array, Array2, arr1, arr2};
use rand::Rng;

struct Layer {
    weights: Array2<f64>,
    bias: Array2<f64>,
}

impl Layer {
    fn new(input_size: usize, output_size: usize) -> Layer {
        let mut rng = rand::thread_rng();
        let weights = Array2::from_shape_fn((input_size, output_size), |_| rng.gen::<f64>());
        let bias = Array2::from_shape_fn((1, output_size), |_| rng.gen::<f64>());
        Layer { weights, bias }
    }

    fn forward(&self, x: &Array2<f64>) -> Array2<f64> {
        x.dot(&self.weights) + &self.bias
    }
}

fn relu(x: &Array2<f64>) -> Array2<f64> {
    x.mapv(|v| f64::max(0.0, v))
}

fn softmax(x: &Array2<f64>) -> Array2<f64> {
    let max_values = x.max_axis(Axis(1)).unwrap().into_shape((x.nrows(), 1)).unwrap();
    let e_x = (x - &max_values).mapv(|v| v.exp());
    e_x / e_x.sum_axis(Axis(1)).view().into_shape((x.nrows(), 1)).unwrap()
}

fn neural_network_forward_pass(input_data: &Array2<f64>, layers: &[Layer]) -> Array2<f64> {
    let mut a = input_data.clone();
    for layer in layers {
        a = layer.forward(&a);
        a = relu(&a);
    }
    softmax(&a)
}

fn generate_data(batch_size: usize, input_size: usize) -> Array2<f64> {
    let mut rng = rand::thread_rng();
    Array2::from_shape_fn((batch_size, input_size), |_| rng.gen::<f64>())
}

fn main() {
    let input_size = 784;
    let hidden_size = 256;
    let output_size = 10;
    let batch_size = 64;
    let layers = vec![Layer::new(input_size, hidden_size), Layer::new(hidden_size, output_size)];
    let input_data = generate_data(batch_size, input_size);
    let output = neural_network_forward_pass(&input_data, &layers);
    println!("{:?}", output);
}