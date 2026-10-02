extern crate rand;
extern crate ndarray;
extern crate ndarray_rand;
extern crate rand_distr;

use ndarray::{Array, Array2, arr1, arr2};
use ndarray_rand::RandomExt;
use rand_distr::StandardNormal;

fn initialize_weights(input_size: usize, hidden_size: usize, output_size: usize) -> (Array2<f64>, Array2<f64>) {
    let w1 = Array2::<f64>::random((input_size, hidden_size), StandardNormal) * (2.0 / input_size as f64).sqrt();
    let w2 = Array2::<f64>::random((hidden_size, output_size), StandardNormal) * (2.0 / hidden_size as f64).sqrt();
    (w1, w2)
}

fn forward_pass(x: &Array2<f64>, w1: &Array2<f64>, w2: &Array2<f64>) -> Array2<f64> {
    let z1 = x.dot(w1);
    let a1 = z1.mapv(|v| v.max(0.0));
    let z2 = a1.dot(w2);
    z2
}

fn compute_loss(y_pred: &Array2<f64>, y_true: &Array2<f64>) -> f64 {
    let diff = y_pred - y_true;
    diff.mapv(|v| v.powi(2)).mean().unwrap()
}

fn train(x: Array2<f64>, y: Array2<f64>, epochs: usize, input_size: usize, hidden_size: usize, output_size: usize) -> (Array2<f64>, Array2<f64>) {
    let (mut w1, mut w2) = initialize_weights(input_size, hidden_size, output_size);
    let learning_rate = 0.01;
    for epoch in 0..epochs {
        let y_pred = forward_pass(&x, &w1, &w2);
        let loss = compute_loss(&y_pred, &y);
        if epoch % 1000 == 0 {
            println!("{}", loss);
        }
        let grad_z2 = 2.0 * (y_pred - y) / y.shape()[0] as f64;
        let grad_w2 = a1.t().dot(&grad_z2);
        let grad_z1 = grad_z2.dot(&w2.t()) * a1.mapv(|v| if v > 0.0 { 1.0 } else { 0.0 });
        let grad_w1 = x.t().dot(&grad_z1);
        w2 -= learning_rate * &grad_w2;
        w1 -= learning_rate * &grad_w1;
    }
    (w1, w2)
}

fn main() {
    let input_size = 10;
    let hidden_size = 20;
    let output_size = 1;
    let epochs = 5000;
    let x = Array2::<f64>::random((100, input_size), StandardNormal);
    let y = Array2::<f64>::random((100, output_size), StandardNormal);
    train(x, y, epochs, input_size, hidden_size, output_size);
}